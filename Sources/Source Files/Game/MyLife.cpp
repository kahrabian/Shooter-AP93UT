//
// Created by kahrabian on 7/13/15.
//

#include "../../Headers/Game/MyLife.h"

MyLife::MyLife(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	frm_tmr = new QElapsedTimer();
	frst_frm = true;
}

MyLife::MyLife(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	frm_tmr = new QElapsedTimer();
	frst_frm = true;
}

MyLife::~MyLife() {

}

void MyLife::updt(qint64 stp_tm) {
	if (frst_frm) {
		frm_tmr->start();
		frst_frm = false;
	}
	else {
		setPos(pos().x() + (vlc->x() * (frm_tmr->elapsed() - stp_tm)),
		       pos().y() + (vlc->y() * (frm_tmr->elapsed() - stp_tm)));
		frm_tmr->restart();
	}
}