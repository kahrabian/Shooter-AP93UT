//
// Created by kahrabian on 7/20/15.
//

#include <Sources/Headers/Game/MyShipShield.h>

MyShipShield::MyShipShield(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0.0, 0.0);
}

MyShipShield::MyShipShield(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0.0, 0.0);
}

MyShipShield::~MyShipShield() {

}

void MyShipShield::setVlc(QPointF *vlc) {
	MyShipShield::vlc = vlc;
}

QPointF *MyShipShield::getVlc() const {
	return vlc;
}

void MyShipShield::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}
