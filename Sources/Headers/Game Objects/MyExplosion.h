//
// Created by kahrabian on 7/23/15.
//

#ifndef SHOOTER_AP93UT_MYEXPLOSION_H
#define SHOOTER_AP93UT_MYEXPLOSION_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Resources.h>

class MyExplosion : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
	MyExplosion(QSize *);

	~MyExplosion();

	void updt();

private:
	int frm_num;

	QSize *expln_size;

	QPointF *vlc;

	QPixmap **expln_frms;
};

#endif //SHOOTER_AP93UT_MYEXPLOSION_H
