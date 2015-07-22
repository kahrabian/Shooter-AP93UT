//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game Objects/MyBullet.h>

MyBullet::MyBullet(int lsr_num, int rtn, int dir, QGraphicsItem *mstr) :
		QGraphicsPixmapItem(QPixmap(MyRes::lsr_add[lsr_num]).scaled(MyRes::lsr_size, Qt::KeepAspectRatio,
		                                                            Qt::SmoothTransformation)) {
	MyBullet::mstr = mstr;
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

QGraphicsItem *MyBullet::getMstr() const {
	return mstr;
}

void MyBullet::cllsn_dtctn() {
	QList<QGraphicsItem *> clldng_items = collidingItems(Qt::ItemSelectionMode::IntersectsItemShape);
			foreach(QGraphicsItem *i, clldng_items) {
			if (dynamic_cast<MyAlien *>(i)) {
				scene()->removeItem(i);
			}
			else if (dynamic_cast<MyAsteroid *>(i)) {
				scene()->removeItem(i);
			}
		}
}

void MyBullet::updt() {
	setPos(pos().x() + MyRes::vw_mvmnt + vlc->x(), pos().y() + vlc->y());
}