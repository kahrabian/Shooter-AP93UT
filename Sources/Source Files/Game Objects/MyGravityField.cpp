//
// Created by kahrabian on 7/30/15.
//

#include <Sources/Headers/Game Objects/MyGravityField.h>

MyGravityField::MyGravityField(QRectF rct, QPointF *vlc) :
		QGraphicsEllipseItem(rct), QObject() {
	MyGravityField::vlc = new QPointF(vlc->x(), vlc->y());
	aln = false;
}

MyGravityField::~MyGravityField() {
	delete vlc;
}

void MyGravityField::setAln(bool aln) {
	MyGravityField::aln = aln;
}

bool MyGravityField::isAln() const {
	return aln;
}

QPointF *MyGravityField::getVlc() const {
	return vlc;
}

