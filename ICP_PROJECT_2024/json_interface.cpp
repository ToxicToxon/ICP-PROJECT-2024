/**
 * @file json_interface.cpp
 * @brief Implementation of the singleton class json_interface.
 * @author Ondřej Beneš
 * @date 24.4.2024
 */

#include "json_interface.h"

JsonInterface* JsonInterface::instance = nullptr;


/*!
 * \brief JsonInterface::getJsonHandle
 * JsonInterface
 * \return
 */
JsonInterface * JsonInterface::getJsonHandle() {
    if (instance == nullptr) {
        instance = new JsonInterface();
    }

    return instance;
}

void JsonInterface::deleteJsonHandler() {
    if (instance != nullptr) {
        delete instance;
    }
}


bool JsonInterface::setPath(QString filePath, bool fileExists) {
    if (this->m_pathSet) {
        return false;
    }

    // Check whether the file exists and set iterators based on its contents

    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly)) {
        QByteArray jsonData = file.readAll();
        file.close();

        QJsonParseError parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
        QJsonObject jsonObj = jsonDoc.object();

        // Check robots
        int iterator = 0;
        QString id = "r" + QString::number(iterator);
        while (jsonObj.contains(id)) {
            iterator++;
            id = "r" + QString::number(iterator);
        }
        this->robotCounter = iterator;

        // Check obstacles
        iterator = 0;
        id = "o" + QString::number(iterator);
        while (jsonObj.contains(id)) {
            iterator++;
            id = "o" + QString::number(iterator);
        }
        this->obstacleCounter = iterator;
    }
    else {
        if (fileExists) {
            return false;
        }
        if (!file.open(QIODevice::WriteOnly)) {
            return false;
        }
    }

    m_filePath = filePath;
    this->m_pathSet = true;
    return true;
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

    file.open(QIODevice::ReadOnly); // Ignore fail, Write creates the file if it does not exist
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);


    QJsonObject jsonObj = jsonDoc.object();
    if (jsonObj.contains(name)) {
        qDebug() << "Error: Entry already exists";
        return false;
    }

    jsonObj.insert(name, obj);

    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Error: Failed to open file " << m_filePath;
        return false;
    }

    file.write(QJsonDocument(jsonObj).toJson());
    file.close();
    this->m_pathSet = true; // Once an object is inserted, the path cannot be changed
    return true;
}


bool JsonInterface::getJsonObjects(QJsonObject *objectsPtr) {

    QFile file(m_filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Error: Failed to open file " << m_filePath;
        return false;
    }
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
    if (jsonDoc.isNull()) {
        qDebug() << "Failed to parse JSON:" << parseError.errorString();
        return false;
    }

    *objectsPtr = jsonDoc.object();
    return true;
}