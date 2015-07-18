//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYSTAR_H
#define SHOOTER_AP93UT_MYSTAR_H

#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>

class MyStar : public QGraphicsPixmapItem
{
public:
	MyStar(QGraphicsItem * parent = 0);
	MyStar(const QPixmap & pixmap, QGraphicsItem * parent = 0);
	~MyStar();
	void updt(qint64 = 0);

private:
	QElapsedTimer *frm_tmr;

	QPointF *vlc;
};

#endif //SHOOTER_AP93UT_MYSTAR_H
