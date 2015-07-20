//
// Created by kahrabian on 7/12/15.
//

#include "../../Headers/Game/MyShip.h"

MyShip::MyShip(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	setPos(10.0, 10.0);
	vlc = new QPointF(0.0, 0.0);
	shpshld = new MyShipShield(MyRes::shp_shld_add);
	shpshld->setGraphicsEffect(new QGraphicsDropShadowEffect());
	shld_tmr = new QTimer();
	QTimer::connect(shld_tmr, SIGNAL(timeout()), this, SLOT(deactivate_shld()));
	mgc_tmr = new QTimer();
	QTimer::connect(mgc_tmr, SIGNAL(timeout()), this, SLOT(deactivate_mgc()));
//	shpshld->hide();
}

MyShip::MyShip(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap.scaled(QSize(150, 150), Qt::KeepAspectRatio,
		                                  Qt::SmoothTransformation), parent), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	setPos(10.0, 10.0);
	vlc = new QPointF(0.0, 0.0);
	shpshld = new MyShipShield(MyRes::shp_shld_add);
	shpshld->setGraphicsEffect(new QGraphicsDropShadowEffect());
	shld_tmr = new QTimer();
	QTimer::connect(shld_tmr, SIGNAL(timeout()), this, SLOT(deactivate_shld()));
	mgc_tmr = new QTimer();
	QTimer::connect(mgc_tmr, SIGNAL(timeout()), this, SLOT(deactivate_mgc()));
	shpshld->hide();
	activate_shld();
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
	shpshld->setPos(pos().x() + (pixmap().width() / 2) - (shpshld->pixmap().width() / 2),
	                pos().y() + (pixmap().height() / 2) - (shpshld->pixmap().height() / 2));
}

void MyShip::activate_shld() {
	shld = true;
	shpshld->show();
	shld_tmr->start(5000);
}

void MyShip::deactivate_shld() {
	shld = false;
	shpshld->hide();
	shld_tmr->stop();
}

void MyShip::activate_mgc() {
	mgc = true;
	mgc_tmr->start(5000);
}

void MyShip::deactivate_mgc() {
	mgc = false;
	mgc_tmr->stop();
}

void MyShip::cllsn_dtctn() {
	QList<QGraphicsItem *> clldng_items = collidingItems(Qt::ItemSelectionMode::IntersectsItemShape);
			foreach(QGraphicsItem *i, clldng_items) {
			if (dynamic_cast<MyStar *>(i)) {
				scr++;
				scene()->removeItem(i);
			}
			else if (dynamic_cast<MyShield *>(i)) {
				activate_shld();
				scene()->removeItem(i);
			}
			else if (dynamic_cast<MyMagic *>(i)) {
				activate_mgc();
				scene()->removeItem(i);
			}
			else if (dynamic_cast<MyLife *>(i)) {
				lf++;
				scene()->removeItem(i);
			}
		}
}

void MyShip::updt_vlc(QSet<int> *prsd_kys) {
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
}

void MyShip::updt_rtn() {
	if (vlc->y() > 0 && rtn < 30)
		rtn += 3;
	else if (vlc->y() < 0 && rtn > -30)
		rtn -= 3;
	else if (vlc->y() == 0 && rtn < 0)
		rtn += 3;
	else if (vlc->y() == 0 && rtn > 0)
		rtn -= 3;
}

void MyShip::updt_pos() {
	setTransform(QTransform().translate(pixmap().size().width() / 2, pixmap().size().height() / 2).rotate(-rtn,
	                                                                                                      Qt::XAxis).translate(
			-pixmap().size().width() / 2, -pixmap().size().height() / 2));
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
	cnstrct_shldpxmp();
}

void MyShip::updt(QSet<int> *prsd_kys) {
	cllsn_dtctn();
	updt_vlc(prsd_kys);
	updt_rtn();
	updt_pos();
	QGraphicsPixmapItem::update();
}
