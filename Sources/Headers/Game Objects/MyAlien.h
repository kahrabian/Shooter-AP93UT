//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYALIEN_H
#define SHOOTER_AP93UT_MYALIEN_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Game Objects/MyBullet.h>
#include <Sources/Headers/Resources.h>

class MyAlien : public QObject, public QGraphicsPixmapItem {
public:
	MyAlien();

	~MyAlien();

	void updt();

private:
	int typ;

	int tmr_id;

	int mss;
	QPointF *vlc;
	QPointF *acc;
	QPointF *frc;

protected:
	void timerEvent(QTimerEvent *);
};

#endif //SHOOTER_AP93UT_MYALIEN_H
