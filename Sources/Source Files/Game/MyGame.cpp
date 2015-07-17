//
// Created by kahrabian on 7/12/15.
//

#include <Sources/Headers/Resources.h>
#include "../../Headers/Game/MyGame.h"

MyGame::MyGame(QWidget * parent) :
		QGraphicsView(parent)
{
	gscn = new QGraphicsScene();
	gscn->setSceneRect(0, 0, 1120 + 6000, 630);
	gscn->setBackgroundBrush(QBrush(QImage(MyRes::env_adds[SettingData::env]).scaled(50, 50)));
	tmp = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]));
	gscn->addItem(tmp);
	setScene(gscn);
//	setSceneRect(0, 0, 1120, 620);
	setSceneRect(this->parentWidget()->frameGeometry());
//	setSceneRect(0, 0, this->parentWidget()->frameGeometry().width(), this->parentWidget()->frameGeometry().height());
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//	tmp->setPos(0, 0);
//	repaint();
	timer_id = startTimer(20);
}

MyGame::MyGame(QGraphicsScene * scene, QWidget * parent) :
		QGraphicsView(scene, parent)
{

}

MyGame::~MyGame() { }

void MyGame::unpause()
{
	timer_id = startTimer(20);
}

void MyGame::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_Up)
	{
		tmp->setPos(tmp->x(), tmp->y() - 10);
	}
	if(event->key() == Qt::Key_Down)
	{
		tmp->setPos(tmp->x(), tmp->y() + 10);
	}
	if(event->key() == Qt::Key_Left)
	{
		tmp->setPos(tmp->x() - 10, tmp->y());
	}
	if(event->key() == Qt::Key_Right)
	{
		tmp->setPos(tmp->x() + 10, tmp->y());
	}
	if(event->key() == Qt::Key_Escape)
	{
		killTimer(timer_id);
		emit gamePaused();
	}
	QGraphicsView::keyPressEvent(event);
}

void MyGame::timerEvent(QTimerEvent *event)
{
	setSceneRect(sceneRect().x() + 1, 0, this->parentWidget()->frameGeometry().width(), this->parentWidget()->frameGeometry().height());
}