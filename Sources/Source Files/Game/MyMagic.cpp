//
// Created by kahrabian on 7/18/15.
//

#include "../../Headers/Game/MyMagic.h"

MyMagic::MyMagic(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	frm_tmr = new QElapsedTimer();
	vlc = new QPointF(0.0, 0.0);
	frst_frm = true;
}

MyMagic::MyMagic(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	frm_tmr = new QElapsedTimer();
	vlc = new QPointF(0.0, 0.0);
	frst_frm = true;
}

MyMagic::~MyMagic() {

}

void MyMagic::setVlc(QPointF *vlc) {
	MyMagic::vlc = vlc;
}

QPointF *MyMagic::getVlc() const {
	return vlc;
}

void MyMagic::updt(qint64 stp_tm) {
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