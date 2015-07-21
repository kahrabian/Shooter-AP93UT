//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game/MyShield.h>

MyShield::MyShield(QGraphicsItem *parent) :
		QGraphicsPixmapItem(QPixmap(MyRes::shld_add).scaled(MyRes::shld_size, Qt::KeepAspectRatio,
		                                                    Qt::SmoothTransformation), parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0.0, 0.0);
}

MyShield::MyShield(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0.0, 0.0);
}

MyShield::~MyShield() {

}

void MyShield::setVlc(QPointF *vlc) {
	MyShield::vlc = vlc;
}

QPointF *MyShield::getVlc() const {
	return vlc;
}

void MyShield::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}