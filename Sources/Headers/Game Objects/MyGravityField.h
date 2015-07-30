//
// Created by kahrabian on 7/30/15.
//

#ifndef SHOOTER_AP93UT_MYGRAVITYFIELD_H
#define SHOOTER_AP93UT_MYGRAVITYFIELD_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Resources.h>

class MyGravityField : public QObject, public QGraphicsEllipseItem {
Q_OBJECT

public:
	MyGravityField(QRectF, QPointF *);

	~MyGravityField();

	void setAln(bool);

	bool isAln() const;

	QPointF *getVlc() const;

private:
	bool aln;

	QPointF *vlc;
};

#endif //SHOOTER_AP93UT_MYGRAVITYFIELD_H
