//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game Objects/MyAlien.h>

MyAlien::MyAlien() :
		QGraphicsPixmapItem() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
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

	vlc = new QPointF(0, 0);
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

void MyAlien::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}

void MyAlien::ply_sf(QString &add) {
	QSoundEffect *sf = new QSoundEffect();
	sf->setSource(QUrl::fromLocalFile(add));
	sf->setVolume(SettingData::sfVol / 100.0);
	sf->play();
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


