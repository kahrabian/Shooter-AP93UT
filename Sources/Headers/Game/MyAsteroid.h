//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYASTEROID_H
#define SHOOTER_AP93UT_MYASTEROID_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Resources.h>

class MyAsteroid : public QGraphicsPixmapItem {
public:
	MyAsteroid(QGraphicsItem *parent = 0);

	MyAsteroid(const QPixmap &pixmap, QGraphicsItem *parent = 0);

	~MyAsteroid();

	void updt();

private:
	int astrd_num;
	int frm_num;

	bool grv;

	int mss;
	QPointF *vlc;
	QPointF *acc;
	QPointF *frc;
};

#endif //SHOOTER_AP93UT_MYASTEROID_H
