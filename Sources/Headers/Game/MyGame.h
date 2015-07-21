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
#include <Sources/Headers/Game/MyShip.h>
#include <Sources/Headers/Game/MyBullet.h>
#include <Sources/Headers/Game/MyAsteroid.h>
#include <Sources/Headers/Game/MyStar.h>
#include <Sources/Headers/Game/MyAlien.h>
#include <Sources/Headers/Game/MyLife.h>
#include <Sources/Headers/Game/MyShield.h>
#include <Sources/Headers/Game/MyMagic.h>
#include <Sources/Headers/Resources.h>

class MyGame : public QGraphicsView {
Q_OBJECT

	friend class MyMainWindow;

public:
	MyGame(QWidget * = 0);

	MyGame(QGraphicsScene *, QWidget * = 0);

	~MyGame();

signals:

	void gamePaused();

	void gameEnded();

private:
	QSet<int> *prsd_kys;

	QGraphicsScene *gscn;

	MyShip *tmp;
	MyAsteroid *tmp1;
//	MyMagic *tmp2;
//	MyShield *tmp3;
//	MyStar *tmp4;

	int timer_id;

	void unpause();

	void restart();

protected:
	void keyPressEvent(QKeyEvent *);

	void keyReleaseEvent(QKeyEvent *);

	void timerEvent(QTimerEvent *);
};

#endif //SHOOTER_AP93UT_MYGAME_H
