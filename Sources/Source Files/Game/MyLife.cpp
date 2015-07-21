//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game/MyLife.h>

MyLife::MyLife(QGraphicsItem *parent) :
		QGraphicsPixmapItem(QPixmap(MyRes::lf_add).scaled(MyRes::lf_size, Qt::KeepAspectRatio,
		                                                  Qt::SmoothTransformation), parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyLife::MyLife(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyLife::~MyLife() {

}

void MyLife::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}