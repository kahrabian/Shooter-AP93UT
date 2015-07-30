//
// Created by kahrabian on 7/12/15.
//

#include <Sources/Headers/Widgets/MyGame.h>

MyGame::MyGame(QWidget *parent) :
		QGraphicsView(parent) {
	resize(MyRes::app_size);
	fast = false;
	cur_stg = 0;
	prsd_kys = new QSet<int>();

	gscn = new QGraphicsScene();
	gscn->setSceneRect(MyRes::scn_rct);
	gscn->setBackgroundBrush(
			QBrush(QImage(MyRes::env_adds[SettingData::env]).scaled(MyRes::tl_size, Qt::KeepAspectRatio,
			                                                        Qt::SmoothTransformation)));
	for (int i = 0; i < MyRes::stg_cnt; i++) {
		QGraphicsPixmapItem *stg = new QGraphicsPixmapItem(
				QPixmap(MyRes::stg_add[i]).scaled(MyRes::stg_size, Qt::IgnoreAspectRatio,
				                                  Qt::SmoothTransformation));
		stg->setPos(i * (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()), 0);
		gscn->addItem(stg);
	}

	restart();
	tmr_id = startTimer(MyRes::frm_dly);
}

MyGame::~MyGame() {
	killTimer(tmr_id);
	clean();
	delete prsd_kys;
	delete gscn;
}

void MyGame::clean() {
	QList<QGraphicsItem *> itms = scene()->items();
			foreach(QGraphicsItem *i, itms) {
			if (dynamic_cast<MyAlien *>(i)) {
				dynamic_cast<MyAlien *>(i)->killTimer(dynamic_cast<MyAlien *>(i)->getTmr_id());
				scene()->removeItem(i);
				MyAlien *tmp = dynamic_cast<MyAlien *>(i);
				delete tmp;
			}
			else if (dynamic_cast<MyAlienBoss *>(i)) {
				scene()->removeItem(i);
				MyAlienBoss *tmp = dynamic_cast<MyAlienBoss *>(i);
				delete tmp;
			}
			else if (dynamic_cast<MyAsteroid *>(i)) {
				scene()->removeItem(i);
				MyAsteroid *tmp = dynamic_cast<MyAsteroid *>(i);
				delete tmp;
			}
			else if (dynamic_cast<MyBullet *>(i)) {
				scene()->removeItem(i);
				MyBullet *tmp = dynamic_cast<MyBullet *>(i);
				delete tmp;
			}
			else if (dynamic_cast<MyExplosion *>(i)) {
				scene()->removeItem(i);
				MyExplosion *tmp = dynamic_cast<MyExplosion *>(i);
				delete tmp;
			}
			else if (dynamic_cast<MyLife *>(i)) {
				scene()->removeItem(i);
				MyLife *tmp = dynamic_cast<MyLife *>(i);
				delete tmp;
			}
			else if (dynamic_cast<MyMagic *>(i)) {
				scene()->removeItem(i);
				MyMagic *tmp = dynamic_cast<MyMagic *>(i);
				delete tmp;
			}
			else if (dynamic_cast<MyShield *>(i)) {
				scene()->removeItem(i);
				MyShield *tmp = dynamic_cast<MyShield *>(i);
				delete tmp;
			}
			else if (dynamic_cast<MyShip *>(i)) {
				scene()->removeItem(i);
				MyShip *tmp = dynamic_cast<MyShip *>(i);
				delete tmp;
			}
			else if (dynamic_cast<MyShipShield *>(i)) {
				scene()->removeItem(i);
				MyShipShield *tmp = dynamic_cast<MyShipShield *>(i);
				delete tmp;
			}
			else if (dynamic_cast<MyStar *>(i)) {
				scene()->removeItem(i);
				MyStar *tmp = dynamic_cast<MyStar *>(i);
				delete tmp;
			}
			else if (dynamic_cast<QGraphicsTextItem *>(i)) {
				scene()->removeItem(i);
				QGraphicsTextItem *tmp = dynamic_cast<QGraphicsTextItem *>(i);
				delete tmp;
			}
		}
}

void MyGame::restart() {
	QFile file(MyRes::stng_add);
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	QString tmp;
	stream >> tmp;
	file.close();

	if (tmp == "0") {
		bld_stg1();
		bld_stg2();
		bld_stg3();
		bld_bss();
	}
}

