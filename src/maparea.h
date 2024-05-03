/**
 * @file maparea.h
 * @brief Declaration of MapArea class
 * @author David Zatloukal
 * @date 29.4.2024
 */

#ifndef MAPAREA_H
#define MAPAREA_H

#include <cstddef>
#include <vector>
#include "robot.h"
#include "obstacle.h"
#include <QGraphicsScene>
#include "SessionManager.h"
#include "objectfactory.h"

class MapArea
{
public:
    /*!
     * \brief Function to create the map area with given size and instantiate factory
     * \param width Width of the map
     * \param height Height of the map
     */
    MapArea(size_t width, size_t height);

    /*!
     * \brief Deletes the map
     */
    ~MapArea();

    /*!
     * \brief Method that calls methods of robot and obstacle to draw the object to the screen.
     * \param Scene Current scene to draw into
     * For more details on drawing objects see Robot::draw(QGraphicsScene*, vector<Obstacle*>, vector(<Robot*>))
     * and Obstacle::draw(QGraphicsScene*)
     */
    void drawMap(QGraphicsScene* scene);

    /*!
     * \brief Creates map borders
     * \param scene Current scene
     * \param x Map width
     * \param y Map height
     */
    void setBorders(QGraphicsScene* scene, size_t x, size_t y);

    /*!
     * \brief Adds a new instance of robot created by factory to robot buffer
     * \param scene Current scene
     * \param settings Structure with all robot parameters
     * \see SessionManager
     */
    void addRobot(QGraphicsScene* scene, SessionManager::robotData settings);

    /*!
     * \brief Creates a new instance of obstacle via factory and adds it to obstacleBuffer
     * \param scene Current scene
     * \param settings Structure containing all the information about an obstacle
     */
    void addObstacle(QGraphicsScene* scene, SessionManager::obstacleData settings);

    /*!
     * \brief Method to add degrees to the orientation of all robots controled by an operator
     * \param turn Turning direction false = left, true = right
     */
    void turnAllUserRobots(bool turn); //false = left, true = right

    /*!
     * \brief Sets the speed of all user controled robots to a certain value.
     */
    void goAllUserRobots();

    /*!
     * \brief Sets the speed of robots to 0. See Robot::stop()
     */
    void stopAllUserRobots();

    /*!
     * \brief Gives the caller width value of the map
     * \return Width value
     */
    size_t getWidth();

    /*!
     * \brief Gives the caller height value of the map
     * \return Height value
     */
    size_t getHeight();

    /*!
     * \brief Action of PausePlay button to stop all robots actions and then make them continue
     */
    void pausePlay();

    /*!
     * \brief Getter function for PlayPause state
     * \return Map state
     */
    bool isPaused();
    ObjectFactory* mapObjectFactory;


private:
    bool paused;

    size_t width;

    size_t height;

    std::vector<Robot*> robotBuffer;

    std::vector<Obstacle*> obstacleBuffer;
};

#endif // MAPAREA_H
