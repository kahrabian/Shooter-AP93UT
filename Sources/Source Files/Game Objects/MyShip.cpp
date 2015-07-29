//
// Created by kahrabian on 7/12/15.
//

#include <Sources/Headers/Game Objects/MyShip.h>

MyShip::MyShip(const QPixmap &pixmap, QString *name) :
		QGraphicsPixmapItem(pixmap.scaled(MyRes::shp_size, Qt::KeepAspectRatio,
		                                  Qt::SmoothTransformation)), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	if (*name == "1") {
		setPos(MyRes::x_offset, MyRes::y_offset);
	}
	else {
		setPos(MyRes::x_offset, MyRes::app_size.height() - MyRes::shp_size.height() - MyRes::y_offset);
	}
	MyShip::name = name;
	fast = false;
	rtn = 0;
	lf = MyRes::shp_lf;
	scr = 0;
	lsr = true;
	mgc = false;

	vlc = new QPointF(0, 0);

	shpshld = new MyShipShield();
	shpshld->setGraphicsEffect(new QGraphicsDropShadowEffect());

	shld_tmr = new QTimer();
	shld_tmr_elpsd = 0;
	mgc_tmr = new QTimer();
	mgc_tmr_elpsd = 0;

	lsr_tmr = new QTimer();
	lsr_tmr_elpsd = 0;
	lsr_tmr->start(MyRes::shp_lsrdly);

	if (*MyShip::name == "1") {
		scr_txt = new QGraphicsTextItem(SettingData::p1_nm + " Score: " + QString::number(scr));
		scr_txt->setFont(MyRes::txt_font);
		lf_txt = new QGraphicsTextItem(SettingData::p1_nm + " Life: " + QString::number(lf));
		lf_txt->setFont(MyRes::txt_font);
	}
	else {
		scr_txt = new QGraphicsTextItem(SettingData::p2_nm + " Score: " + QString::number(scr));
		scr_txt->setFont(MyRes::txt_font);
		lf_txt = new QGraphicsTextItem(SettingData::p2_nm + " Life: " + QString::number(lf));
		lf_txt->setFont(MyRes::txt_font);
	}

	QTimer::connect(shld_tmr, SIGNAL(timeout()), this, SLOT(deactivate_shld()));
	QTimer::connect(shpshld, SIGNAL(shieldDestroyd()), this, SLOT(deactivate_shld()));
	QTimer::connect(mgc_tmr, SIGNAL(timeout()), this, SLOT(deactivate_mgc()));
	QTimer::connect(lsr_tmr, SIGNAL(timeout()), this, SLOT(activate_lsr()));

	deactivate_shld();
	deactivate_mgc();
}

MyShip::~MyShip() {
	delete name;
	delete mgc_tmr;
	delete lsr_tmr;
	delete vlc;
}

void MyShip::cnstrct_shldpxmp() {
	shpshld->setPos(pos().x() + (pixmap().width() / 2) - (shpshld->pixmap().width() / 2),
	                pos().y() + (pixmap().height() / 2) - (shpshld->pixmap().height() / 2));
}

void MyShip::activate_shld() {
	shpshld->show();
	if (fast) {
		shld_tmr->start(MyRes::spcl_tm / 4);
	}
	else {
		shld_tmr->start(MyRes::spcl_tm);
	}
}

void MyShip::deactivate_shld() {
	shpshld->hide();
	shld_tmr->stop();
}

void MyShip::activate_mgc() {
	mgc = true;
	if (fast) {
		mgc_tmr->start(MyRes::spcl_tm / 4);
	}
	else {
		mgc_tmr->start(MyRes::spcl_tm);
	}
}

void MyShip::deactivate_mgc() {
	mgc = false;
	mgc_tmr->stop();
}

void MyShip::activate_lsr() {
	lsr = true;
}

void MyShip::deactivate_lsr() {
	lsr = false;
	if (fast) {
		lsr_tmr->start(MyRes::shp_lsrdly / 4);
	}
	else {
		lsr_tmr->start(MyRes::shp_lsrdly);
	}
}

void MyShip::scrIncrement() {
	scr++;
}

