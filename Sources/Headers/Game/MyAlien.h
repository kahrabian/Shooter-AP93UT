//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYALIEN_H
#define SHOOTER_AP93UT_MYALIEN_H

#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>

class MyAlien : public QGraphicsPixmapItem {
public:
	MyAlien(QGraphicsItem *parent = 0);

	MyAlien(const QPixmap &pixmap, QGraphicsItem *parent = 0);

	~MyAlien();

	void updt(qint64 = 0);

private:
	QElapsedTimer *frm_tmr;

	int typ;

	QTimer blt_tmr;

	int mss;
	QPointF *pos;
	QPointF *vlc;
	QPointF *acc;
	QPointF *frc;
};

#endif //SHOOTER_AP93UT_MYALIEN_H
