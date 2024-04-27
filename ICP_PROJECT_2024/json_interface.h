/**
 * @file json_interface.h
 * @brief Definition of the singleton class json_interface.
 * @author Ondřej Beneš
 * @date 24.4.2024
 */

#ifndef JSON_INTERFACE_H
#define JSON_INTERFACE_H

#include <QObject>
#include <QFile>
#include <QJsonObject>
#include <QIODevice>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QCoreApplication>
#include <QDir>
#include <QString>

class JsonInterface
{
public:
    static JsonInterface * getJsonHandle();
    static void deleteJsonHandler();
    bool setPath(QString filePath, bool fileExists);

    bool add_robot(const QString &name, int type, int width, int orientation, int x, int y, int fov,  int r_angle,  int r_direction);
    bool add_obstacle(const QString &name, int width, int orientation, int x, int y);

    bool getJsonObjects(QJsonObject *objectsPtr);

private:
    static JsonInterface *instance;
    explicit JsonInterface() {};

    int robotCounter = 0;
    int obstacleCounter = 0;

    QJsonDocument m_data;
    QString m_filePath;
    bool m_pathSet = false;
    bool add_object(const QString &name, const QJsonObject &obj);
};

#endif // JSON_INTERFACE_H
