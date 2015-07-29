//
// Created by kahrabian on 7/28/15.
//

#ifndef SHOOTER_AP93UT_MYALIENBOSS_H
#define SHOOTER_AP93UT_MYALIENBOSS_H

#include <QSoundEffect>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Resources.h>

class MyAlienBoss : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
	MyAlienBoss(int, int, int);

	~MyAlienBoss();

	int getStg() const;

	void updt();

private:
	int astrd_num;
	int frm_num;

	int stg;

	QPointF *vlc;

	QPixmap **astrd_frms;
};

#endif //SHOOTER_AP93UT_MYALIENBOSS_H
