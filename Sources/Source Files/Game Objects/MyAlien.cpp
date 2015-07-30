//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game Objects/MyAlien.h>

MyAlien::MyAlien(int typ) :
		QGraphicsPixmapItem(), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	fast = false;
	rttn = false;
	rtn = 0;
	par = 0;
	MyAlien::typ = typ;
	if (typ == 1 || typ == 3) {
		setPixmap(QPixmap(MyRes::aln_nrml_adds[rand() % MyRes::aln_nrml_cnt]).scaled(MyRes::aln_bgsize,
		                                                                             Qt::KeepAspectRatio,
		                                                                             Qt::SmoothTransformation));
	}
	else {
		setPixmap(QPixmap(MyRes::aln_nrml_adds[rand() % MyRes::aln_nrml_cnt]).scaled(MyRes::aln_smllsize,
		                                                                             Qt::KeepAspectRatio,
		                                                                             Qt::SmoothTransformation));
	}
	if (typ == 1 || typ == 2) {
		vlc = new QPointF(0, 10);
	}
	else {
		if (rand() % 2 == 0) {
			vlc = new QPointF(-10, -10);
		}
		else {
			vlc = new QPointF(-10, 10);
		}
	}
	tmr_id = startTimer(MyRes::aln_lsrdly);
	setZValue(2);
}

MyAlien::~MyAlien() {
	delete vlc;
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
		tmr_id = startTimer(MyRes::aln_lsrdly / MyRes::fst_vlc);
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
		tmr_id = startTimer(MyRes::aln_lsrdly / MyRes::fst_vlc);
	}
	else {
		tmr_id = startTimer(MyRes::aln_lsrdly);
	}
}

void MyAlien::cllsn_dtctn() {
	if (rttn) {
		return;
	}
	QList<QGraphicsItem *> clldng_items = collidingItems(Qt::ItemSelectionMode::IntersectsItemShape);
			foreach(QGraphicsItem *i, clldng_items) {
			if (dynamic_cast<MyGravityField *>(i) && i->isVisible() &&
			    !dynamic_cast<MyGravityField *>(i)->getPar()->isAln()) {
				rttn = true;
				dynamic_cast<MyGravityField *>(i)->getPar()->setAln(true);
				par = dynamic_cast<MyGravityField *>(i)->getPar();
			}
		}
}

void MyAlien::updt() {
	cllsn_dtctn();
	QPointF tplft(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().topLeft()))));
	QPointF bttmrght(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().bottomRight()))));
	QRectF vw_rct(scene()->views().first()->viewport()->rect());
	if ((tplft.y() + vlc->y() >= MyRes::y_offset && bttmrght.y() + vlc->y() <= vw_rct.height() - MyRes::y_offset) ||
	    (tplft.y() + vlc->y() < MyRes::y_offset && vlc->y() > 0) ||
	    ((bttmrght.y() + vlc->y() > vw_rct.height() - MyRes::y_offset) && vlc->y() < 0)) {
		setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
	}
	else {
		vlc->setY(vlc->y() * (-1));
	}
	if (rttn) {
		rtn = (rtn + 15) % 360;
		setTransformOriginPoint(pixmap().width() / 2, pixmap().height() / 2);
		setRotation(rtn);
		setPos(par->pos().x() + par->pixmap().width() / 2 - pixmap().width() / 2,
		       par->pos().y() + par->pixmap().height() / 2 - pixmap().height() / 2);
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
	if ((typ == 2 || typ == 4) && scene()->views().first()->sceneRect().intersects(sceneBoundingRect())) {
		ply_sf(const_cast<QString &>(MyRes::sf_aln_lsr_add));
		MyBullet *lsr = new MyBullet(1, rtn, -1);
		lsr->setPos(pos().x() + (pixmap().width() / 2),
		            pos().y() + (pixmap().height() / 2) - (MyRes::lsr_size.height() / 2));
		scene()->addItem(lsr);
	}
}