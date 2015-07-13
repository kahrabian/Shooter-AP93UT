//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYALIEN_H
#define SHOOTER_AP93UT_MYALIEN_H

#include <QGraphicsPixmapItem>

class MyAlien : public QGraphicsPixmapItem
{
//    Q_OBJECT
public:
	MyAlien(QGraphicsItem * parent = 0);
	MyAlien(const QPixmap & pixmap, QGraphicsItem * parent = 0);
	~MyAlien();

private:
};

#endif //SHOOTER_AP93UT_MYALIEN_H