void MyShip::ply_sf(QString &add) {
	if (!SettingData::sfMut) {
		QSoundEffect *sf = new QSoundEffect();
		sf->setSource(QUrl::fromLocalFile(add));
		sf->setVolume(SettingData::sfVol / 100.0);
		sf->play();
	}
}

void MyShip::change_speed() {
	fast = !fast;
	if (fast) {
		if (shld_tmr->isActive()) {
			shld_tmr->start(shld_tmr->remainingTime() / 4);
		}
		if (mgc_tmr->isActive()) {
			mgc_tmr->start(mgc_tmr->remainingTime() / 4);
		}
		if (lsr_tmr->isActive()) {
			lsr_tmr->start(lsr_tmr->remainingTime() / 4);
		}
	}
	else {
		if (shld_tmr->isActive()) {
			shld_tmr->start(shld_tmr->remainingTime() * 4);
		}
		if (mgc_tmr->isActive()) {
			mgc_tmr->start(mgc_tmr->remainingTime() * 4);
		}
		if (lsr_tmr->isActive()) {
			lsr_tmr->start(lsr_tmr->remainingTime() * 4);
		}
	}
}

void MyShip::game_paused() {
	if (shld_tmr->isActive()) {
		shld_tmr_elpsd = shld_tmr->remainingTime();
		shld_tmr->stop();
	}
	if (mgc_tmr->isActive()) {
		mgc_tmr_elpsd = mgc_tmr->remainingTime();
		mgc_tmr->stop();
	}
	if (lsr_tmr->isActive()) {
		lsr_tmr_elpsd = lsr_tmr->remainingTime();
		lsr_tmr->stop();
	}
}

void MyShip::game_unpaused() {
	if (shld_tmr_elpsd > 0) {
		shld_tmr->start(shld_tmr_elpsd);
	}
	if (mgc_tmr_elpsd > 0) {
		mgc_tmr->start(mgc_tmr_elpsd);
	}
	if (lsr_tmr_elpsd > 0) {
		lsr_tmr->start(lsr_tmr_elpsd);
	}
	else if (lsr_tmr_elpsd == 0) {
		if (fast) {
			lsr_tmr->start(MyRes::shp_lsrdly / 4);
		}
		else {
			lsr_tmr->start(MyRes::shp_lsrdly);
		}
		activate_lsr();
	}
}

