//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYSHIELD_H
#define SHOOTER_AP93UT_MYSHIELD_H

#include <QGraphicsPixmapItem>

class MyShield : public QGraphicsPixmapItem
{
//    Q_OBJECT
public:
	MyShield(QGraphicsItem * parent = 0);
	MyShield(const QPixmap & pixmap, QGraphicsItem * parent = 0);
	~MyShield();

private:
};

#endif //SHOOTER_AP93UT_MYSHIELD_H