void MyGame::change_speed() {
	fast = !fast;
	killTimer(tmr_id);
	if (fast)
		tmr_id = startTimer(MyRes::frm_dly / MyRes::fst_vlc);
	else
		tmr_id = startTimer(MyRes::frm_dly);
	QList<QGraphicsItem *> items = scene()->items();
			foreach(QGraphicsItem *i, items) {
			if (dynamic_cast<MyAlien *>(i)) {
				dynamic_cast<MyAlien *>(i)->change_speed();
			}
			if (dynamic_cast<MyShip *>(i)) {
				dynamic_cast<MyShip *>(i)->change_speed();
			}
		}
}

void MyGame::pause() {
	killTimer(tmr_id);
	QList<QGraphicsItem *> items = scene()->items();
			foreach(QGraphicsItem *i, items) {
			if (dynamic_cast<MyAlien *>(i)) {
				dynamic_cast<MyAlien *>(i)->game_paused();
			}
			if (dynamic_cast<MyShip *>(i)) {
				dynamic_cast<MyShip *>(i)->game_paused();
			}
		}
	emit gamePaused();
}

void MyGame::unpause() {
	if (fast)
		tmr_id = startTimer(MyRes::frm_dly / MyRes::fst_vlc);
	else
		tmr_id = startTimer(MyRes::frm_dly);
	QList<QGraphicsItem *> items = scene()->items();
			foreach(QGraphicsItem *i, items) {
			if (dynamic_cast<MyAlien *>(i)) {
				dynamic_cast<MyAlien *>(i)->game_unpaused();
			}
			if (dynamic_cast<MyShip *>(i)) {
				dynamic_cast<MyShip *>(i)->game_unpaused();
			}
		}
	prsd_kys->clear();
}

