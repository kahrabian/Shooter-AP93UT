//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game Objects/MyLife.h>

MyLife::MyLife() :
		QGraphicsPixmapItem(QPixmap(MyRes::lf_add).scaled(MyRes::lf_size, Qt::KeepAspectRatio,
		                                                  Qt::SmoothTransformation)), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyLife::~MyLife() {

}

void MyLife::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}