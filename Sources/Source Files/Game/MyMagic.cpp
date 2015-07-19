//
// Created by kahrabian on 7/18/15.
//

#include "../../Headers/Game/MyMagic.h"

MyMagic::MyMagic(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	frm_tmr = new QElapsedTimer();
	frst_frm = true;
}

MyMagic::MyMagic(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	frm_tmr = new QElapsedTimer();
	frst_frm = true;
}

MyMagic::~MyMagic() {

}

void MyMagic::updt(qint64 stp_tm) {
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