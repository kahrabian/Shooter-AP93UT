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
#include <Sources/Headers/Game Objects/MyGravityField.h>
#include <Sources/Headers/Resources.h>

class MyGame : public QGraphicsView {
Q_OBJECT

	friend class MyMainWindow;

public:
	MyGame(QWidget * = 0);

	~MyGame();

	void restart();

signals:

	void gamePaused();

	void gameEnded(int);

private:
	bool fast;

	QSet<int> *prsd_kys;

	QGraphicsScene *gscn;

	MyShip *shp1;
	MyShip *shp2;

	int tmr_id;

	int cur_stg;

	void change_speed();

	void bld_stg1();

	void bld_stg2();

	void bld_stg3();

	void bld_bss();

	void clean();

	void pause();

	void unpause();

protected:
	void keyPressEvent(QKeyEvent *);

	void keyReleaseEvent(QKeyEvent *);

	void timerEvent(QTimerEvent *);
};

#endif //SHOOTER_AP93UT_MYGAME_H
