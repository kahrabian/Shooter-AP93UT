//
// Created by kahrabian on 7/20/15.
//

#include <Sources/Headers/Game Objects/MyShipShield.h>

MyShipShield::MyShipShield(MyShip *mstr) :
		QGraphicsPixmapItem(QPixmap(MyRes::shp_shld_add).scaled(MyRes::shp_shld_size, Qt::KeepAspectRatio,
		                                                        Qt::SmoothTransformation)), QObject() {
	MyShipShield::mstr = mstr;
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyShipShield::~MyShipShield() {

}

void MyShipShield::cllsn_dtctn() {
	QList<QGraphicsItem *> clldng_items = collidingItems(Qt::ItemSelectionMode::IntersectsItemShape);
			foreach(QGraphicsItem *i, clldng_items) {
			if (dynamic_cast<MyAsteroid *>(i)) {
				scene()->removeItem(i);
			}
			else if (dynamic_cast<MyBullet *>(i)) {
				scene()->removeItem(i);
			}
//			else if (dynamic_cast<MyShip *>(i) && dynamic_cast<MyShip *>(i) != mstr) {
//				emit shieldDestroyd();
//			}
		}
}

void MyShipShield::updt() {
	cllsn_dtctn();
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}
