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

class MyAsteroid;

class MyGravityField : public QObject, public QGraphicsEllipseItem {
Q_OBJECT

public:
	MyGravityField(QRectF, MyAsteroid *);

	~MyGravityField();

	MyAsteroid *getPar() const;

private:
	MyAsteroid *par;
};

#endif //SHOOTER_AP93UT_MYGRAVITYFIELD_H
