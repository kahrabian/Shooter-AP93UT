//
// Created by kahrabian on 7/13/15.
//

#include "../../Headers/Game/MyLife.h"

MyLife::MyLife(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	frm_tmr = new QElapsedTimer();
	vlc = new QPointF(0.0, 0.0);
	frst_frm = true;
}

MyLife::MyLife(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	frm_tmr = new QElapsedTimer();
	vlc = new QPointF(0.0, 0.0);
	frst_frm = true;
}

MyLife::~MyLife() {

}

void MyLife::setVlc(QPointF *vlc) {
	MyLife::vlc = vlc;
}

QPointF *MyLife::getVlc() const {
	return vlc;
}

void MyLife::updt(qint64 stp_tm) {
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