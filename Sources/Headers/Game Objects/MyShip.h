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
#include <QSoundEffect>
#include <Sources/Headers/Game Objects/MyBullet.h>
#include <Sources/Headers/Game Objects/MyStar.h>
#include <Sources/Headers/Game Objects/MyShield.h>
#include <Sources/Headers/Game Objects/MyMagic.h>
#include <Sources/Headers/Game Objects/MyLife.h>
#include <Sources/Headers/Game Objects/MyShipShield.h>
#include <Sources/Headers/Game Objects/MyAsteroid.h>
#include <Sources/Headers/Game Objects/MyAlienBoss.h>
#include <Sources/Headers/Resources.h>

class MyShip : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

	friend class MyGame;

	friend class MyAi;

public:
	MyShip(const QPixmap &, QString *);

	~MyShip();

	void game_paused();

	void game_unpaused();

	void change_speed();

	void updt(QSet<int> * = 0);

private:
	MyShipShield *shpshld;

	QGraphicsTextItem *scr_txt;
	QGraphicsTextItem *lf_txt;

	bool fast;
	int rtn;
	QString *name;

	int lf;
	int scr;
	int shld_tmr_elpsd;
	QTimer *shld_tmr;
	bool mgc;
	int mgc_tmr_elpsd;
	QTimer *mgc_tmr;
	bool lsr;
	int lsr_tmr_elpsd;
	QTimer *lsr_tmr;

	int lf_tmr_elpsd;
	QTimer *lf_tmr;

	QPointF *vlc;

	void cnstrct_shldpxmp();

	void cllsn_dtctn();

	void ply_sf(QString &);

	void updt_txt();

	void updt_vlc(QSet<int> *);

	void updt_rtn();

	void updt_pos();

private slots:
	void activate_shld();

	void deactivate_shld();

	void activate_mgc();

	void deactivate_mgc();

	void activate_lsr();

	void deactivate_lsr();

	void activate_lf();

	void deactivate_lf();

	void scrIncrement();
};

#endif //SHOOTER_AP93UT_MYSHIP_H
