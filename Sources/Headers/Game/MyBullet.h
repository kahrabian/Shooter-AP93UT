//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYBULLET_H
#define SHOOTER_AP93UT_MYBULLET_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Resources.h>

class MyBullet : public QGraphicsPixmapItem {
public:
	MyBullet(int, int, QGraphicsItem *parent = 0);

	~MyBullet();

	void updt();

private:
	int rtn;

	QPointF *vlc;
};

#endif //SHOOTER_AP93UT_MYBULLET_H
