//
// Created by kahrabian on 7/30/15.
//

#include <Sources/Headers/Game Objects/MyGravityField.h>

MyGravityField::MyGravityField(QRectF rct, MyAsteroid *par) :
		QGraphicsEllipseItem(rct), QObject() {
	MyGravityField::par = par;
}

MyGravityField::~MyGravityField() {

}

MyAsteroid *MyGravityField::getPar() const {
	return par;
}