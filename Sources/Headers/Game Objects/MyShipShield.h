//
// Created by kahrabian on 7/20/15.
//

#ifndef SHOOTER_AP93UT_MYSHIPSHIELD_H
#define SHOOTER_AP93UT_MYSHIPSHIELD_H

#include <QGraphicsDropShadowEffect>
#include <QSoundEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Game Objects/MyExplosion.h>
#include <Sources/Headers/Game Objects/MyAsteroid.h>
#include <Sources/Headers/Game Objects/MyBullet.h>
#include <Sources/Headers/Game Objects/MyAlienBoss.h>
#include <Sources/Headers/Resources.h>

class MyShip;

class MyShipShield : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
	MyShipShield();

	~MyShipShield();

	void dstry();

	void updt();

signals:

	void shieldDestroyd();

private:
	QPointF *vlc;

	void cllsn_dtctn();

	void ply_sf(QString &);
};

#endif //SHOOTER_AP93UT_MYSHIPSHIELD_H
