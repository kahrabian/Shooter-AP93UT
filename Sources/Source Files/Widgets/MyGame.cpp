//
// Created by kahrabian on 7/12/15.
//

#include <Sources/Headers/Widgets/MyGame.h>

MyGame::MyGame(QWidget *parent) :
		QGraphicsView(parent) {
	resize(MyRes::app_size);
	fast = false;
	prsd_kys = new QSet<int>();

	restart();
	tmr_id = startTimer(MyRes::frm_dly);
}

MyGame::~MyGame() {
	killTimer(tmr_id);
	clean();
	if (SettingData::gMode == 3) {
		delete shp2_ai;
	}
	delete prsd_kys;
	delete gscn;
}

void MyGame::clean() {
	QList<QGraphicsItem *> itms = scene()->items();
			foreach(QGraphicsItem *i, itms) {
			if (dynamic_cast<MyAlien *>(i)) {
				dynamic_cast<MyAlien *>(i)->killTimer(dynamic_cast<MyAlien *>(i)->getTmr_id());
				scene()->removeItem(i);
				MyAlien *aln = dynamic_cast<MyAlien *>(i);
				delete aln;
			}
			else if (dynamic_cast<MyAlienBoss *>(i)) {
				scene()->removeItem(i);
				MyAlienBoss *bss = dynamic_cast<MyAlienBoss *>(i);
				delete bss;
			}
			else if (dynamic_cast<MyAsteroid *>(i)) {
				scene()->removeItem(i);
				MyAsteroid *astrd = dynamic_cast<MyAsteroid *>(i);
				delete astrd;
			}
			else if (dynamic_cast<MyBullet *>(i)) {
				scene()->removeItem(i);
				MyBullet *lsr = dynamic_cast<MyBullet *>(i);
				delete lsr;
			}
			else if (dynamic_cast<MyExplosion *>(i)) {
				scene()->removeItem(i);
				MyExplosion *explsn = dynamic_cast<MyExplosion *>(i);
				delete explsn;
			}
			else if (dynamic_cast<MyGravityField *>(i)) {
				scene()->removeItem(i);
				MyGravityField *grv_fld = dynamic_cast<MyGravityField *>(i);
				delete grv_fld;
			}
			else if (dynamic_cast<MyLife *>(i)) {
				scene()->removeItem(i);
				MyLife *lf = dynamic_cast<MyLife *>(i);
				delete lf;
			}
			else if (dynamic_cast<MyMagic *>(i)) {
				scene()->removeItem(i);
				MyMagic *mgc = dynamic_cast<MyMagic *>(i);
				delete mgc;
			}
			else if (dynamic_cast<MyShield *>(i)) {
				scene()->removeItem(i);
				MyShield *shld = dynamic_cast<MyShield *>(i);
				delete shld;
			}
			else if (dynamic_cast<MyShip *>(i)) {
				scene()->removeItem(i);
				MyShip *shp = dynamic_cast<MyShip *>(i);
				delete shp;
			}
			else if (dynamic_cast<MyShipShield *>(i)) {
				scene()->removeItem(i);
				MyShipShield *shp_shld = dynamic_cast<MyShipShield *>(i);
				delete shp_shld;
			}
			else if (dynamic_cast<MyStar *>(i)) {
				scene()->removeItem(i);
				MyStar *str = dynamic_cast<MyStar *>(i);
				delete str;
			}
			else if (dynamic_cast<QGraphicsTextItem *>(i)) {
				scene()->removeItem(i);
				QGraphicsTextItem *txt = dynamic_cast<QGraphicsTextItem *>(i);
				delete txt;
			}
		}
}

void MyGame::restart() {
	QFile file(MyRes::stng_add);
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	QString inp;
	stream >> inp;
	file.close();

	if (inp == "0") {
		prpr_scn();
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

void MyGame::prpr_scn() {
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
	setScene(gscn);
	setSceneRect(viewport()->frameGeometry());
	shp1 = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]), new QString("1"));
	scene()->addItem(shp1);
	scene()->addItem(shp1->shpshld);
	shp1->scr_txt->setPos(size().width() - shp1->scr_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
	                      MyRes::txtitem_y_crrctn);
	shp1->lf_txt->setPos(size().width() - shp1->lf_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
	                     MyRes::txtitem_y_crrctn + shp1->scr_txt->boundingRect().height());
	shp1->scr_txt->setZValue(1);
	shp1->lf_txt->setZValue(1);
	scene()->addItem(shp1->scr_txt);
	scene()->addItem(shp1->lf_txt);

	if (SettingData::gMode != 1) {
		if (SettingData::gMode == 2) {
			shp2 = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]), new QString("2"));
		}
		else {
			shp2 = new MyShip(QPixmap(MyRes::shp_adds[SettingData::aiShp]), new QString("ai"));
			shp2_ai = new MyAi(shp2);
		}
		scene()->addItem(shp2);
		scene()->addItem(shp2->shpshld);
		shp2->scr_txt->setPos(size().width() - shp2->scr_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
		                      size().height() - shp2->scr_txt->boundingRect().height() - MyRes::txtitem_y_crrctn);
		shp2->lf_txt->setPos(size().width() - shp2->lf_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
		                     size().height() - shp2->scr_txt->boundingRect().height() -
		                     shp2->lf_txt->boundingRect().height() -
		                     MyRes::txtitem_y_crrctn);
		shp2->scr_txt->setZValue(1);
		shp2->lf_txt->setZValue(1);
		scene()->addItem(shp2->scr_txt);
		scene()->addItem(shp2->lf_txt);
	}
}

