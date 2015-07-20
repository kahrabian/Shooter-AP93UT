//
// Created by kahrabian on 7/18/15.
//

#include <Sources/Headers/Game/MyMagic.h>

MyMagic::MyMagic(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0.0, 0.0);
}

MyMagic::MyMagic(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0.0, 0.0);
}

MyMagic::~MyMagic() {

}

void MyMagic::setVlc(QPointF *vlc) {
	MyMagic::vlc = vlc;
}

QPointF *MyMagic::getVlc() const {
	return vlc;
}

void MyMagic::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}