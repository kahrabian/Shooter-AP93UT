//
// Created by kahrabian on 7/12/15.
//

#ifndef SHOOTER_AP93UT_MYSHIP_H
#define SHOOTER_AP93UT_MYSHIP_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QElapsedTimer>
#include <QTimer>
#include <QPointF>
#include <QString>
#include <QPixmap>
#include <QSet>
#include <QTextStream>
#include <QTransform>
#include <Sources/Headers/Game Objects/MyBullet.h>
#include <Sources/Headers/Game Objects/MyStar.h>
#include <Sources/Headers/Game Objects/MyShield.h>
#include <Sources/Headers/Game Objects/MyMagic.h>
#include <Sources/Headers/Game Objects/MyLife.h>
#include <Sources/Headers/Game Objects/MyShipShield.h>
#include <Sources/Headers/Game Objects/MyAsteroid.h>
#include <Sources/Headers/Resources.h>

class MyShip : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

	friend class MyGame;

public:
	MyShip(const QPixmap &pixmap);

	~MyShip();

	void updt(QSet<int> * = 0);

private:
	MyShipShield *shpshld;

	int rtn = 0;
	QString *name;

	int lf = 0;
	int scr = 0;
	QTimer *shld_tmr;
	bool mgc = false;
	QTimer *mgc_tmr;
	QElapsedTimer *lsr_tmr;

	int mss;
	QPointF *vlc;
	QPointF *acc;
	QPointF *frc;

	void cnstrct_shldpxmp();

	void cllsn_dtctn();

	void updt_vlc(QSet<int> *);

	void updt_rtn();

	void updt_pos();

private slots:
	void activate_shld();

	void deactivate_shld();

	void activate_mgc();

	void deactivate_mgc();

	void scrIncrement();
};

#endif //SHOOTER_AP93UT_MYSHIP_H
