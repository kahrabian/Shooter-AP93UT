//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game/MyAsteroid.h>

MyAsteroid::MyAsteroid(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	astrd_num = rand() % MyRes::astrd_typcnt;
	frm_num = 0;
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0.0, 0.0);
}

MyAsteroid::MyAsteroid(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0.0, 0.0);
}

MyAsteroid::~MyAsteroid() {

}

//void MyAsteroid::setVlc(QPointF *vlc) {
//	MyAsteroid::vlc = vlc;
//}
//
//QPointF *MyAsteroid::getVlc() const {
//	return vlc;
//}

void MyAsteroid::updt() {
	setPixmap(QPixmap(MyRes::astrd_adds[astrd_num][(frm_num / 3) % MyRes::astrd_frcnt]).scaled(MyRes::astrd_size,
	                                                                                           Qt::KeepAspectRatio,
	                                                                                           Qt::SmoothTransformation));
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
	frm_num++;
}