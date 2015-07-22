//
// Created by kahrabian on 7/20/15.
//

#ifndef SHOOTER_AP93UT_MYSHIPSHIELD_H
#define SHOOTER_AP93UT_MYSHIPSHIELD_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Game Objects/MyAsteroid.h>
#include <Sources/Headers/Game Objects/MyBullet.h>
//#include <Sources/Headers/Game Objects/MyShip.h>
#include <Sources/Headers/Resources.h>

class MyShip;

class MyShipShield : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:
	MyShipShield(MyShip *);

	~MyShipShield();

	void updt();

signals:

	void shieldDestroyd();

private:
	MyShip *mstr;

	QPointF *vlc;

	void cllsn_dtctn();
};

#endif //SHOOTER_AP93UT_MYSHIPSHIELD_H
