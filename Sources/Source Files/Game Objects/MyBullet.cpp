//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game Objects/MyBullet.h>

MyBullet::MyBullet(int lsr_num, int rtn, int dir) :
		QGraphicsPixmapItem(QPixmap(MyRes::lsr_add[lsr_num]).scaled(MyRes::lsr_size, Qt::KeepAspectRatio,
		                                                            Qt::SmoothTransformation)), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	if (dir == -1)
		MyBullet::rtn = 180 - rtn;
	else
		MyBullet::rtn = rtn;
	vlc = new QPointF(MyRes::lsr_mvmnt * cos(MyBullet::rtn * M_PI / 180.0),
	                  MyRes::lsr_mvmnt * sin(MyBullet::rtn * M_PI / 180.0));
	setTransformOriginPoint(0, pixmap().height() / 2);
	setRotation(MyBullet::rtn);
}

MyBullet::~MyBullet() {

}

void MyBullet::cllsn_dtctn() {
	QList<QGraphicsItem *> clldng_items = collidingItems(Qt::ItemSelectionMode::IntersectsItemShape);
			foreach(QGraphicsItem *i, clldng_items) {
			if (dynamic_cast<MyAlien *>(i) && vlc->x() > 0) {
				dynamic_cast<MyAlien *>(i)->killTimer(dynamic_cast<MyAlien *>(i)->getTmr_id());
				scene()->removeItem(i);
				hide();
//				emit scrGained();
			}
			else if (dynamic_cast<MyAsteroid *>(i)) {
				scene()->removeItem(i);
				hide();
			}
		}
}

void MyBullet::updt() {
	cllsn_dtctn();
	setPos(pos().x() + MyRes::vw_mvmnt + vlc->x(), pos().y() + vlc->y());
}