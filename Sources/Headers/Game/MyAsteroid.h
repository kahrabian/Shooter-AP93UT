//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYASTEROID_H
#define SHOOTER_AP93UT_MYASTEROID_H

#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>

class MyAsteroid : public QGraphicsPixmapItem
{
public:
	MyAsteroid(QGraphicsItem * parent = 0);
	MyAsteroid(const QPixmap & pixmap, QGraphicsItem * parent = 0);
	~MyAsteroid();
	void updt(qint64 = 0);

private:
	QElapsedTimer *frm_tmr;

	bool grv;

	int mss;
	QPointF *pos;
	QPointF *vlc;
	QPointF *acc;
	QPointF *frc;
};

#endif //SHOOTER_AP93UT_MYASTEROID_H
