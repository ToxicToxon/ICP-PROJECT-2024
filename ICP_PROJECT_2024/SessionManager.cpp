/**
 * @file SessionManager.cpp
 * @brief Implementation of the singleton class SessionManager.
 * @author Ondřej Beneš
 * @date 24.4.2024
 */

#include "SessionManager.h"

SessionManager* SessionManager::instance = nullptr;


/*!
 * \brief Retrieves the singleton instance of the SessionManager.
 *
 * Returns the existing instance of the SessionManager or creates
 * a new one if it does not exist.
 *
 * \return Pointer to the singleton instance of SessionManager.
 */
SessionManager * SessionManager::getManagerHandle() {
    if (instance == nullptr) {
        instance = new SessionManager();
    }

    return instance;
}


/*!
 * \brief Deletes the singleton instance of SessionManager if it exists.
 */
void SessionManager::deleteManagerHandle() {
    if (instance != nullptr) {
        delete instance;
    }
}


/*!
 * \brief Inserts new robot structure into a session structure.
 *
 * \param type Type of robot, autonomous when 0, controllable when 1.
 * \param width Width of the robot.
 * \param orientation Starting angle of the robot.
 * \param x Horizontal position on the map.
 * \param y Vertical position on the map.
 * \param detection Distance at which obstacles are detected.
 * \param rAngle How much the robot rotates after detecting an obstacle.
 * \param rDirection Which way the robot rotates after detecting an obstacle (0 - clockwise, 1 - counterclockwise).
 */
bool SessionManager::addRobot(int type, int width, int orientation, int x, int y, int detection,  int rAngle,  int rDirection) {

    robotData robotObj;
    robotObj.Type = type;
    robotObj.Width = width;
    robotObj.Orientation = orientation;
    robotObj.X = x;
    robotObj.Y = y;
    robotObj.Detection = detection;
    robotObj.RotationAngle = rAngle;
    robotObj.RotationDirection = rDirection;

    this->data.robots.push_back(robotObj);

    return true;
}


/*!
 * \brief Inserts new obstacle structure into a session structure.
 *
 * \param width Width of the obstacle.
 * \param orientation How rotated the obstacle is in degrees, 0 is top.
 * \param x Horizontal position on the map.
 * \param y Vertical position on the map.
 */
bool SessionManager::addObstacle(int width, int orientation, int x, int y) {

    obstacleData obstacleObj;
    obstacleObj.Width = width;
    obstacleObj.Orientation = orientation;
    obstacleObj.X = x;
    obstacleObj.Y = y;

    this->data.obstacles.push_back(obstacleObj);

    return true;
}


/*!
 * \brief Fetches session data from the SessionManager.
 *
 * \return sessionData structure.
 */
SessionManager::sessionData SessionManager::getSessionData() {
    return this->data;
}


/*!
 * \brief Saves session data into a json file.
 *
 * \param filePath Path to the file, where data should be saved.
 * \param overwrite If true, an exising file will be overwritten.
 * \return 0 on success, 1 if the file already exists and should not be overwritten, -1 on error.
 */
int SessionManager::saveSession(QString filePath, bool overwrite) {
    QFile file(filePath);
    if (file.exists()) {
        if (!overwrite) {
            return 1;
        }
    }
    QJsonObject jsonObj;

    QJsonArray robotsArray;
    for (const auto& robot : data.robots) {
        QJsonObject robotObj;
        robotObj["Type"] = robot.Type;
        robotObj["Width"] = robot.Width;
        robotObj["Orientation"] = robot.Orientation;
        robotObj["X"] = robot.X;
        robotObj["Y"] = robot.Y;
        robotObj["Detection"] = robot.Detection;
        robotObj["RotationAngle"] = robot.RotationAngle;
        robotObj["RotationDirection"] = robot.RotationDirection;
        robotsArray.append(robotObj);
    }

    QJsonArray obstaclesArray;
    for (const auto& obstacle : data.obstacles) {
        QJsonObject obstacleObj;
        obstacleObj["Width"] = obstacle.Width;
        obstacleObj["Orientation"] = obstacle.Orientation;
        obstacleObj["X"] = obstacle.X;
        obstacleObj["Y"] = obstacle.Y;
        obstaclesArray.append(obstacleObj);
    }

    // Update simulationSettings with the modified arrays
    QJsonObject simulationSettings;
    simulationSettings["Robots"] = robotsArray;
    simulationSettings["Obstacles"] = obstaclesArray;

    if (!file.open(QIODevice::WriteOnly | QFile::Truncate)) {
        qDebug() << "Error: Failed to open file for writing" << filePath;
        return -1;
    }

    file.write(QJsonDocument(simulationSettings).toJson());
    file.close();

    return 0;
}


/*!
 * \brief Loads json data into a sessionData structure.
 *
 * \param filePath Path to the source file.
 * \return True on success, false on failure.
 */
bool SessionManager::loadSessionData(QString filePath) {
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Error: Failed to open file for reading" << filePath;
        return false;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);

    if (jsonDoc.isNull() || jsonDoc.isEmpty()) {
        qDebug() << "Error: Failed to parse JSON data";
        return false;
    }

    QJsonObject simulationSettings = jsonDoc.object();

    QJsonArray robotsArray = simulationSettings["Robots"].toArray();
    QJsonArray obstaclesArray = simulationSettings["Obstacles"].toArray();

    for (const auto& robotValue : robotsArray) {
        QJsonObject robotObj = robotValue.toObject();
        robotData robot;
        robot.Type = robotObj["Type"].toInt();
        robot.Width = robotObj["Width"].toInt();
        robot.Orientation = robotObj["Orientation"].toInt();
        robot.X = robotObj["X"].toInt();
        robot.Y = robotObj["Y"].toInt();
        robot.Detection = robotObj["Detection"].toInt();
        robot.RotationAngle = robotObj["RotationAngle"].toInt();
        robot.RotationDirection = robotObj["RotationDirection"].toInt();
        this->data.robots.push_back(robot);
    }

    for (const auto& obstacleValue : obstaclesArray) {
        QJsonObject obstacleObj = obstacleValue.toObject();
        obstacleData obstacle;
        obstacle.Width = obstacleObj["Width"].toInt();
        obstacle.Orientation = obstacleObj["Orientation"].toInt();
        obstacle.X = obstacleObj["X"].toInt();
        obstacle.Y = obstacleObj["Y"].toInt();
        this->data.obstacles.push_back(obstacle);
    }

    return true;
}
