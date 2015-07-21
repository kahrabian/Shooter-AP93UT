//
// Created by kahrabian on 7/12/15.
//

#include <Sources/Headers/Game/MyGame.h>

MyGame::MyGame(QWidget *parent) :
		QGraphicsView(parent) {
	prsd_kys = new QSet<int>();
	resize(MyRes::app_size);

	// Test
	gscn = new QGraphicsScene();
	gscn->setSceneRect(MyRes::scn_rct);
	gscn->setBackgroundBrush(
			QBrush(QImage(MyRes::env_adds[SettingData::env]).scaled(MyRes::tl_size, Qt::KeepAspectRatio,
			                                                        Qt::SmoothTransformation)));
	tmp = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]));

	tmp1 = new MyAsteroid();
	tmp1->setPos(1000, 100);
	gscn->addItem(tmp1);
//	tmp2 = new MyMagic();
//	tmp2->setPos(1050, 100);
//	gscn->addItem(tmp2);
//	tmp3 = new MyShield();
//	tmp3->setPos(1100, 100);
//	gscn->addItem(tmp3);
//	tmp4 = new MyStar();
//	tmp4->setPos(1100, 100);
//	gscn->addItem(tmp4);

	gscn->addItem(tmp);
	gscn->addItem(tmp->shpshld);
	setScene(gscn);
	setSceneRect(viewport()->frameGeometry());
	timer_id = startTimer(MyRes::frm_dly);
}

MyGame::MyGame(QGraphicsScene *scene, QWidget *parent) :
		QGraphicsView(scene, parent) {

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
	QGraphicsView::keyPressEvent(event);
}

void MyGame::keyReleaseEvent(QKeyEvent *event) {
	prsd_kys->remove(event->key());
	QGraphicsView::keyReleaseEvent(event);
}

void MyGame::timerEvent(QTimerEvent *event) {
	setSceneRect(sceneRect().x() + MyRes::vw_mvmnt, 0, viewport()->frameGeometry().width(),
	             viewport()->frameGeometry().height());
	QList<QGraphicsItem *> items = gscn->items();
			foreach(QGraphicsItem *i, items) {
			if (dynamic_cast<MyShip *>(i))
				dynamic_cast<MyShip *>(i)->updt(prsd_kys);
			if (dynamic_cast<MyAsteroid *>(i))
				dynamic_cast<MyAsteroid *>(i)->updt();
		}
}