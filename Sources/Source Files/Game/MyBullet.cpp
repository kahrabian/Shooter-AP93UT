//
// Created by kahrabian on 7/13/15.
//

#include "../../Headers/Game/MyBullet.h"

MyBullet::MyBullet(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	frm_tmr = new QElapsedTimer();
	vlc = new QPointF(0.0, 0.0);
	frst_frm = true;
}

MyBullet::MyBullet(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	frm_tmr = new QElapsedTimer();
	vlc = new QPointF(0.0, 0.0);
	frst_frm = true;
}

MyBullet::~MyBullet() {

}

void MyBullet::setVlc(QPointF *vlc) {
	MyBullet::vlc = vlc;
}

QPointF *MyBullet::getVlc() const {
	return vlc;
}

void MyBullet::updt(qint64 stp_tm) {
	if (frst_frm) {
		frst_frm = false;
		frm_tmr->start();
	}
	else {
		setPos(pos().x() + (vlc->x() * (frm_tmr->elapsed() - stp_tm)),
		       pos().y() + (vlc->y() * (frm_tmr->elapsed() - stp_tm)));
		frm_tmr->restart();
	}
}