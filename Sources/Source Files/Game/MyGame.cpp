//
// Created by kahrabian on 7/12/15.
//

#include "../../Headers/Game/MyGame.h"

MyGame::MyGame(QObject *parent) :
        QGraphicsScene(parent)
{

}

MyGame::MyGame(const QRectF &sceneRect, QObject *parent) :
        QGraphicsScene(sceneRect, parent)
{

}

MyGame::MyGame(qreal x, qreal y, qreal width, qreal height, QObject *parent) :
        QGraphicsScene(x, y, width, height, parent)
{

}

MyGame::~MyGame() { }