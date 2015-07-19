//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYMAGIC_H
#define SHOOTER_AP93UT_MYMAGIC_H

#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>

class MyMagic : public QGraphicsPixmapItem {
public:
	MyMagic(QGraphicsItem *parent = 0);

	MyMagic(const QPixmap &pixmap, QGraphicsItem *parent = 0);

	~MyMagic();

	void setVlc(QPointF *);

	QPointF *getVlc() const;

	void updt(qint64 = 0);

private:
	bool frst_frm;
	QElapsedTimer *frm_tmr;

	QPointF *vlc;
};

#endif //SHOOTER_AP93UT_MYMAGIC_H