void MyShip::cllsn_dtctn() {
	QList<QGraphicsItem *> clldng_items = collidingItems(Qt::ItemSelectionMode::IntersectsItemShape);
			foreach(QGraphicsItem *i, clldng_items) {
			if (dynamic_cast<MyLife *>(i) && dynamic_cast<MyLife *>(i)->isVisible()) {
				ply_sf(const_cast<QString &>(MyRes::sf_lf_add));
				lf++;
				dynamic_cast<MyLife *>(i)->hide();
			}
			else if (dynamic_cast<MyMagic *>(i) && dynamic_cast<MyMagic *>(i)->isVisible()) {
				ply_sf(const_cast<QString &>(MyRes::sf_mgc_add));
				activate_mgc();
				dynamic_cast<MyMagic *>(i)->hide();
			}
			else if (dynamic_cast<MyShield *>(i) && dynamic_cast<MyShield *>(i)->isVisible()) {
				ply_sf(const_cast<QString &>(MyRes::sf_shld_add));
				activate_shld();
				dynamic_cast<MyShield *>(i)->hide();
			}
			else if (dynamic_cast<MyShip *>(i) && dynamic_cast<MyShip *>(i)->isVisible()) {
				ply_sf(const_cast<QString &>(MyRes::sf_shp_shp_add));
				lf--;
			}
			else if (dynamic_cast<MyShipShield *>(i) && dynamic_cast<MyShipShield *>(i)->isVisible() &&
			         dynamic_cast<MyShipShield *>(i) != shpshld) {
				ply_sf(const_cast<QString &>(MyRes::sf_expln_shpshld_add));
				lf--;
				dynamic_cast<MyShipShield *>(i)->dstry();
			}
			else if (dynamic_cast<MyStar *>(i) && dynamic_cast<MyStar *>(i)->isVisible()) {
				ply_sf(const_cast<QString &>(MyRes::sf_str_add));
				scr++;
				dynamic_cast<MyStar *>(i)->hide();
			}
			else if (dynamic_cast<MyAlien *>(i) && dynamic_cast<MyAlien *>(i)->isVisible()) {
				if (dynamic_cast<MyAlien *>(i)->getTyp() == 0) {
					ply_sf(const_cast<QString &>(MyRes::sf_expln_aln_bg_add));
					MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_aln_bg_size));
					expln->setPos(dynamic_cast<MyAlien *>(i)->x() + (dynamic_cast<MyAlien *>(i)->pixmap().width() / 2) -
					              (MyRes::expln_aln_bg_size.width() / 2), dynamic_cast<MyAlien *>(i)->y() +
					                                                      (dynamic_cast<MyAlien *>(i)->pixmap().height() /
					                                                       2) -
					                                                      (MyRes::expln_aln_bg_size.height() / 2) +
							MyRes::expln_aln_bg_crrctn);
					scene()->addItem(expln);
				}
				else {
					ply_sf(const_cast<QString &>(MyRes::sf_expln_aln_smll_add));
					MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_aln_smll_size));
					expln->setPos(dynamic_cast<MyAlien *>(i)->x() + (dynamic_cast<MyAlien *>(i)->pixmap().width() / 2) -
					              (MyRes::expln_aln_smll_size.width() / 2), dynamic_cast<MyAlien *>(i)->y() +
					                                                        (dynamic_cast<MyAlien *>(i)->pixmap().height() /
					                                                         2) -
					                                                        (MyRes::expln_aln_smll_size.height() / 2) +
					                                                        MyRes::expln_aln_smll_crrctn);
					scene()->addItem(expln);
				}
				lf--;
				dynamic_cast<MyAlien *>(i)->killTimer(dynamic_cast<MyAlien *>(i)->getTmr_id());
				dynamic_cast<MyAlien *>(i)->hide();
			}
			else if (dynamic_cast<MyAlienBoss *>(i) && dynamic_cast<MyAlienBoss *>(i)->isVisible()) {
				ply_sf(const_cast<QString &>(MyRes::sf_expln_astrd_add));
				if (dynamic_cast<MyAlienBoss *>(i)->getStg() == 0) {
					MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_astrd_size));
					expln->setPos(
							dynamic_cast<MyAlienBoss *>(i)->x() +
							(dynamic_cast<MyAlienBoss *>(i)->pixmap().width() / 2) -
							(MyRes::expln_astrd_size.width() / 2),
							dynamic_cast<MyAlienBoss *>(i)->y() +
							(dynamic_cast<MyAlienBoss *>(i)->pixmap().height() / 2) -
							(MyRes::expln_astrd_size.height() / 2) + MyRes::expln_astrd_crrctn);
					expln->updt();
					scene()->addItem(expln);
				}
				lf--;
				dynamic_cast<MyAlienBoss *>(i)->hide();

				if (dynamic_cast<MyAlienBoss *>(i)->getStg() != 0) {
					for (int j = 0; j < 2; j++) {
						MyAlienBoss *bss = new MyAlienBoss(dynamic_cast<MyAlienBoss *>(i)->getStg() - 1);
						bss->setPos(dynamic_cast<MyAlienBoss *>(i)->pos());
						scene()->addItem(bss);
					}
				}
			}
			else if (dynamic_cast<MyAsteroid *>(i) && dynamic_cast<MyAsteroid *>(i)->isVisible()) {
				ply_sf(const_cast<QString &>(MyRes::sf_expln_astrd_add));
				MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_astrd_size));
				expln->setPos(
						dynamic_cast<MyAsteroid *>(i)->x() + (dynamic_cast<MyAsteroid *>(i)->pixmap().width() / 2) -
						(MyRes::expln_astrd_size.width() / 2),
						dynamic_cast<MyAsteroid *>(i)->y() + (dynamic_cast<MyAsteroid *>(i)->pixmap().height() / 2) -
						(MyRes::expln_astrd_size.height() / 2) + MyRes::expln_astrd_crrctn);
				expln->updt();
				scene()->addItem(expln);
				lf--;
				dynamic_cast<MyAsteroid *>(i)->hide();
			}
			else if (dynamic_cast<MyBullet *>(i) && dynamic_cast<MyBullet *>(i)->isVisible()) {
				ply_sf(const_cast<QString &>(MyRes::sf_expln_lsr_add));
				MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_lsr_size));
				expln->setPos(dynamic_cast<MyBullet *>(i)->x() + (dynamic_cast<MyBullet *>(i)->pixmap().width() / 2) -
				              (MyRes::expln_lsr_size.width() / 2),
				              dynamic_cast<MyBullet *>(i)->y() + (dynamic_cast<MyBullet *>(i)->pixmap().height() / 2) -
				              (MyRes::expln_lsr_size.height() / 2) + MyRes::expln_lsr_crrctn);
				expln->updt();
				scene()->addItem(expln);
				lf--;
				dynamic_cast<MyBullet *>(i)->hide();
			}
		}
}