void MyGame::bld_stg1() {
	setScene(gscn);
	setSceneRect(viewport()->frameGeometry());
	shp1 = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]), new QString("1"));
	scene()->addItem(shp1);
	scene()->addItem(shp1->shpshld);
	shp1->scr_txt->setPos(size().width() - shp1->scr_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
	                      MyRes::txtitem_y_crrctn);
	shp1->lf_txt->setPos(size().width() - shp1->lf_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
	                     MyRes::txtitem_y_crrctn + shp1->scr_txt->boundingRect().height());
	scene()->addItem(shp1->scr_txt);
	scene()->addItem(shp1->lf_txt);

	if (SettingData::gMode != 1) {
		if (SettingData::gMode == 2) {
			shp2 = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]), new QString("2"));
		}
		else {
			shp2 = new MyShip(QPixmap(MyRes::shp_adds[SettingData::aiShp]), new QString("ai"));
		}
		scene()->addItem(shp2);
		scene()->addItem(shp2->shpshld);
		shp2->scr_txt->setPos(size().width() - shp2->scr_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
		                      size().height() - shp2->scr_txt->boundingRect().height() - MyRes::txtitem_y_crrctn);
		shp2->lf_txt->setPos(size().width() - shp2->lf_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
		                     size().height() - shp2->scr_txt->boundingRect().height() -
		                     shp2->lf_txt->boundingRect().height() -
		                     MyRes::txtitem_y_crrctn);
		scene()->addItem(shp2->scr_txt);
		scene()->addItem(shp2->lf_txt);
	}
	for (int i = 0; i < MyRes::stg_astrd[0][SettingData::gDiff - 1]; i++) {
		MyAsteroid *astrd = new MyAsteroid(1);
		astrd->setPos(MyRes::app_size.width() +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(astrd);
	}
	for (int i = 0; i < MyRes::stg_lf; i++) {
		MyLife *lf = new MyLife();
		lf->setPos(MyRes::app_size.width() +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(lf);
	}
	for (int i = 0; i < MyRes::stg_shld[SettingData::gDiff - 1]; i++) {
		MyShield *shld = new MyShield();
		shld->setPos(MyRes::app_size.width() +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(shld);
	}
	for (int i = 0; i < MyRes::stg_mgc[SettingData::gDiff - 1]; i++) {
		MyMagic *mgc = new MyMagic();
		mgc->setPos(MyRes::app_size.width() +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(mgc);
	}
	for (int i = 0; i < MyRes::stg_str; i++) {
		MyStar *str = new MyStar();
		str->setPos(MyRes::app_size.width() +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(str);
	}
}

void MyGame::bld_stg2() {
	for (int i = 0; i < MyRes::stg_aln_bg[1][SettingData::gDiff - 1]; i++) {
		MyAlien *tmp = new MyAlien(1);
		tmp->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
	for (int i = 0; i < MyRes::stg_aln_smll[1][SettingData::gDiff - 1]; i++) {
		MyAlien *tmp = new MyAlien(2);
		tmp->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
	for (int i = 0; i < MyRes::stg_lf; i++) {
		MyLife *tmp = new MyLife();
		tmp->setPos(MyRes::app_size.width() +
				            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
	for (int i = 0; i < MyRes::stg_shld[SettingData::gDiff - 1]; i++) {
		MyShield *tmp = new MyShield();
		tmp->setPos(MyRes::app_size.width() +
				            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
	for (int i = 0; i < MyRes::stg_mgc[SettingData::gDiff - 1]; i++) {
		MyMagic *tmp = new MyMagic();
		tmp->setPos(MyRes::app_size.width() +
				            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
	for (int i = 0; i < MyRes::stg_str; i++) {
		MyStar *tmp = new MyStar();
		tmp->setPos(MyRes::app_size.width() +
				            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
}

void MyGame::bld_stg3() {
	for (int i = 0; i < MyRes::stg_astrd[2][SettingData::gDiff - 1]; i++) {
		MyAsteroid *tmp = new MyAsteroid(2);
		tmp->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
	for (int i = 0; i < MyRes::stg_aln_bg[2][SettingData::gDiff - 1]; i++) {
		MyAlien *tmp = new MyAlien(3);
		tmp->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
	for (int i = 0; i < MyRes::stg_aln_smll[2][SettingData::gDiff - 1]; i++) {
		MyAlien *tmp = new MyAlien(4);
		tmp->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
	for (int i = 0; i < MyRes::stg_lf; i++) {
		MyLife *tmp = new MyLife();
		tmp->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
	for (int i = 0; i < MyRes::stg_shld[SettingData::gDiff - 1]; i++) {
		MyShield *tmp = new MyShield();
		tmp->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
	for (int i = 0; i < MyRes::stg_mgc[SettingData::gDiff - 1]; i++) {
		MyMagic *tmp = new MyMagic();
		tmp->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
	for (int i = 0; i < MyRes::stg_str; i++) {
		MyStar *tmp = new MyStar();
		tmp->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
				            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(tmp);
	}
}

void MyGame::bld_bss() {
	MyAlienBoss *bss = new MyAlienBoss(4, -1, -1);
	bss->setPos(
			MyRes::stg_cnt * (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
					MyRes::bss_offset, rand() % (viewport()->height() - bss->pixmap().height()));
	scene()->addItem(bss);
}

void MyGame::keyPressEvent(QKeyEvent *event) {
	prsd_kys->insert(event->key());
	if (event->key() == Qt::Key_Escape) {
		pause();
	}
	if (event->key() == Qt::Key_F) {
		change_speed();
	}
}

void MyGame::keyReleaseEvent(QKeyEvent *event) {
	prsd_kys->remove(event->key());
}

void MyGame::timerEvent(QTimerEvent *event) {
	setSceneRect(sceneRect().x() + MyRes::vw_mvmnt, 0, viewport()->frameGeometry().width(),
	             viewport()->frameGeometry().height());
	QList<QGraphicsItem *> itms = scene()->items();
	if (sceneRect().x() >
	    MyRes::stg_cnt * (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) -
	    MyRes::app_size.width()) {
		if (SettingData::gMode == 3) {
			if (shp1->scr > shp2->scr) {
				emit gameEnded(1);
			}
			else if (shp1->scr < shp2->scr) {
				emit gameEnded(2);
			}
			else {
				if (shp1->lf > shp2->lf) {
					emit gameEnded(1);
				}
				else if (shp1->lf < shp2->lf) {
					emit gameEnded(2);
				}
				else {
					emit gameEnded(3);
				}
			}
		}
		else {
			bool f = false;
					foreach(QGraphicsItem *i, itms) {
					if (dynamic_cast<MyAlienBoss *>(i)) {
						f = true;
					}
				}
			if (!f) {
				if (SettingData::gMode == 2) {
					emit gameEnded(4);
				}
				else {
					emit gameEnded(1);
				}
				return;
			}
		}
	}
	if (SettingData::gMode == 2) {
		bool f = false;
				foreach(QGraphicsItem *i, itms) {
				if (dynamic_cast<MyShip *>(i)) {
					f = true;
				}
			}
		if (!f) {
			emit gameEnded(0);
			return;
		}
	}
	foreach(QGraphicsItem *i, itms) {
			if (sceneRect().right() < i->sceneBoundingRect().left())
				continue;
			if (dynamic_cast<MyAlien *>(i)) {
				dynamic_cast<MyAlien *>(i)->updt();
				if (!dynamic_cast<MyAlien *>(i)->isVisible() ||
				    dynamic_cast<MyAlien *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyAlien *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyAlien *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					dynamic_cast<MyAlien *>(i)->killTimer(dynamic_cast<MyAlien *>(i)->getTmr_id());
					scene()->removeItem(i);
					MyAlien *tmp = dynamic_cast<MyAlien *>(i);
					delete tmp;
				}
			}
			else if (dynamic_cast<MyAlienBoss *>(i)) {
				dynamic_cast<MyAlienBoss *>(i)->updt();
				if (!dynamic_cast<MyAlienBoss *>(i)->isVisible() ||
				    dynamic_cast<MyAlienBoss *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyAlienBoss *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyAlienBoss *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyAlienBoss *tmp = dynamic_cast<MyAlienBoss *>(i);
					delete tmp;
				}
			}
			else if (dynamic_cast<MyAsteroid *>(i)) {
				dynamic_cast<MyAsteroid *>(i)->updt();
				if (!dynamic_cast<MyAsteroid *>(i)->isVisible() ||
				    dynamic_cast<MyAsteroid *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyAsteroid *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyAsteroid *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyAsteroid *tmp = dynamic_cast<MyAsteroid *>(i);
					delete tmp;
				}
			}
			else if (dynamic_cast<MyBullet *>(i)) {
				dynamic_cast<MyBullet *>(i)->updt();
				if (!dynamic_cast<MyBullet *>(i)->isVisible() ||
				    dynamic_cast<MyBullet *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyBullet *>(i)->sceneBoundingRect().left() > sceneRect().right() ||
				    dynamic_cast<MyBullet *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyBullet *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyBullet *tmp = dynamic_cast<MyBullet *>(i);
					delete tmp;
				}
			}
			else if (dynamic_cast<MyExplosion *>(i)) {
				dynamic_cast<MyExplosion *>(i)->updt();
				if (!dynamic_cast<MyExplosion *>(i)->isVisible() ||
				    dynamic_cast<MyExplosion *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyExplosion *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyExplosion *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyExplosion *tmp = dynamic_cast<MyExplosion *>(i);
					delete tmp;
				}
			}
			else if (dynamic_cast<MyLife *>(i)) {
				dynamic_cast<MyLife *>(i)->updt();
				if (!dynamic_cast<MyLife *>(i)->isVisible() ||
				    dynamic_cast<MyLife *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyLife *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyLife *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyLife *tmp = dynamic_cast<MyLife *>(i);
					delete tmp;
				}
			}
			else if (dynamic_cast<MyMagic *>(i)) {
				dynamic_cast<MyMagic *>(i)->updt();
				if (!dynamic_cast<MyMagic *>(i)->isVisible() ||
				    dynamic_cast<MyMagic *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyMagic *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyMagic *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyMagic *tmp = dynamic_cast<MyMagic *>(i);
					delete tmp;
				}
			}
			else if (dynamic_cast<MyShield *>(i)) {
				dynamic_cast<MyShield *>(i)->updt();
				if (!dynamic_cast<MyShield *>(i)->isVisible() ||
				    dynamic_cast<MyShield *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyShield *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyShield *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyShield *tmp = dynamic_cast<MyShield *>(i);
					delete tmp;
				}
			}
			else if (dynamic_cast<MyShip *>(i)) {
				dynamic_cast<MyShip *>(i)->updt(prsd_kys);
				if (!dynamic_cast<MyShip *>(i)->isVisible()) {
					scene()->removeItem(dynamic_cast<MyShip *>(i)->shpshld);
					scene()->removeItem(dynamic_cast<MyShip *>(i)->scr_txt);
					scene()->removeItem(dynamic_cast<MyShip *>(i)->lf_txt);
					scene()->removeItem(i);
					if (dynamic_cast<MyShip *>(i)->name->compare("1") == 0) {
						if (SettingData::gMode == 1) {
							emit gameEnded(0);
							return;
						}
						else if (SettingData::gMode == 3) {
							emit gameEnded(2);
							return;
						}
					}
					else if (SettingData::gMode == 3) {
						emit gameEnded(1);
						return;
					}
					MyShip *tmp = dynamic_cast<MyShip *>(i);
					delete tmp;
				}
			}
			else if (dynamic_cast<MyShipShield *>(i)) {
				dynamic_cast<MyShipShield *>(i)->updt();
			}
			else if (dynamic_cast<MyStar *>(i)) {
				dynamic_cast<MyStar *>(i)->updt();
				if (!dynamic_cast<MyStar *>(i)->isVisible() ||
				    dynamic_cast<MyStar *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyStar *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyStar *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyStar *tmp = dynamic_cast<MyStar *>(i);
					delete tmp;
				}
			}
		}
}