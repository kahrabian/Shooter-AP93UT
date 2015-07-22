//
// Created by kahrabian on 7/20/15.
//

#include <Sources/Headers/Game Objects/MyShipShield.h>

MyShipShield::MyShipShield() :
		QGraphicsPixmapItem(QPixmap(MyRes::shp_shld_add).scaled(MyRes::shp_shld_size, Qt::KeepAspectRatio,
		                                                        Qt::SmoothTransformation)), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyShipShield::~MyShipShield() {

}

void MyShipShield::cllsn_dtctn() {
	QList<QGraphicsItem *> clldng_items = collidingItems(Qt::ItemSelectionMode::IntersectsItemShape);
			foreach(QGraphicsItem *i, clldng_items) {
			if ((dynamic_cast<MyAsteroid *>(i) || dynamic_cast<MyBullet *>(i)) && isVisible()) {
				scene()->removeItem(i);
			}
			else if (dynamic_cast<MyAlien *>(i)/* || dynamic_cast<MyShip *>(i))*/ && isVisible()) {
				dynamic_cast<MyAlien *>(i)->killTimer(dynamic_cast<MyAlien *>(i)->getTmr_id());
				scene()->removeItem(i);
				emit shieldDestroyd();
			}
		}
}

void MyShipShield::updt() {
	cllsn_dtctn();
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}
