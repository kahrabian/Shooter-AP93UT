//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYMAGIC_H
#define SHOOTER_AP93UT_MYMAGIC_H

#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>

class MyMagic : public QGraphicsPixmapItem
{
//    Q_OBJECT
public:
	MyMagic(QGraphicsItem * parent = 0);
	MyMagic(const QPixmap & pixmap, QGraphicsItem * parent = 0);
	~MyMagic();
	void updt(qint64 = 0);

private:
	QElapsedTimer *frm_tmr;

	int mss;
	QPointF *pos;
	QPointF *vlc;
	QPointF *acc;
	QPointF *frc;
};

#endif //SHOOTER_AP93UT_MYMAGIC_H