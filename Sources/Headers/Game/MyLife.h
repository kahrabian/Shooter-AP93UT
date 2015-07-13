//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYLIFE_H
#define SHOOTER_AP93UT_MYLIFE_H

#include <QGraphicsPixmapItem>

class MyLife : public QGraphicsPixmapItem
{
//    Q_OBJECT
public:
	MyLife(QGraphicsItem * parent = 0);
	MyLife(const QPixmap & pixmap, QGraphicsItem * parent = 0);
	~MyLife();

private:
};

#endif //SHOOTER_AP93UT_MYLIFE_H
