//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYSHIELD_H
#define SHOOTER_AP93UT_MYSHIELD_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Resources.h>

class MyShield : public QGraphicsPixmapItem {
public:
	MyShield();

	~MyShield();

	void updt();

private:
	QPointF *vlc;
};

#endif //SHOOTER_AP93UT_MYSHIELD_H
