//
// Created by kahrabian on 7/12/15.
//

#include <QtCore/qtextstream.h>
#include <QTransform>
#include "../../Headers/Game/MyShip.h"

MyShip::MyShip(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	setPos(10.0, 10.0);
	vlc = new QPointF(0.0, 0.0);
	rtn = 0;
}

MyShip::MyShip(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap.scaled(QSize(150, 150), Qt::KeepAspectRatio,
		                                  Qt::SmoothTransformation), parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	setPos(10.0, 10.0);
	vlc = new QPointF(0.0, 0.0);
	rtn = 0;
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

void MyShip::cnstrct_shldpxmp() {
	QPixmap *tmp = new QPixmap(250, 250);
	tmp->fill(Qt::transparent);
	QPainter *painter = new QPainter(tmp);
	painter->drawPixmap(125 - (pixmap().width() / 2), 125 - (pixmap().height() / 2), pixmap().width(),
	                    pixmap().height(), QPixmap(pixmap()));
	painter->drawPixmap(0, 0, 250, 250, QPixmap(MyRes::shp_shld_add));
	painter->end();
	setPixmap(*tmp);
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
	cnstrct_shldpxmp();
	setPos(pos().x() + MyRes::vw_mvmnt, pos().y());

	QPointF tplft(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().topLeft()))));
	QPointF bttmrght(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().bottomRight()))));
	QRectF vw_rct(scene()->views().first()->viewport()->rect());

	if (tplft.x() + vlc->x() >= 10 && bttmrght.x() + vlc->x() <= vw_rct.width() - 10)
		setPos(pos().x() + vlc->x(), pos().y());

	if ((tplft.y() + vlc->y() >= 15 && bttmrght.y() + vlc->y() <= vw_rct.height() - 15) ||
	    (tplft.y() + vlc->y() < 15 && vlc->y() > 0) ||
	    ((bttmrght.y() + vlc->y() > vw_rct.height() - 15) && vlc->y() < 0))
		setPos(pos().x(), pos().y() + vlc->y());
	QGraphicsPixmapItem::update();
}
