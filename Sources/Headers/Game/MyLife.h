//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYLIFE_H
#define SHOOTER_AP93UT_MYLIFE_H

#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>

class MyLife : public QGraphicsPixmapItem {
public:
	MyLife(QGraphicsItem *parent = 0);

	MyLife(const QPixmap &pixmap, QGraphicsItem *parent = 0);

	~MyLife();

	void updt(qint64 = 0);

private:
	QElapsedTimer *frm_tmr;
	bool frst_frm;

	QPointF *vlc;
};

#endif //SHOOTER_AP93UT_MYLIFE_H
