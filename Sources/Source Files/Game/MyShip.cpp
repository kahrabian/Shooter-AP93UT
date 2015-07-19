//
// Created by kahrabian on 7/12/15.
//

#include <QtCore/qtextstream.h>
#include <QTransform>
#include "../../Headers/Game/MyShip.h"

MyShip::MyShip(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	setPos(0.0, 0.0);
	vlc = new QPointF(0.0, 0.0);
	rtn = 0;
//	setTransform(QTransform().rotate(70, Qt::XAxis), true);
}

MyShip::MyShip(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	setPos(0.0, 0.0);
	vlc = new QPointF(0.0, 0.0);
	rtn = 0;
//	setTransform(QTransform().rotate(70, Qt::XAxis), true);
}

MyShip::~MyShip() {

}

int MyShip::getLf() const {
	return lf;
}

void MyShip::setLf(int lf) {
	MyShip::lf = lf;
}

int MyShip::getScr() const {
	return scr;
}

void MyShip::setScr(int scr) {
	MyShip::scr = scr;
}

bool MyShip::isShld() const {
	return shld;
}

void MyShip::setShld(bool shld) {
	MyShip::shld = shld;
}

bool MyShip::isMgc() const {
	return mgc;
}

void MyShip::setMgc(bool mgc) {
	MyShip::mgc = mgc;
}

void MyShip::setVlc(QPointF *vlc) {
	MyShip::vlc = vlc;
}

QPointF *MyShip::getVlc() const {
	return vlc;
}

void MyShip::updt(qint64 stp_tm, QSet<int> *prsd_kys) {
	vlc->setY(0);
	vlc->setX(0);

	if (prsd_kys->find(Qt::Key_Up) != prsd_kys->end())
		vlc->setY(vlc->y() - MyRes::shp_mvmnt);
	if (prsd_kys->find(Qt::Key_Down) != prsd_kys->end())
		vlc->setY(vlc->y() + MyRes::shp_mvmnt);
	if (prsd_kys->find(Qt::Key_Left) != prsd_kys->end())
		vlc->setX(vlc->x() - MyRes::shp_mvmnt);
	if (prsd_kys->find(Qt::Key_Right) != prsd_kys->end())
		vlc->setX(vlc->x() + MyRes::shp_mvmnt);


	if (vlc->y() > 0 && rtn < 30)
		rtn += 3;
	else if (vlc->y() < 0 && rtn > -30)
		rtn -= 3;
	else if (vlc->y() == 0 && rtn < 0)
		rtn += 3;
	else if (vlc->y() == 0 && rtn > 0)
		rtn -= 3;
	setTransform(QTransform().translate(pixmap().size().width() / 2, pixmap().size().height() / 2).rotate(-rtn,
	                                                                                                      Qt::XAxis).translate(
			-pixmap().size().width() / 2, -pixmap().size().height() / 2));
	setPos(pos().x() + MyRes::vw_mvmnt + vlc->x(), pos().y() + vlc->y());
	QGraphicsPixmapItem::update();
}
