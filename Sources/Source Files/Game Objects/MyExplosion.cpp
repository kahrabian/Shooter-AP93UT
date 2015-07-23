//
// Created by kahrabian on 7/23/15.
//

#include <Sources/Headers/Game Objects/MyExplosion.h>

MyExplosion::MyExplosion() :
		QGraphicsPixmapItem() {
	frm_num = 0;
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyExplosion::~MyExplosion() {

}

void MyExplosion::updt() {
	// Size
	setPixmap(QPixmap(MyRes::expln_adds[(frm_num / 2) % MyRes::expln_frcnt]).scaled(MyRes::astrd_size,
	                                                                                Qt::KeepAspectRatio,
	                                                                                Qt::SmoothTransformation));
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
	frm_num = (frm_num + 1) % (2 * MyRes::expln_frcnt);
	if (frm_num == 0)
		hide();
}