void MyShip::updt_txt() {
	if (*MyShip::name == "1") {
		scr_txt->setPlainText(SettingData::p1_nm + " Score: " + QString::number(scr));
	}
	else {
		scr_txt->setPlainText(SettingData::p2_nm + " Score: " + QString::number(scr));
	}
	if (*MyShip::name == "1") {
		lf_txt->setPlainText(SettingData::p1_nm + " Life: " + QString::number(lf));
	}
	else {
		lf_txt->setPlainText(SettingData::p2_nm + " Life: " + QString::number(lf));
	}
	if (name->compare("1") == 0) {
		scr_txt->setPos(scene()->views().first()->mapToScene(0, 0).x() + scene()->views().first()->size().width() -
		                scr_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
		                MyRes::txtitem_y_crrctn);
		lf_txt->setPos(scene()->views().first()->mapToScene(0, 0).x() + scene()->views().first()->size().width() -
		               lf_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
		               MyRes::txtitem_y_crrctn + scr_txt->boundingRect().height());
	}
	else {
		scr_txt->setPos(
				scene()->views().first()->mapToScene(0, 0).x() + scene()->views().first()->size().width() -
				scr_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
				scene()->views().first()->size().height() - scr_txt->boundingRect().height() - MyRes::txtitem_y_crrctn);
		lf_txt->setPos(
				scene()->views().first()->mapToScene(0, 0).x() + scene()->views().first()->size().width() -
				lf_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
				scene()->views().first()->size().height() - scr_txt->boundingRect().height() -
				lf_txt->boundingRect().height() -
				MyRes::txtitem_y_crrctn);
	}
}

