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
		stg->setPos(MyRes::app_size.width() + i * (MyRes::stg_size.width() + MyRes::app_size.width() +
		                                           (MyRes::gm_drtn / MyRes::frm_dly) + MyRes::app_size.width()), 0);
		gscn->addItem(stg);
	}

	restart();
	setScene(gscn);
	setSceneRect(viewport()->frameGeometry());
	tmr_id = startTimer(MyRes::frm_dly);
}

MyGame::~MyGame() { }

void MyGame::restart() {
	QFile file(MyRes::stng_add);
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
	QString tmp;
	stream >> tmp;
	file.close();

	if (tmp == "0") {
		MyShip *test = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]), new QString("1"));
		gscn->addItem(test);
		gscn->addItem(test->shpshld);
		test->scr_txt->setPos(size().width() - test->scr_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
		                      MyRes::txtitem_y_crrctn);
		test->lf_txt->setPos(size().width() - test->lf_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
		                     MyRes::txtitem_y_crrctn + test->scr_txt->boundingRect().height());
		gscn->addItem(test->scr_txt);
		gscn->addItem(test->lf_txt);

		test = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]), new QString("2"));
		gscn->addItem(test);
		gscn->addItem(test->shpshld);
		test->scr_txt->setPos(size().width() - test->scr_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
		                      size().height() - test->scr_txt->boundingRect().height() - MyRes::txtitem_y_crrctn);
		test->lf_txt->setPos(size().width() - test->lf_txt->boundingRect().width() - MyRes::txtitem_x_crrctn,
		                     size().height() - test->scr_txt->boundingRect().height() -
		                     test->lf_txt->boundingRect().height() -
		                     MyRes::txtitem_y_crrctn);
		gscn->addItem(test->scr_txt);
		gscn->addItem(test->lf_txt);
	}
//	else if(tmp == "1") {
//
//	}
//	else if(tmp == "2") {
//
//	}
//	else if(tmp == "3") {
//
//	}
}

void MyGame::change_speed() {
	fast = !fast;
	killTimer(tmr_id);
	if (fast)
		tmr_id = startTimer(MyRes::frm_dly / 4);
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
		tmr_id = startTimer(MyRes::frm_dly / 4);
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
	QList<QGraphicsItem *> items = scene()->items();
			foreach(QGraphicsItem *i, items) {
			if (dynamic_cast<MyAlien *>(i)) {
				dynamic_cast<MyAlien *>(i)->updt();
				if (!dynamic_cast<MyAlien *>(i)->isVisible() ||
				    dynamic_cast<MyAlien *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyAlien *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyAlien *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					dynamic_cast<MyAlien *>(i)->killTimer(dynamic_cast<MyAlien *>(i)->getTmr_id());
					scene()->removeItem(i);
				}
			}
			else if (dynamic_cast<MyAsteroid *>(i)) {
				dynamic_cast<MyAsteroid *>(i)->updt();
				if (!dynamic_cast<MyAsteroid *>(i)->isVisible() ||
				    dynamic_cast<MyAsteroid *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyAsteroid *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyAsteroid *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
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
				}
			}
			else if (dynamic_cast<MyExplosion *>(i)) {
				dynamic_cast<MyExplosion *>(i)->updt();
				if (!dynamic_cast<MyExplosion *>(i)->isVisible() ||
				    dynamic_cast<MyExplosion *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyExplosion *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyExplosion *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
				}
			}
			else if (dynamic_cast<MyLife *>(i)) {
				dynamic_cast<MyLife *>(i)->updt();
				if (!dynamic_cast<MyLife *>(i)->isVisible() ||
				    dynamic_cast<MyLife *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyLife *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyLife *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
				}
			}
			else if (dynamic_cast<MyMagic *>(i)) {
				dynamic_cast<MyMagic *>(i)->updt();
				if (!dynamic_cast<MyMagic *>(i)->isVisible() ||
				    dynamic_cast<MyMagic *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyMagic *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyMagic *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
				}
			}
			else if (dynamic_cast<MyShield *>(i)) {
				dynamic_cast<MyShield *>(i)->updt();
				if (!dynamic_cast<MyShield *>(i)->isVisible() ||
				    dynamic_cast<MyShield *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyShield *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyShield *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
				}
			}
			else if (dynamic_cast<MyShip *>(i)) {
				dynamic_cast<MyShip *>(i)->updt(prsd_kys);
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
				}
			}
		}
	items = scene()->items();
			foreach(QGraphicsItem *i, items) {
			if (!dynamic_cast<MyShipShield *>(i) && !dynamic_cast<MyShip *>(i) && !i->isVisible()) {
				scene()->removeItem(i);
			}
			else if (dynamic_cast<MyShip *>(i) && !i->isVisible()) {
				scene()->removeItem(dynamic_cast<MyShip *>(i)->shpshld);
				scene()->removeItem(dynamic_cast<MyShip *>(i)->scr_txt);
				scene()->removeItem(dynamic_cast<MyShip *>(i)->lf_txt);
				scene()->removeItem(i);
			}
		}
}