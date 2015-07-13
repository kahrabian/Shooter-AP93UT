//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYSTAR_H
#define SHOOTER_AP93UT_MYSTAR_H

#include <QGraphicsPixmapItem>

class MyStar : public QGraphicsPixmapItem
{
//    Q_OBJECT
public:
	MyStar(QGraphicsItem * parent = 0);
	MyStar(const QPixmap & pixmap, QGraphicsItem * parent = 0);
	~MyStar();

private:
};

#endif //SHOOTER_AP93UT_MYSTAR_H