void MyShip::updt_vlc(QSet<int> *prsd_kys) {
	vlc->setY(0);
	vlc->setX(0);

	if (prsd_kys->find(Qt::Key_Up) != prsd_kys->end() && name->compare("1") == 0) {
		vlc->setY(vlc->y() - MyRes::shp_mvmnt);
	}
	if (prsd_kys->find(Qt::Key_Down) != prsd_kys->end() && name->compare("1") == 0) {
		vlc->setY(vlc->y() + MyRes::shp_mvmnt);
	}
	if (prsd_kys->find(Qt::Key_Left) != prsd_kys->end() && name->compare("1") == 0) {
		vlc->setX(vlc->x() - MyRes::shp_mvmnt);
	}
	if (prsd_kys->find(Qt::Key_Right) != prsd_kys->end() && name->compare("1") == 0) {
		vlc->setX(vlc->x() + MyRes::shp_mvmnt);
	}
	if (prsd_kys->find(Qt::Key_Space) != prsd_kys->end() && name->compare("1") == 0 && lsr) {
		ply_sf(const_cast<QString &>(MyRes::sf_shp_lsr_add));
		if (!mgc) {
			MyBullet *lsr = new MyBullet(0);
			lsr->setPos(pos().x() + pixmap().width(),
			            pos().y() + (pixmap().height() / 2) - (MyRes::lsr_size.height() / 2));
			scene()->addItem(lsr);
			QObject::connect(lsr, SIGNAL(scrGained()), this, SLOT(scrIncrement()));
		}
		else {
			for (int i = -MyRes::lsr_rtn_max; i <= MyRes::lsr_rtn_max; i += MyRes::lsr_rtn_stp) {
				MyBullet *lsr = new MyBullet(0, i);
				lsr->setPos(pos().x() + pixmap().width(),
				            pos().y() + (pixmap().height() / 2) - (MyRes::lsr_size.height() / 2));
				scene()->addItem(lsr);
				QObject::connect(lsr, SIGNAL(scrGained()), this, SLOT(scrIncrement()));
			}
		}
		deactivate_lsr();
	}

	if (prsd_kys->find(Qt::Key_W) != prsd_kys->end() && name->compare("1") != 0) {
		vlc->setY(vlc->y() - MyRes::shp_mvmnt);
	}
	if (prsd_kys->find(Qt::Key_S) != prsd_kys->end() && name->compare("1") != 0) {
		vlc->setY(vlc->y() + MyRes::shp_mvmnt);
	}
	if (prsd_kys->find(Qt::Key_A) != prsd_kys->end() && name->compare("1") != 0) {
		vlc->setX(vlc->x() - MyRes::shp_mvmnt);
	}
	if (prsd_kys->find(Qt::Key_D) != prsd_kys->end() && name->compare("1") != 0) {
		vlc->setX(vlc->x() + MyRes::shp_mvmnt);
	}
	if (prsd_kys->find(Qt::Key_X) != prsd_kys->end() && name->compare("1") != 0 && lsr) {
		ply_sf(const_cast<QString &>(MyRes::sf_shp_lsr_add));
		if (!mgc) {
			MyBullet *lsr = new MyBullet(0);
			lsr->setPos(pos().x() + pixmap().width(),
			            pos().y() + (pixmap().height() / 2) - (MyRes::lsr_size.height() / 2));
			scene()->addItem(lsr);
			QObject::connect(lsr, SIGNAL(scrGained()), this, SLOT(scrIncrement()));
		}
		else {
			for (int i = -MyRes::lsr_rtn_max; i <= MyRes::lsr_rtn_max; i += MyRes::lsr_rtn_stp) {
				MyBullet *lsr = new MyBullet(0, i);
				lsr->setPos(pos().x() + pixmap().width(),
				            pos().y() + (pixmap().height() / 2) - (MyRes::lsr_size.height() / 2));
				scene()->addItem(lsr);
				QObject::connect(lsr, SIGNAL(scrGained()), this, SLOT(scrIncrement()));
			}
		}
		deactivate_lsr();
	}
}

void MyShip::updt_rtn() {
	if (vlc->y() > 0 && rtn < MyRes::rtn_max) {
		rtn += MyRes::rtn_stp;
	}
	else if (vlc->y() < 0 && rtn > -MyRes::rtn_max) {
		rtn -= MyRes::rtn_stp;
	}
	else if (vlc->y() == 0 && rtn < 0) {
		rtn += MyRes::rtn_stp;
	}
	else if (vlc->y() == 0 && rtn > 0) {
		rtn -= MyRes::rtn_stp;
	}
}

void MyShip::updt_pos() {
	setPos(pos().x() + MyRes::vw_mvmnt, pos().y());
	setTransform(QTransform().translate(pixmap().size().width() / 2, pixmap().size().height() / 2).rotate(-rtn,
	                                                                                                      Qt::XAxis).translate(
			-pixmap().size().width() / 2, -pixmap().size().height() / 2));

	QPointF tplft(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().topLeft()))));
	QPointF bttmrght(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().bottomRight()))));
	QRectF vw_rct(scene()->views().first()->viewport()->rect());

	if (tplft.x() + vlc->x() >= MyRes::x_offset && bttmrght.x() + vlc->x() <= vw_rct.width() - MyRes::x_offset) {
		setPos(pos().x() + vlc->x(), pos().y());
	}
	if ((tplft.y() + vlc->y() >= MyRes::y_offset && bttmrght.y() + vlc->y() <= vw_rct.height() - MyRes::y_offset) ||
	    (tplft.y() + vlc->y() < MyRes::y_offset && vlc->y() > 0) ||
			((bttmrght.y() + vlc->y() > vw_rct.height() - MyRes::y_offset) && vlc->y() < 0)) {
		setPos(pos().x(), pos().y() + vlc->y());
	}
	cnstrct_shldpxmp();
}

void MyShip::updt(QSet<int> *prsd_kys) {
	cllsn_dtctn();
	updt_vlc(prsd_kys);
	updt_rtn();
	updt_pos();
	updt_txt();
	if (lf < 0)
		hide();
}