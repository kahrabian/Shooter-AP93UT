//
// Created by kahrabian on 7/23/15.
//

#include <Sources/Headers/Game Objects/MyExplosion.h>

MyExplosion::MyExplosion(QSize *expln_size) :
		QGraphicsPixmapItem(), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	expln_frms = new QPixmap *[MyRes::expln_frcnt];
	frm_num = 0;
	vlc = new QPointF(-1, 0);
	MyExplosion::expln_size = expln_size;
	for (int i = 0; i < MyRes::expln_frcnt; i++) {
		expln_frms[i] = new QPixmap(MyRes::expln_adds[i]);
	}
	setPixmap(*expln_frms[0]);
}

MyExplosion::~MyExplosion() {
	for (int i = 0; i < MyRes::expln_frcnt; i++) {
		delete expln_frms[i];
	}
	delete[] expln_frms;
	delete expln_size;
	delete vlc;
}

void MyExplosion::updt() {
	frm_num = (frm_num + 1) % (2 * MyRes::expln_frcnt);
	if (frm_num == 0)
		hide();
	setPixmap(expln_frms[(frm_num / 2) % MyRes::expln_frcnt]->scaled((*expln_size), Qt::KeepAspectRatio,
	                                                                 Qt::SmoothTransformation));
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}