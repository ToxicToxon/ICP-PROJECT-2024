/**
 * @file robot.h
 * @brief Declaration of Robot class
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 29.4.2024
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "obstacle.h"
#include "SessionManager.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <vector>
#include <QGraphicsScene>
#include <QDebug>

class Robot : public MapObject
{
public:
    /*!
     * \brief Creates the robot and his graphical representation
     * \param speed Speed of the robot
     * \param robot Struction with most of the values for the robot initialization
     * \param scene Current scene to draw to
     */
    Robot(int speed, SessionManager::robot robot, QGraphicsScene* scene);

    /*!
     *  Deletes an instance of Robot
     */
    ~Robot();

    /*!
     * \brief Redraws the robot every tick and checks for collisions
     * \param scene Current scene to redraw to
     * \param obstacleBuffer Buffer with obstacle instances
     * \param robotBuffer Buffer with robot instances
     */
    void draw(QGraphicsScene* scene, std::vector<Obstacle*> obstacleBuffer, std::vector<Robot*> robotBuffer);

    /*!
     * \brief Adds values to x and y coordinates to move the robot
     */
    void move();

    /*!
     * \brief Starts the turning process
     * \param turn Which way to turn. False means left, true means right
     */
    void turn(bool turn);

    /*!
     * \brief Decides robots behaviour to collisions based on robot type
     */
    void collision();

    /*!
     * \brief Getter function for robot type
     * \return 1 means controlled by an operator, 0 means self-controlled
     */
    int getType();

    /*!
     * \brief Gets the shape of the robot
     * \return The shape of the robot
     */
    QGraphicsItem* getGraphic() override;

    /*!
     * \brief Sets the speed to certain value
     */
    void go();

    /*!
     * \brief Sets the robot speed to 0
     */
    void stop();

private:
    int type;

    int speed;

    int detection;

    bool stuck;

    bool detected;

    double expectedAngle;

    double rotationAngle;

    bool rotationDirection; //false = left, true = right

    QGraphicsItemGroup* robotGraphic;

    /*!
     * \brief Mehod to construct the detection rectangle, color it and check its collisions
     * \param obstacleBuffer Buffer with all obstacle instances
     * \param robotBuffer Buffer with all robot instances
     * \param scene Current scene to draw to
     * \param ellipse Needed to not detect collision with it
     * \return Created rectangle
     */
    QGraphicsItem* getDetection(std::vector<Obstacle*> obstacleBuffer, std::vector<Robot*> robotBuffer, QGraphicsScene* scene, QGraphicsItem* ellipse);

    /*!
     * \brief Draws the robot body and checks for collisions with other bodies
     * \param robotBuffer Buffer with all robot instances
     * \return Created robot body
     */
    QGraphicsEllipseItem* getBody(std::vector<Robot*> robotBuffer);

};

#endif // ROBOT_H
