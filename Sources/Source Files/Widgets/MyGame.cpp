//
// Created by kahrabian on 7/12/15.
//

#include <Sources/Headers/Widgets/MyGame.h>

MyGame::MyGame(QWidget *parent) :
		QGraphicsView(parent) {
	fast = false;
	prsd_kys = new QSet<int>();
	resize(MyRes::app_size);

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

	// Test
	MyShip *tmp = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]), new QString("1"));
	gscn->addItem(tmp);
	gscn->addItem(tmp->shpshld);
	gscn->addItem(tmp->scr_txt);
	tmp->scr_txt->setPos(0, 0);

	tmp = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]), new QString("2"));
	tmp->setPos(20, 400);
	gscn->addItem(tmp);
	gscn->addItem(tmp->shpshld);

//	tmp7 = new MyExplosion();
//	tmp7->setPos(300, 50);
//	gscn->addItem(tmp7);
//
//	tmp1 = new MyAlien();
//	tmp1->setPos(1500, 50);
//	gscn->addItem(tmp1);
//
//	tmp2 = new MyAsteroid();
//	tmp2->setPos(1000, 400);
//	gscn->addItem(tmp2);
//
//
//	tmp2 = new MyAsteroid();
//	tmp2->setPos(1000, 50);
//	gscn->addItem(tmp2);
//
//	tmp6 = new MyStar();
//	tmp6->setPos(200, 100);
//	gscn->addItem(tmp6);
//
//	tmp5 = new MyShield();
//	tmp5->setPos(200, 50);
//	gscn->addItem(tmp5);

	setScene(gscn);
	setSceneRect(viewport()->frameGeometry());
	tmr_id = startTimer(MyRes::frm_dly);
}

MyGame::~MyGame() { }

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

void MyGame::restart() {
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
			if (!dynamic_cast<MyShipShield *>(i) && !i->isVisible())
				scene()->removeItem(i);
		}
}