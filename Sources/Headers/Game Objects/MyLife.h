//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYLIFE_H
#define SHOOTER_AP93UT_MYLIFE_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Resources.h>

class MyLife : public QGraphicsPixmapItem {
public:
	MyLife(QGraphicsItem *parent = 0);

	~MyLife();

	void updt();

private:
	QPointF *vlc;
};

#endif //SHOOTER_AP93UT_MYLIFE_H
