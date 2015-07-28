//
// Created by kahrabian on 7/18/15.
//

#include <Sources/Headers/Game Objects/MyMagic.h>

MyMagic::MyMagic() :
		QGraphicsPixmapItem(
				QPixmap(MyRes::mgc_add[rand() % MyRes::mgc_cnt]).scaled(MyRes::mgc_size, Qt::KeepAspectRatio,
				                                                        Qt::SmoothTransformation)), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyMagic::~MyMagic() {
	delete vlc;
}

void MyMagic::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}