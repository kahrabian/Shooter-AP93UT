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
#include <Sources/Headers/Game/MyStar.h>
#include <Sources/Headers/Game/MyShield.h>
#include <Sources/Headers/Game/MyMagic.h>
#include <Sources/Headers/Game/MyLife.h>
#include <Sources/Headers/Resources.h>
#include <Sources/Headers/Game/MyShipShield.h>
//#include "MyShipShield.h"

class MyShip : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

	friend class MyGame;

public:
	MyShip(QGraphicsItem *parent = 0);

	MyShip(const QPixmap &pixmap, QGraphicsItem *parent = 0);

	~MyShip();

	int getLf() const;

	void setLf(int lf);

	int getScr() const;

	void setScr(int scr);

	bool isShld() const;

	void setShld(bool shld);

	bool isMgc() const;

	void setMgc(bool mgc);

	void setVlc(QPointF *);

	QPointF *getVlc() const;

	void updt(QSet<int> * = 0);

private:
	MyShipShield *shpshld;

	int rtn = 0;
	QString *name;
	QRectF *init_rct;

	int lf = 0;
	int scr = 0;
	bool shld = false;
	QTimer *shld_tmr;
	bool mgc = false;
	QTimer *mgc_tmr;

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
};

#endif //SHOOTER_AP93UT_MYSHIP_H
