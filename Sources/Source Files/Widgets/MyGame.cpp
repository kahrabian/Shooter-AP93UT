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
	tmp1 = new MyMagic();
	tmp1->setPos(1000, 100);
	gscn->addItem(tmp1);
	setScene(gscn);
	setSceneRect(viewport()->frameGeometry());
	timer_id = startTimer(MyRes::frm_dly);
}

MyGame::~MyGame() { }

void MyGame::unpause() {
	timer_id = startTimer(MyRes::frm_dly);
}

void MyGame::restart() {
}

void MyGame::keyPressEvent(QKeyEvent *event) {
	prsd_kys->insert(event->key());
	if (event->key() == Qt::Key_Escape) {
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
			foreach(QGraphicsItem *i, items) {
//			if (dynamic_cast<MyAlien *>(i))
//				dynamic_cast<MyAlien *>(i)->updt();
			if (dynamic_cast<MyAsteroid *>(i))
				dynamic_cast<MyAsteroid *>(i)->updt();
			if (dynamic_cast<MyBullet *>(i))
				dynamic_cast<MyBullet *>(i)->updt();
			if (dynamic_cast<MyMagic *>(i))
				dynamic_cast<MyMagic *>(i)->updt();
			if (dynamic_cast<MyShield *>(i))
				dynamic_cast<MyShield *>(i)->updt();
			if (dynamic_cast<MyShield *>(i))
				dynamic_cast<MyShield *>(i)->updt();
			if (dynamic_cast<MyShip *>(i))
				dynamic_cast<MyShip *>(i)->updt(prsd_kys);
			if (dynamic_cast<MyShipShield *>(i))
				dynamic_cast<MyShipShield *>(i)->updt();
			if (dynamic_cast<MyStar *>(i))
				dynamic_cast<MyStar *>(i)->updt();
		}
}