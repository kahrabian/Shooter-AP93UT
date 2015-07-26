//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game Objects/MyAlien.h>

MyAlien::MyAlien() :
		QGraphicsPixmapItem(), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	fast = false;
	typ = rand() % 2;
	if (typ == 0) {
		setPixmap(QPixmap(MyRes::aln_nrml_adds[rand() % MyRes::aln_nrml_cnt]).scaled(MyRes::aln_smllsize,
		                                                                             Qt::KeepAspectRatio,
		                                                                             Qt::SmoothTransformation));
	}
	else {
		setPixmap(QPixmap(MyRes::aln_nrml_adds[rand() % MyRes::aln_nrml_cnt]).scaled(MyRes::aln_bgsize,
		                                                                             Qt::KeepAspectRatio,
		                                                                             Qt::SmoothTransformation));
	}

	vlc = new QPointF(5, 10);
	tmr_id = startTimer(MyRes::aln_lsrdly);
}

MyAlien::~MyAlien() {

}

int MyAlien::getTmr_id() const {
	return tmr_id;
}

int MyAlien::getTyp() const {
	return typ;
}

void MyAlien::change_speed() {
	fast = !fast;
	killTimer(tmr_id);
	if (fast) {
		tmr_id = startTimer(MyRes::aln_lsrdly / 4);
	}
	else {
		tmr_id = startTimer(MyRes::aln_lsrdly);
	}
}

void MyAlien::game_paused() {
	killTimer(tmr_id);
}

void MyAlien::game_unpaused() {
	if (fast) {
		tmr_id = startTimer(MyRes::aln_lsrdly / 4);
	}
	else {
		tmr_id = startTimer(MyRes::aln_lsrdly);
	}
}

void MyAlien::updt() {
	QPointF tplft(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().topLeft()))));
	QPointF bttmrght(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().bottomRight()))));
	QRectF vw_rct(scene()->views().first()->viewport()->rect());
	if ((tplft.y() + vlc->y() >= MyRes::y_offset && bttmrght.y() + vlc->y() <= vw_rct.height() - MyRes::y_offset) ||
	    (tplft.y() + vlc->y() < MyRes::y_offset && vlc->y() > 0) ||
	    ((bttmrght.y() + vlc->y() > vw_rct.height() - MyRes::y_offset) && vlc->y() < 0)) {
		setPos(pos().x(), pos().y() + vlc->y());
	}
	else {
		vlc->setY(vlc->y() * (-1));
	}
}

void MyAlien::ply_sf(QString &add) {
	if (!SettingData::sfMut && sceneBoundingRect().intersects(scene()->views().first()->sceneRect())) {
		QSoundEffect *sf = new QSoundEffect();
		sf->setSource(QUrl::fromLocalFile(add));
		sf->setVolume(SettingData::sfVol / 100.0);
		sf->play();
	}
}

void MyAlien::timerEvent(QTimerEvent *event) {
	if (typ == 1) {
		ply_sf(const_cast<QString &>(MyRes::sf_aln_lsr_add));
		MyBullet *tmp = new MyBullet(1, 0, -1);
		tmp->setPos(pos().x(),
		            pos().y() + (pixmap().height() / 2) - (MyRes::lsr_size.height() / 2));
		scene()->addItem(tmp);
	}
}