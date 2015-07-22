//
// Created by kahrabian on 7/12/15.
//

#include <Sources/Headers/Game Objects/MyShip.h>

MyShip::MyShip(const QPixmap &pixmap) :
		QGraphicsPixmapItem(pixmap.scaled(MyRes::shp_size, Qt::KeepAspectRatio,
		                                  Qt::SmoothTransformation)), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	setPos(MyRes::x_offset, MyRes::y_offset);

	vlc = new QPointF(0, 0);

	shpshld = new MyShipShield();
	shpshld->setGraphicsEffect(new QGraphicsDropShadowEffect());

	shld_tmr = new QTimer();
	mgc_tmr = new QTimer();

	QTimer::connect(shld_tmr, SIGNAL(timeout()), this, SLOT(deactivate_shld()));
	QTimer::connect(shpshld, SIGNAL(shieldDestroyd()), this, SLOT(deactivate_shld()));
	QTimer::connect(mgc_tmr, SIGNAL(timeout()), this, SLOT(deactivate_mgc()));

	activate_shld();
	activate_mgc();
}

MyShip::~MyShip() {

}

void MyShip::cnstrct_shldpxmp() {
	shpshld->setPos(pos().x() + (pixmap().width() / 2) - (shpshld->pixmap().width() / 2),
	                pos().y() + (pixmap().height() / 2) - (shpshld->pixmap().height() / 2));
}

void MyShip::activate_shld() {
	shld = true;
	shpshld->show();
	shld_tmr->start(MyRes::spcl_tm);
}

void MyShip::deactivate_shld() {
	shld = false;
	shpshld->hide();
	shld_tmr->stop();
}

void MyShip::activate_mgc() {
	mgc = true;
	mgc_tmr->start(MyRes::spcl_tm);
}

void MyShip::deactivate_mgc() {
	mgc = false;
	mgc_tmr->stop();
}

void MyShip::cllsn_dtctn() {
	QList<QGraphicsItem *> clldng_items = collidingItems(Qt::ItemSelectionMode::IntersectsItemShape);
			foreach(QGraphicsItem *i, clldng_items) {
			if (dynamic_cast<MyLife *>(i)) {
				scr++;
				scene()->removeItem(i);
			}
			else if (dynamic_cast<MyMagic *>(i)) {
				activate_shld();
				scene()->removeItem(i);
			}
			else if (dynamic_cast<MyShield *>(i)) {
				activate_mgc();
				scene()->removeItem(i);
			}
			else if (dynamic_cast<MyShip *>(i)) {
				lf--;
			}
			else if (dynamic_cast<MyShipShield *>(i) && dynamic_cast<MyShipShield *>(i) != shpshld) {
				lf--;
				dynamic_cast<MyShipShield *>(i)->dstry();
			}
			else if (dynamic_cast<MyStar *>(i)) {
				lf++;
				scene()->removeItem(i);
			}
			else if (dynamic_cast<MyAlien *>(i)) {
				lf--;
				dynamic_cast<MyAlien *>(i)->killTimer(dynamic_cast<MyAlien *>(i)->getTmr_id());
				scene()->removeItem(i);
				// Add Explosion
			}
			else if (dynamic_cast<MyAlien *>(i) || dynamic_cast<MyAsteroid *>(i) || dynamic_cast<MyBullet *>(i)) {
				lf--;
				scene()->removeItem(i);
				// Add Explosion
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
	if (prsd_kys->find(Qt::Key_Space) != prsd_kys->end()) {
		if (!mgc) {
			MyBullet *tmp = new MyBullet(0);
			tmp->setPos(pos().x() + pixmap().width(),
			            pos().y() + (pixmap().height() / 2) - (MyRes::lsr_size.height() / 2));
			scene()->addItem(tmp);
		}
		else {
			for (int i = -MyRes::lsr_rtn_max; i <= MyRes::lsr_rtn_max; i += MyRes::lsr_rtn_stp) {
				MyBullet *tmp = new MyBullet(0, i);
				tmp->setPos(pos().x() + pixmap().width(),
				            pos().y() + (pixmap().height() / 2) - (MyRes::lsr_size.height() / 2));
				scene()->addItem(tmp);
			}
		}
	}
}

void MyShip::updt_rtn() {
	if (vlc->y() > 0 && rtn < MyRes::rtn_max)
		rtn += MyRes::rtn_stp;
	else if (vlc->y() < 0 && rtn > -MyRes::rtn_max)
		rtn -= MyRes::rtn_stp;
	else if (vlc->y() == 0 && rtn < 0)
		rtn += MyRes::rtn_stp;
	else if (vlc->y() == 0 && rtn > 0)
		rtn -= MyRes::rtn_stp;
}

void MyShip::updt_pos() {
	setTransform(QTransform().translate(pixmap().size().width() / 2, pixmap().size().height() / 2).rotate(-rtn,
	                                                                                                      Qt::XAxis).translate(
			-pixmap().size().width() / 2, -pixmap().size().height() / 2));

	QPointF tplft(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().topLeft()))));
	QPointF bttmrght(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().bottomRight()))));
	QRectF vw_rct(scene()->views().first()->viewport()->rect());

	if (tplft.x() + vlc->x() >= MyRes::x_offset && bttmrght.x() + vlc->x() <= vw_rct.width() - MyRes::x_offset)
		setPos(pos().x() + vlc->x(), pos().y());

	if ((tplft.y() + vlc->y() >= MyRes::y_offset && bttmrght.y() + vlc->y() <= vw_rct.height() - MyRes::y_offset) ||
	    (tplft.y() + vlc->y() < MyRes::y_offset && vlc->y() > 0) ||
	    ((bttmrght.y() + vlc->y() > vw_rct.height() - MyRes::y_offset) && vlc->y() < 0))
		setPos(pos().x(), pos().y() + vlc->y());
	cnstrct_shldpxmp();
}

void MyShip::updt(QSet<int> *prsd_kys) {
	setPos(pos().x() + MyRes::vw_mvmnt, pos().y());
	cllsn_dtctn();
	updt_vlc(prsd_kys);
	updt_rtn();
	updt_pos();
}
