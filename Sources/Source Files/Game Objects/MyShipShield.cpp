//
// Created by kahrabian on 7/20/15.
//

#include <Sources/Headers/Game Objects/MyShipShield.h>

MyShipShield::MyShipShield(QGraphicsItem *parent) :
		QGraphicsPixmapItem(QPixmap(MyRes::shp_shld_add).scaled(MyRes::shp_shld_size, Qt::KeepAspectRatio,
		                                                        Qt::SmoothTransformation), parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyShipShield::~MyShipShield() {

}

void MyShipShield::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}