void MyGame::bld_stg1() {
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
		MyAlien *aln_bg = new MyAlien(1);
		aln_bg->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(aln_bg);
	}
	for (int i = 0; i < MyRes::stg_aln_smll[1][SettingData::gDiff - 1]; i++) {
		MyAlien *aln_smll = new MyAlien(2);
		aln_smll->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(aln_smll);
	}
	for (int i = 0; i < MyRes::stg_lf; i++) {
		MyLife *lf = new MyLife();
		lf->setPos(MyRes::app_size.width() +
				            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(lf);
	}
	for (int i = 0; i < MyRes::stg_shld[SettingData::gDiff - 1]; i++) {
		MyShield *shld = new MyShield();
		shld->setPos(MyRes::app_size.width() +
				            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(shld);
	}
	for (int i = 0; i < MyRes::stg_mgc[SettingData::gDiff - 1]; i++) {
		MyMagic *mgc = new MyMagic();
		mgc->setPos(MyRes::app_size.width() +
				            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(mgc);
	}
	for (int i = 0; i < MyRes::stg_str; i++) {
		MyStar *str = new MyStar();
		str->setPos(MyRes::app_size.width() +
				            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(str);
	}
}

void MyGame::bld_stg3() {
	for (int i = 0; i < MyRes::stg_astrd[2][SettingData::gDiff - 1]; i++) {
		MyAsteroid *astrd = new MyAsteroid(2);
		astrd->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(astrd);
		scene()->addItem(astrd->grv_fld);
	}
	for (int i = 0; i < MyRes::stg_aln_bg[2][SettingData::gDiff - 1]; i++) {
		MyAlien *aln_bg = new MyAlien(3);
		aln_bg->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(aln_bg);
	}
	for (int i = 0; i < MyRes::stg_aln_smll[2][SettingData::gDiff - 1]; i++) {
		MyAlien *aln_smll = new MyAlien(4);
		aln_smll->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(aln_smll);
	}
	for (int i = 0; i < MyRes::stg_lf; i++) {
		MyLife *lf = new MyLife();
		lf->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(lf);
	}
	for (int i = 0; i < MyRes::stg_shld[SettingData::gDiff - 1]; i++) {
		MyShield *shld = new MyShield();
		shld->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(shld);
	}
	for (int i = 0; i < MyRes::stg_mgc[SettingData::gDiff - 1]; i++) {
		MyMagic *mgc = new MyMagic();
		mgc->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(mgc);
	}
	for (int i = 0; i < MyRes::stg_str; i++) {
		MyStar *str = new MyStar();
		str->setPos(MyRes::app_size.width() +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
		            (MyRes::app_size.width() + (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()) +
				            (rand() % ((MyRes::gm_drtn / MyRes::frm_dly) - MyRes::astrd_size.width() + 1)),
		            (rand() % (MyRes::app_size.height() - MyRes::astrd_size.height() + 1)));
		scene()->addItem(str);
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
		emit gamePaused();
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
				pause();
				emit gameEnded(1);
				return;
			}
			else if (shp1->scr < shp2->scr) {
				pause();
				emit gameEnded(2);
				return;
			}
			else {
				if (shp1->lf > shp2->lf) {
					pause();
					emit gameEnded(1);
					return;
				}
				else if (shp1->lf < shp2->lf) {
					pause();
					emit gameEnded(2);
					return;
				}
				else {
					pause();
					emit gameEnded(3);
					return;
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
					pause();
					emit gameEnded(4);
					return;
				}
				else {
					pause();
					emit gameEnded(1);
					return;
				}
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
			pause();
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
					if (dynamic_cast<MyAlien *>(i)->par != 0) {
						dynamic_cast<MyAlien *>(i)->par->setAln(false);
					}
					MyAlien *aln = dynamic_cast<MyAlien *>(i);
					delete aln;
				}
			}
			else if (dynamic_cast<MyAlienBoss *>(i)) {
				dynamic_cast<MyAlienBoss *>(i)->updt();
				if (!dynamic_cast<MyAlienBoss *>(i)->isVisible() ||
				    dynamic_cast<MyAlienBoss *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyAlienBoss *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyAlienBoss *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyAlienBoss *bss = dynamic_cast<MyAlienBoss *>(i);
					delete bss;
				}
			}
			else if (dynamic_cast<MyAsteroid *>(i)) {
				dynamic_cast<MyAsteroid *>(i)->updt();
				if (!dynamic_cast<MyAsteroid *>(i)->isVisible() ||
				    dynamic_cast<MyAsteroid *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyAsteroid *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyAsteroid *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					if (dynamic_cast<MyAsteroid *>(i)->grv) {
						dynamic_cast<MyAsteroid *>(i)->grv_fld->hide();
					}
					if (!dynamic_cast<MyAsteroid *>(i)->isAln()) {
						scene()->removeItem(i);
						MyAsteroid *astrd = dynamic_cast<MyAsteroid *>(i);
						delete astrd;
					}
					else {
						dynamic_cast<MyAsteroid *>(i)->hide();
					}
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
					MyBullet *lsr = dynamic_cast<MyBullet *>(i);
					delete lsr;
				}
			}
			else if (dynamic_cast<MyExplosion *>(i)) {
				dynamic_cast<MyExplosion *>(i)->updt();
				if (!dynamic_cast<MyExplosion *>(i)->isVisible() ||
				    dynamic_cast<MyExplosion *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyExplosion *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyExplosion *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyExplosion *explsn = dynamic_cast<MyExplosion *>(i);
					delete explsn;
				}
			}
			else if (dynamic_cast<MyLife *>(i)) {
				dynamic_cast<MyLife *>(i)->updt();
				if (!dynamic_cast<MyLife *>(i)->isVisible() ||
				    dynamic_cast<MyLife *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyLife *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyLife *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyLife *lf = dynamic_cast<MyLife *>(i);
					delete lf;
				}
			}
			else if (dynamic_cast<MyMagic *>(i)) {
				dynamic_cast<MyMagic *>(i)->updt();
				if (!dynamic_cast<MyMagic *>(i)->isVisible() ||
				    dynamic_cast<MyMagic *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyMagic *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyMagic *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyMagic *mgc = dynamic_cast<MyMagic *>(i);
					delete mgc;
				}
			}
			else if (dynamic_cast<MyShield *>(i)) {
				dynamic_cast<MyShield *>(i)->updt();
				if (!dynamic_cast<MyShield *>(i)->isVisible() ||
				    dynamic_cast<MyShield *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyShield *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyShield *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
					MyShield *shld = dynamic_cast<MyShield *>(i);
					delete shld;
				}
			}
			else if (dynamic_cast<MyShip *>(i)) {
				if (dynamic_cast<MyShip *>(i)->name->compare("ai") == 0) {
					shp2_ai->updt();
				}
				else {
					dynamic_cast<MyShip *>(i)->updt(prsd_kys);
				}
				if (!dynamic_cast<MyShip *>(i)->isVisible()) {
					scene()->removeItem(dynamic_cast<MyShip *>(i)->shpshld);
					scene()->removeItem(dynamic_cast<MyShip *>(i)->scr_txt);
					scene()->removeItem(dynamic_cast<MyShip *>(i)->lf_txt);
					scene()->removeItem(i);
					if (dynamic_cast<MyShip *>(i)->name->compare("1") == 0) {
						if (SettingData::gMode == 1) {
							pause();
							emit gameEnded(0);
							return;
						}
						else if (SettingData::gMode == 3) {
							pause();
							emit gameEnded(2);
							return;
						}
					}
					else if (SettingData::gMode == 3) {
						pause();
						emit gameEnded(1);
						return;
					}
					MyShip *shp = dynamic_cast<MyShip *>(i);
					delete shp;
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
					MyStar *str = dynamic_cast<MyStar *>(i);
					delete str;
				}
			}
			else if (dynamic_cast<MyGravityField *>(i) && !dynamic_cast<MyGravityField *>(i)->isVisible()) {
				scene()->removeItem(i);
//				if (dynamic_cast<MyGravityField *>(i)->sceneBoundingRect().right() < sceneRect().left() - 15 ||
//				    dynamic_cast<MyGravityField *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
//				    dynamic_cast<MyGravityField *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
//					MyGravityField *grv_fld = dynamic_cast<MyGravityField *>(i);
//					delete grv_fld;
//				}
			}
		}
}