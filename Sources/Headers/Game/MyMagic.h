//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYMAGIC_H
#define SHOOTER_AP93UT_MYMAGIC_H

#include <QGraphicsPixmapItem>

class MyMagic : public QGraphicsPixmapItem
{
//    Q_OBJECT
public:
	MyMagic(QGraphicsItem * parent = 0);
	MyMagic(const QPixmap & pixmap, QGraphicsItem * parent = 0);
	~MyMagic();

private:
};

#endif //SHOOTER_AP93UT_MYMAGIC_H
