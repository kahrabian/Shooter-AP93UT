//
// Created by kahrabian on 7/12/15.
//

#ifndef SHOOTER_AP93UT_MYGAME_H
#define SHOOTER_AP93UT_MYGAME_H

#include <QGraphicsScene>
#include <QElapsedTimer>
#include <QTimer>
#include <QVector>
#include "MyShip.h"
#include "MyBullet.h"
#include "MyAsteroid.h"
#include "MyStar.h"
#include "MyAlien.h"
#include "MyLife.h"
#include "MyShield.h"
#include "MyMagic.h"

class MyGame : public QGraphicsScene
{
    Q_OBJECT
    friend class MyMainWindow;
public:
    MyGame(QObject * = 0);
    MyGame(const QRectF &, QObject * = 0);
    MyGame(qreal, qreal, qreal, qreal, QObject * = 0);
    ~MyGame();

private:
    QVector<MyShip> shps;
    QVector<MyBullet> blts;
    QVector<MyAsteroid> astrs;
    QVector<MyStar> strs;
    QVector<MyAlien> alns;
    QVector<MyLife> lfs;
    QVector<MyShield> shlds;
    QVector<MyMagic> mgns;

	QTimer *g_tmr;
	QElapsedTimer *stp_tmr;
	qint64 stp_tmr_val;
};

#endif //SHOOTER_AP93UT_MYGAME_H
