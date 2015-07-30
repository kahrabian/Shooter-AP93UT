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

	friend class MyGame;

public:
	MyAsteroid(int);

	~MyAsteroid();

	void updt();

	void setAln(bool);

	bool isAln() const;

	QPointF *getVlc() const;

private:
	int astrd_num;
	int frm_num;

	bool grv;
	bool aln;

	QGraphicsEllipseItem *grv_fld;

	QPointF *vlc;

	QPixmap **astrd_frms;
};

#endif //SHOOTER_AP93UT_MYASTEROID_H
