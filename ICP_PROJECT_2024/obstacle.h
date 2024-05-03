/**
 * @file obstacle.h
 * @brief Declaration of Obstacle class
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 29.4.2024
 */

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsItem>
#include <cstddef>
#include "SessionManager.h"
#include "mapobject.h"

class Obstacle: public MapObject
{
public:
    /*!
     * \brief Obstacle constructor for boundaries
     * \param x X coordinate
     * \param y Y coordinate
     * \param width Width of the boundary
     * \param height Height of the boundary
     * \param scene Current scene
     */
    Obstacle(size_t x, size_t y, size_t width, size_t height, int orientation, QGraphicsScene* scene);

    /*!
     * \brief Constructor for obstacles. Called by ObjectFactory::createMapObject(SessionManager::obstacle*, SessionManager::robot*, QGraphicsScene*)
     * \param obstStruct Structure with all the information about obstacles
     * \param scene Current scene to draw to
     */
    Obstacle(SessionManager::obstacle obstStruct, QGraphicsScene* scene);

    /*!
     *  \brief Deletes Obstacle instance
     */
    ~Obstacle();

    /*!
     * \brief Method to get QGraphicsItem
     * \return Objects shape
     */
    QGraphicsItem* getGraphic();

    /*!
     * \brief Redraws the obstacle every tick
     * \param scene Current scene to draw to
     */
    void draw(QGraphicsScene* scene);

private:
    size_t height;

    QGraphicsRectItem* obstacleGraphic;
};

#endif // OBSTACLE_H
