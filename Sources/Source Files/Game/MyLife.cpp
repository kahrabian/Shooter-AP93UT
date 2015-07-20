//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game/MyLife.h>

MyLife::MyLife(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0.0, 0.0);
}

MyLife::MyLife(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0.0, 0.0);
}

MyLife::~MyLife() {

}

void MyLife::setVlc(QPointF *vlc) {
	MyLife::vlc = vlc;
}

QPointF *MyLife::getVlc() const {
	return vlc;
}

void MyLife::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}