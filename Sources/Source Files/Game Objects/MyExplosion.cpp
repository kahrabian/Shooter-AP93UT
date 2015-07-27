//
// Created by kahrabian on 7/23/15.
//

#include <Sources/Headers/Game Objects/MyExplosion.h>

MyExplosion::MyExplosion(QSize *expln_size) :
		QGraphicsPixmapItem(), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	frm_num = 0;
	vlc = new QPointF(0, 0);
	MyExplosion::expln_size = expln_size;
}

MyExplosion::~MyExplosion() {

}

void MyExplosion::updt() {
	frm_num = (frm_num + 1) % (2 * MyRes::expln_frcnt);
	if (frm_num == 0)
		hide();
	setPixmap(QPixmap(MyRes::expln_adds[(frm_num / 2) % MyRes::expln_frcnt]).scaled((*expln_size),
	                                                                                Qt::KeepAspectRatio,
	                                                                                Qt::SmoothTransformation));
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}