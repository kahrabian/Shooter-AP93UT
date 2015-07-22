//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYALIEN_H
#define SHOOTER_AP93UT_MYALIEN_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Resources.h>

class MyAlien : public QObject, public QGraphicsPixmapItem {
public:
	MyAlien(QGraphicsItem *parent = 0);

	~MyAlien();

	void updt();

private:
	int typ;

	int mss;
	QPointF *vlc;
	QPointF *acc;
	QPointF *frc;
};

#endif //SHOOTER_AP93UT_MYALIEN_H
