#ifndef JSON_INTERFACE_H
#define JSON_INTERFACE_H

#include <QObject>
#include <QFile>
#include <QJsonObject>
#include <QIODevice>
#include <QJsonParseError>
#include <QJsonDocument>

class Json_interface
{
public:
    explicit Json_interface(const QString &file_path) : m_filePath(file_path) {};

    bool add_robot(const QString &name, int type, int width, int orientation, int x, int y, int fov,  int r_angle,  int r_direction);
    bool add_obstacle(const QString &name, int width, int orientation, int x, int y);
    //QJsonObject objects_next()

private:
    QJsonObject m_data;
    QString m_filePath;
    bool add_object(const QString &name, const QJsonObject &obj);
};

#endif // JSON_INTERFACE_H
