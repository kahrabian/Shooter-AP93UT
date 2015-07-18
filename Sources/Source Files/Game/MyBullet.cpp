//
// Created by kahrabian on 7/13/15.
//

#include "../../Headers/Game/MyBullet.h"

MyBullet::MyBullet(QGraphicsItem * parent) :
		QGraphicsPixmapItem(parent)
{

}

MyBullet::MyBullet(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent)
{

}

MyBullet::~MyBullet()
{

}

void MyBullet::updt(qint64 qint641)
{

}