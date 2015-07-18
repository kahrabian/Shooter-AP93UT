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
#include "MyShip.h"
#include "MyBullet.h"
#include "MyAsteroid.h"
#include "MyStar.h"
#include "MyAlien.h"
#include "MyLife.h"
#include "MyShield.h"
#include "MyMagic.h"

class MyGame : public QGraphicsView
{
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

    QList<MyShip> shps;
    QList<MyBullet> blts;
    QList<MyAsteroid> astrs;
    QList<MyStar> strs;
    QList<MyAlien> alns;
    QList<MyLife> lfs;
    QList<MyShield> shlds;
    QList<MyMagic> mgns;

	QElapsedTimer *stp_tmr;
	qint64 stp_tmr_val;

	int timer_id;

	void unpause();
	void restart();

protected:
	void keyPressEvent(QKeyEvent *);
	void keyReleaseEvent(QKeyEvent *);
	void timerEvent(QTimerEvent *);
};

#endif //SHOOTER_AP93UT_MYGAME_H
