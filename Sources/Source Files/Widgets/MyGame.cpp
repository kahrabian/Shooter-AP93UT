//
// Created by kahrabian on 7/12/15.
//

#include <Sources/Headers/Widgets/MyGame.h>

MyGame::MyGame(QWidget *parent) :
		QGraphicsView(parent) {
	prsd_kys = new QSet<int>();
	resize(MyRes::app_size);

	gscn = new QGraphicsScene();
	gscn->setSceneRect(MyRes::scn_rct);
	gscn->setBackgroundBrush(
			QBrush(QImage(MyRes::env_adds[SettingData::env]).scaled(MyRes::tl_size, Qt::KeepAspectRatio,
			                                                        Qt::SmoothTransformation)));
	// Test
	tmp = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]));
	gscn->addItem(tmp);
	gscn->addItem(tmp->shpshld);

	tmp1 = new MyAlien();
	tmp1->setPos(500, 100);
	gscn->addItem(tmp1);


	tmp1 = new MyAlien();
	tmp1->setPos(1000, 100);
	gscn->addItem(tmp1);

	tmp1 = new MyAlien();
	tmp1->setPos(1500, 100);
	gscn->addItem(tmp1);

	setScene(gscn);
	setSceneRect(viewport()->frameGeometry());
	timer_id = startTimer(MyRes::frm_dly);
}

MyGame::~MyGame() { }

void MyGame::unpause() {
	// Unpause everything
	timer_id = startTimer(MyRes::frm_dly);
}

void MyGame::restart() {
}

void MyGame::keyPressEvent(QKeyEvent *event) {
	prsd_kys->insert(event->key());
	if (event->key() == Qt::Key_Escape) {
		// Pause everything
		killTimer(timer_id);
		emit gamePaused();
	}
}

void MyGame::keyReleaseEvent(QKeyEvent *event) {
	prsd_kys->remove(event->key());
}

void MyGame::timerEvent(QTimerEvent *event) {
	setSceneRect(sceneRect().x() + MyRes::vw_mvmnt, 0, viewport()->frameGeometry().width(),
	             viewport()->frameGeometry().height());
	QList<QGraphicsItem *> items = gscn->items();

//	QTextStream X(stderr);
//	X << items.size() << endl;

			foreach(QGraphicsItem *i, items) {
			if (dynamic_cast<MyAlien *>(i)) {
				dynamic_cast<MyAlien *>(i)->updt();
				if (dynamic_cast<MyAlien *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyAlien *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyAlien *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					dynamic_cast<MyAlien *>(i)->killTimer(dynamic_cast<MyAlien *>(i)->getTmr_id());
					scene()->removeItem(i);
				}
			}
			else if (dynamic_cast<MyAsteroid *>(i)) {
				dynamic_cast<MyAsteroid *>(i)->updt();
				if (dynamic_cast<MyAsteroid *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
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
				if (dynamic_cast<MyLife *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyLife *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyLife *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
				}
			}
			else if (dynamic_cast<MyMagic *>(i)) {
				dynamic_cast<MyMagic *>(i)->updt();
				if (dynamic_cast<MyMagic *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyMagic *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyMagic *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
				}
			}
			else if (dynamic_cast<MyShield *>(i)) {
				dynamic_cast<MyShield *>(i)->updt();
				if (dynamic_cast<MyShield *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
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
				if (dynamic_cast<MyStar *>(i)->sceneBoundingRect().right() < sceneRect().left() ||
				    dynamic_cast<MyStar *>(i)->sceneBoundingRect().top() > sceneRect().bottom() ||
				    dynamic_cast<MyStar *>(i)->sceneBoundingRect().bottom() < sceneRect().top()) {
					scene()->removeItem(i);
				}
			}
		}
}