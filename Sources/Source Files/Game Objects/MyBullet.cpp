//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game Objects/MyBullet.h>

MyBullet::MyBullet(int lsr_num, int rtn, int dir) :
		QGraphicsPixmapItem(QPixmap(MyRes::lsr_add[lsr_num]).scaled(MyRes::lsr_size, Qt::KeepAspectRatio,
		                                                            Qt::SmoothTransformation)), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	if (dir == -1)
		MyBullet::rtn = 180 - rtn;
	else
		MyBullet::rtn = rtn;
	vlc = new QPointF(MyRes::lsr_mvmnt * cos(MyBullet::rtn * M_PI / 180.0),
	                  MyRes::lsr_mvmnt * sin(MyBullet::rtn * M_PI / 180.0));
	setTransformOriginPoint(0, pixmap().height() / 2);
	setRotation(MyBullet::rtn);
}

MyBullet::~MyBullet() {

}

void MyBullet::cllsn_dtctn() {
	QList<QGraphicsItem *> clldng_items = collidingItems(Qt::ItemSelectionMode::IntersectsItemShape);
			foreach(QGraphicsItem *i, clldng_items) {
			if (dynamic_cast<MyAlien *>(i) && vlc->x() > 0) {
				if (dynamic_cast<MyAlien *>(i)->getTyp() == 0) {
					QSoundEffect *sf = new QSoundEffect();
					sf->setSource(QUrl::fromLocalFile(MyRes::sf_expln_aln_bg_add));
					sf->setVolume(SettingData::sfVol / 100.0);
					sf->play();
					MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_aln_bg_size));
					expln->setPos(dynamic_cast<MyAlien *>(i)->x() + (dynamic_cast<MyAlien *>(i)->pixmap().width() / 2) -
					              (MyRes::expln_aln_bg_size.width() / 2), dynamic_cast<MyAlien *>(i)->y() +
					                                                      (dynamic_cast<MyAlien *>(i)->pixmap().height() /
					                                                       2) -
					                                                      (MyRes::expln_aln_bg_size.height() / 2) +
							MyRes::expln_aln_bg_crrctn);
					scene()->addItem(expln);
				}
				else {
					QSoundEffect *sf = new QSoundEffect();
					sf->setSource(QUrl::fromLocalFile(MyRes::sf_expln_aln_smll_add));
					sf->setVolume(SettingData::sfVol / 100.0);
					sf->play();
					MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_aln_smll_size));
					expln->setPos(dynamic_cast<MyAlien *>(i)->x() + (dynamic_cast<MyAlien *>(i)->pixmap().width() / 2) -
					              (MyRes::expln_aln_smll_size.width() / 2), dynamic_cast<MyAlien *>(i)->y() +
					                                                        (dynamic_cast<MyAlien *>(i)->pixmap().height() /
					                                                         2) -
					                                                        (MyRes::expln_aln_smll_size.height() / 2) +
					                                                        MyRes::expln_aln_smll_crrctn);
					scene()->addItem(expln);
				}
				QSoundEffect *sf = new QSoundEffect();
				sf->setSource(QUrl::fromLocalFile(MyRes::sf_expln_lsr_add));
				sf->setVolume(SettingData::sfVol / 100.0);
				sf->play();
				MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_lsr_size));
				expln->setPos(x() + (pixmap().width() / 2) - (MyRes::expln_lsr_size.width() / 2),
				              y() + (pixmap().height() / 2) - (MyRes::expln_lsr_size.height() / 2) +
				              MyRes::expln_lsr_crrctn);
				scene()->addItem(expln);

				dynamic_cast<MyAlien *>(i)->killTimer(dynamic_cast<MyAlien *>(i)->getTmr_id());
				scene()->removeItem(i);
				hide();
				emit scrGained();
			}
			else if (dynamic_cast<MyAsteroid *>(i) && vlc->x() > 0) {
				QSoundEffect *sf = new QSoundEffect();
				sf->setSource(QUrl::fromLocalFile(MyRes::sf_expln_astrd_add));
				sf->setVolume(SettingData::sfVol / 100.0);
				sf->play();
				MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_astrd_size));
				expln->setPos(
						dynamic_cast<MyAsteroid *>(i)->x() + (dynamic_cast<MyAsteroid *>(i)->pixmap().width() / 2) -
						(MyRes::expln_astrd_size.width() / 2),
						dynamic_cast<MyAsteroid *>(i)->y() + (dynamic_cast<MyAsteroid *>(i)->pixmap().height() / 2) -
						(MyRes::expln_astrd_size.height() / 2) + MyRes::expln_astrd_crrctn);
				scene()->addItem(expln);

				QSoundEffect *sf_lsr = new QSoundEffect();
				sf_lsr->setSource(QUrl::fromLocalFile(MyRes::sf_expln_lsr_add));
				sf_lsr->setVolume(SettingData::sfVol / 100.0);
				sf_lsr->play();
				expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_lsr_size));
				expln->setPos(x() + (pixmap().width() / 2) - (MyRes::expln_lsr_size.width() / 2),
				              y() + (pixmap().height() / 2) - (MyRes::expln_lsr_size.height() / 2) +
				              MyRes::expln_lsr_crrctn);
				scene()->addItem(expln);

				scene()->removeItem(i);
				hide();
			}
		}
}

void MyBullet::updt() {
	cllsn_dtctn();
	setPos(pos().x() + MyRes::vw_mvmnt + vlc->x(), pos().y() + vlc->y());
}