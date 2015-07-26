//
// Created by kahrabian on 7/12/15.
//

#ifndef SHOOTER_AP93UT_MYGAME_H
#define SHOOTER_AP93UT_MYGAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QElapsedTimer>
#include <QTimer>
#include <QList>
#include <QKeyEvent>
#include <QTextStream>
#include <QSet>
#include <Sources/Headers/Game Objects/MyShip.h>
#include <Sources/Headers/Game Objects/MyBullet.h>
#include <Sources/Headers/Game Objects/MyAsteroid.h>
#include <Sources/Headers/Game Objects/MyStar.h>
#include <Sources/Headers/Game Objects/MyAlien.h>
#include <Sources/Headers/Game Objects/MyLife.h>
#include <Sources/Headers/Game Objects/MyShield.h>
#include <Sources/Headers/Game Objects/MyMagic.h>
#include <Sources/Headers/Game Objects/MyExplosion.h>
#include <Sources/Headers/Resources.h>

class MyGame : public QGraphicsView {
Q_OBJECT

	friend class MyMainWindow;

public:
	MyGame(QWidget * = 0);

	~MyGame();

signals:

	void gamePaused();

	void gameEnded();

private:
	bool fast;

	QSet<int> *prsd_kys;

	QGraphicsScene *gscn;
	QGraphicsScene *gscn_s;

	QGraphicsTextItem *stg_1;
	QGraphicsTextItem *stg_2;
	QGraphicsTextItem *stg_3;
	QGraphicsTextItem *stg_4;

	MyShip *tmp;
	MyAlien *tmp1;
	MyAsteroid *tmp2;
	MyExplosion *tmp7;
	MyLife *tmp3;
	MyMagic *tmp4;
	MyShield *tmp5;
	MyStar *tmp6;

	int tmr_id;

	void change_speed();

	void pause();

	void unpause();

	void restart();

protected:
	void keyPressEvent(QKeyEvent *);

	void keyReleaseEvent(QKeyEvent *);

	void timerEvent(QTimerEvent *);
};

#endif //SHOOTER_AP93UT_MYGAME_H
