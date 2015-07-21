//
// Created by kahrabian on 7/20/15.
//

#ifndef SHOOTER_AP93UT_MYSHIPSHIELD_H
#define SHOOTER_AP93UT_MYSHIPSHIELD_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Resources.h>

class MyShipShield : public QGraphicsPixmapItem {
public:
	MyShipShield(QGraphicsItem *parent = 0);

	MyShipShield(const QPixmap &pixmap, QGraphicsItem *parent = 0);

	~MyShipShield();

	void setVlc(QPointF *);

	QPointF *getVlc() const;

	void updt();

private:
	QPointF *vlc;
};

#endif //SHOOTER_AP93UT_MYSHIPSHIELD_H
