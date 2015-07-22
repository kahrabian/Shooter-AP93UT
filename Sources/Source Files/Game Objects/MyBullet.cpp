//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game Objects/MyBullet.h>

MyBullet::MyBullet(int lsr_num, int rtn, QGraphicsItem *parent) :
		QGraphicsPixmapItem(QPixmap(MyRes::lsr_add[lsr_num]).scaled(MyRes::lsr_size, Qt::KeepAspectRatio,
		                                                            Qt::SmoothTransformation), parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	MyBullet::rtn = rtn;
	vlc = new QPointF(MyRes::lsr_mvmnt * cos(rtn * M_PI / 180.0), MyRes::lsr_mvmnt * sin(rtn * M_PI / 180.0));
	setTransformOriginPoint(0, pixmap().height() / 2);
	setRotation(rtn);
}

MyBullet::~MyBullet() {

}

void MyBullet::updt() {
	setPos(pos().x() + MyRes::vw_mvmnt + vlc->x(), pos().y() + vlc->y());
}