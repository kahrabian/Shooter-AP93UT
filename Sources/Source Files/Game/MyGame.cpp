//
// Created by kahrabian on 7/12/15.
//

#include <Sources/Headers/Resources.h>
#include "../../Headers/Game/MyGame.h"

MyGame::MyGame(QWidget *parent) :
		QGraphicsView(parent) {
	prsd_kys = new QSet<int>();
	resize(MyRes::app_size);

	stp_tmr = new QElapsedTimer();
	stp_tmr->invalidate();

	gscn = new QGraphicsScene();
	gscn->setSceneRect(MyRes::scn_rct);
	gscn->setBackgroundBrush(QBrush(QImage(MyRes::env_adds[SettingData::env]).scaled(MyRes::tl_size)));
	tmp = new MyShip(QPixmap(MyRes::shp_adds[SettingData::uShp]));
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
	stp_tmr_val = stp_tmr->elapsed();
	stp_tmr->invalidate();
	timer_id = startTimer(MyRes::frm_dly);
}

void MyGame::restart() {
}

void MyGame::keyPressEvent(QKeyEvent *event) {
	prsd_kys->insert(event->key());
	if (event->key() == Qt::Key_Escape) {
		stp_tmr->restart();
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
	tmp->updt(stp_tmr->elapsed(), prsd_kys);
	setSceneRect(sceneRect().x() + MyRes::vw_mvmnt, 0, viewport()->frameGeometry().width(),
	             viewport()->frameGeometry().height());
}