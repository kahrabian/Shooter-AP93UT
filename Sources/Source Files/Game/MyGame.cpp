//
// Created by kahrabian on 7/12/15.
//

#include <Sources/Headers/Resources.h>
#include "../../Headers/Game/MyGame.h"

MyGame::MyGame(QWidget * parent) :
		QGraphicsView(parent)
{
	gscn = new QGraphicsScene();
	gscn->setSceneRect(0, 0, 1000, 500);
	tmp = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]));
	gscn->addItem(tmp);
	setScene(gscn);
	setSceneRect(0, 0, 1120, 620);
//	tmp->setPos(0, 0);
//	repaint();
}

MyGame::MyGame(QGraphicsScene * scene, QWidget * parent) :
		QGraphicsView(scene, parent)
{

}

MyGame::~MyGame() { }

void MyGame::keyPressEvent(QKeyEvent *e)
{
	if(e->key() == Qt::Key_Up)
	{
		tmp->setPos(tmp->x(), tmp->y() - 2);
	}
	if(e->key() == Qt::Key_Down)
	{
		tmp->setPos(tmp->x(), tmp->y() + 2);
	}
	if(e->key() == Qt::Key_Left)
	{
		tmp->setPos(tmp->x() - 2, tmp->y());
	}
	if(e->key() == Qt::Key_Right)
	{
		tmp->setPos(tmp->x() + 2, tmp->y());
	}
	QGraphicsView::keyPressEvent(e);
}
