/**
 * @file SessionInterface.h
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
//#include <qDebug>
#include <QJsonArray>

class SessionManager
{
public:
    static SessionManager * getManagerHandle();
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

    int saveSession(QString filePath, bool overwrite);
    sessionData getSessionData();
    bool loadSessionData(QString filePath);

    bool addRobot(int type, int width, int orientation, int x, int y, int detection,  int r_angle,  int r_direction);
    bool addObstacle(int width, int orientation, int x, int y);


private:
    static SessionManager *instance;
    explicit SessionManager() {};

    sessionData data;
};

#endif // SESSIONMANAGER_H
