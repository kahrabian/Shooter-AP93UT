//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYASTEROID_H
#define SHOOTER_AP93UT_MYASTEROID_H

#include <QGraphicsPixmapItem>

class MyAsteroid : public QGraphicsPixmapItem
{
//    Q_OBJECT
public:
	MyAsteroid(QGraphicsItem * parent = 0);
	MyAsteroid(const QPixmap & pixmap, QGraphicsItem * parent = 0);
	~MyAsteroid();

private:
};

#endif //SHOOTER_AP93UT_MYASTEROID_H
