//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYBULLET_H
#define SHOOTER_AP93UT_MYBULLET_H

#include <QGraphicsPixmapItem>

class MyBullet : public QGraphicsPixmapItem
{
//    Q_OBJECT
public:
	MyBullet(QGraphicsItem * parent = 0);
	MyBullet(const QPixmap & pixmap, QGraphicsItem * parent = 0);
	~MyBullet();

private:
};

#endif //SHOOTER_AP93UT_MYBULLET_H
