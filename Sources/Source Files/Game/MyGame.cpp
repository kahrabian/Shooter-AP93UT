//
// Created by kahrabian on 7/12/15.
//

#include "../../Headers/Game/MyGame.h"

MyGame::MyGame(QWidget * parent) :
		QGraphicsView(parent)
{

}

MyGame::MyGame(QGraphicsScene * scene, QWidget * parent) :
		QGraphicsView(scene, parent)
{

}

MyGame::~MyGame() { }