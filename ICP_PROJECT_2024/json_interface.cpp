#include "json_interface.h"

JsonInterface* JsonInterface::instance = nullptr;


/*!
 * \brief JsonInterface::getJsonHandle
 * JsonInterface
 * \return
 */
JsonInterface * JsonInterface::getJsonHandle() {
    if (instance == nullptr) {
        QString buildDirPath = QCoreApplication::applicationDirPath();
        QDir buildDir(buildDirPath);

        // Get to build folder
        if (!buildDir.cdUp() || !buildDir.cdUp() || !buildDir.cdUp()) {
            qDebug() << "Failed to navigate to the desired directory.";
            return nullptr;
        }

        // Construct the path to objects_file.json
        QString filePath = buildDir.filePath("objects_file.json");
        QFile file(filePath);
        file.remove();

        instance = new JsonInterface(filePath);
    }

    return instance;
}

void JsonInterface::deleteJsonHandler() {
    if (instance != nullptr) {
        delete instance;
    }
}


/*!
 * \brief add_robot insert new robot into the json file
 * \param name
 * \param type of robot based on controls (0 - automatic, 1 - manual)
 * \param width of the robot
 * \param orientation starting angle of the robot
 * \param x position on map
 * \param y position on map
 * \param fov distance at which obstacles are detected
 * \param r_angle how much the robot rotates after detecting an obstacle
 * \param r_direction which way the robot rotates after detecting an obstacle (0 - clockwise, 1 - counterclockwise)
 */
bool JsonInterface::add_robot(const QString &name, int type, int width, int orientation, int x, int y, int fov,  int r_angle,  int r_direction) {

    QJsonObject robot_obj {
        {"Type", type},
        {"Width", width},
        {"Orientation", orientation},
        {"X", x},
        {"Y", y},
        {"Fov", fov},
        {"Rotation_angle", r_angle},
        {"Rotation_direction", r_direction},
    };

    QString robotName = name + QString::number(robotCounter);

    if(this->add_object(robotName, robot_obj)) {
        this->robotCounter++;
        return true;
    }
    return false;
}


/*!
 * \brief add_obstacle insert new obstacle into the json file
 * \param name
 * \param width of the obstacle
 * \param orientation how rotated the obstacle is in degrees
 * \param x position on the map
 * \param y position on the map
 */
bool JsonInterface::add_obstacle(const QString &name, int width, int orientation, int x, int y) {

    QJsonObject obstacle_obj {
        {"Width", width},
        {"Orientation", orientation},
        {"X", x},
        {"Y", y}
    };

    QString obstacleName = name + QString::number(obstacleCounter);

    if(this->add_object(obstacleName, obstacle_obj)) {
        this->obstacleCounter++;
        return true;
    }
    return false;
}


/*!
 * \brief add_object add given object to json file
 * \param name
 * \param obj
 */
bool JsonInterface::add_object(const QString &name, const QJsonObject &obj) {
    QFile file(m_filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Error: Failed to open file " << m_filePath << ". File will be created.";
        //return false;
    }
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);

    if (jsonDoc.isNull()) {
        qDebug() << "Error: Failed to create json document";
        //return false;
    }

    QJsonObject jsonObj = jsonDoc.object();
    if (jsonObj.contains(name)) {
        qDebug() << "Error: Object already exists";
        return false;
    }

    jsonObj.insert(name, obj);

    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Error: Failed to open file " << m_filePath;
        return false;
    }

    file.write(QJsonDocument(jsonObj).toJson());
    file.close();

    return true;
}
