//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game Objects/MyShield.h>

MyShield::MyShield() :
		QGraphicsPixmapItem(QPixmap(MyRes::shld_add).scaled(MyRes::shld_size, Qt::KeepAspectRatio,
		                                                    Qt::SmoothTransformation)), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyShield::~MyShield() {
	delete vlc;
}

void MyShield::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}