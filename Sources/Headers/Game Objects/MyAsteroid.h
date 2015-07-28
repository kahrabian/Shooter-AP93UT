//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYASTEROID_H
#define SHOOTER_AP93UT_MYASTEROID_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Resources.h>

class MyAsteroid : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
	MyAsteroid(int);

	~MyAsteroid();

	void updt();

private:
	int astrd_num;
	int frm_num;

//	int typ;
//	bool grv;

//	int mss;
	QPointF *vlc;
//	QPointF *acc;
//	QPointF *frc;

	QPixmap **astrd_frms;
};

#endif //SHOOTER_AP93UT_MYASTEROID_H
