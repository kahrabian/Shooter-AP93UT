//
// Created by kahrabian on 7/13/15.
//

#include "../../Headers/Game/MyStar.h"

MyStar::MyStar(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	frm_tmr = new QElapsedTimer();
	vlc = new QPointF(0.0, 0.0);
	frst_frm = true;
}

MyStar::MyStar(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	frm_tmr = new QElapsedTimer();
	vlc = new QPointF(0.0, 0.0);
	frst_frm = true;
}

MyStar::~MyStar() {

}

void MyStar::setVlc(QPointF *vlc) {
	MyStar::vlc = vlc;
}

QPointF *MyStar::getVlc() const {
	return vlc;
}

void MyStar::updt(qint64 stp_tm) {
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
