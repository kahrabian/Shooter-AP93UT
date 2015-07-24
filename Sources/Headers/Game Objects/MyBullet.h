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
#include <Sources/Headers/Game Objects/MyAlien.h>
#include <Sources/Headers/Game Objects/MyAsteroid.h>
#include <Sources/Headers/Game Objects/MyExplosion.h>
#include <Sources/Headers/Resources.h>

class MyShip;

class MyBullet : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
	MyBullet(int, int = 0, int = 1);

	~MyBullet();

	void updt();

signals:

	void scrGained();

private:
	int rtn;

	QPointF *vlc;

	void cllsn_dtctn();
};

#endif //SHOOTER_AP93UT_MYBULLET_H
