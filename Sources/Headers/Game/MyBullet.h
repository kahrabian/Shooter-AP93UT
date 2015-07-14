//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYBULLET_H
#define SHOOTER_AP93UT_MYBULLET_H

#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>

class MyBullet : public QGraphicsPixmapItem
{
public:
	MyBullet(QGraphicsItem * parent = 0);
	MyBullet(const QPixmap & pixmap, QGraphicsItem * parent = 0);
	~MyBullet();
	void updt(qint64 = 0);

private:
	QElapsedTimer *frm_tmr;

	int mss;
	QPointF *pos;
	QPointF *vlc;
	QPointF *acc;
	QPointF *frc;
};

#endif //SHOOTER_AP93UT_MYBULLET_H
