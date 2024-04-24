#include "json_interface.h"

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
bool Json_interface::add_robot(const QString &name, int type, int width, int orientation, int x, int y, int fov,  int r_angle,  int r_direction) {

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

    return this->add_object(name, robot_obj);
}


/*!
 * \brief add_obstacle insert new obstacle into the json file
 * \param name
 * \param width of the obstacle
 * \param orientation how rotated the obstacle is in degrees
 * \param x position on the map
 * \param y position on the map
 */
bool Json_interface::add_obstacle(const QString &name, int width, int orientation, int x, int y) {

    QJsonObject obstacle_obj {
        {"Width", width},
        {"Orientation", orientation},
        {"X", x},
        {"Y", y}
    };

    return this->add_object(name, obstacle_obj);
}


/*!
 * \brief add_object add given object to json file
 * \param name
 * \param obj
 */
bool Json_interface::add_object(const QString &name, const QJsonObject &obj) {
    QFile file(m_filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);

    if (jsonDoc.isNull()) {
        return false;
    }

    QJsonObject jsonObj = jsonDoc.object();
    if (jsonObj.contains(name)) {
        return false;
    }

    jsonObj.insert(name, obj);

    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    file.write(QJsonDocument(jsonObj).toJson());
    file.close();

    return true;
}
