/**
 * @file SessionManager.h
 * @brief Definition of the singleton class SessionManager.
 * @author Ondřej Beneš
 * @date 24.4.2024
 */

#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include <QObject>
#include <QFile>
#include <QJsonObject>
#include <QIODevice>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QDir>
#include <QString>
#include <QJsonArray>

class SessionManager
{
public:
    /*!
     * \brief Retrieves the singleton instance of the SessionManager.
     *
     * Returns the existing instance of the SessionManager or creates
     * a new one if it does not exist.
     *
     * \return Pointer to the singleton instance of SessionManager.
     */
    static SessionManager * getManagerHandle();

    /*!
     * \brief Deletes the singleton instance of SessionManager if it exists.
     */
    static void deleteManagerHandle();

    // structures
    typedef struct robot {
        int Type;
        int Width;
        int Orientation;
        int X;
        int Y;
        int Detection;
        int RotationAngle;
        int RotationDirection;
    } robotData;

    typedef struct obstacle {
        int Width;
        int Orientation;
        int X;
        int Y;
    } obstacleData;

    typedef struct sessionData {
        std::vector<robotData> robots;
        std::vector<obstacleData> obstacles;
    } sessionData;

    /*!
     * \brief Saves session data into a json file.
     *
     * \param filePath Path to the file, where data should be saved.
     * \param overwrite If true, an exising file will be overwritten.
     * \return 0 on success, 1 if the file already exists and should not be overwritten, -1 on error.
     */
    int saveSession(QString filePath, bool overwrite);

    /*!
     * \brief Fetches session data from the SessionManager.
     *
     * \return sessionData structure.
     */
    sessionData getSessionData();

    /*!
     * \brief Loads json data into a sessionData structure.
     *
     * \param filePath Path to the source file.
     * \return True on success, false on failure.
     */
    bool loadSessionData(QString filePath);

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
    bool addRobot(int type, int width, int orientation, int x, int y, int detection,  int r_angle,  int r_direction);

    /*!
     * \brief Inserts new obstacle structure into a session structure.
     *
     * \param width Width of the obstacle.
     * \param orientation How rotated the obstacle is in degrees, 0 is top.
     * \param x Horizontal position on the map.
     * \param y Vertical position on the map.
     */
    bool addObstacle(int width, int orientation, int x, int y);


private:
    static SessionManager *instance;
    explicit SessionManager() {};

    sessionData data;
};

#endif // SESSIONMANAGER_H
