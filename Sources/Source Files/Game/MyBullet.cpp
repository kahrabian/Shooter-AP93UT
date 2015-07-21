//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game/MyBullet.h>

MyBullet::MyBullet(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyBullet::MyBullet(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyBullet::~MyBullet() {

}

void MyBullet::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}