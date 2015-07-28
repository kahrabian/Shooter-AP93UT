//
// Created by kahrabian on 7/20/15.
//

#include <Sources/Headers/Game Objects/MyShipShield.h>

MyShipShield::MyShipShield() :
		QGraphicsPixmapItem(QPixmap(MyRes::shp_shld_add).scaled(MyRes::shp_shld_size, Qt::KeepAspectRatio,
		                                                        Qt::SmoothTransformation)), QObject() {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyShipShield::~MyShipShield() {
	delete vlc;
}

void MyShipShield::dstry() {
	emit shieldDestroyd();
}

void MyShipShield::ply_sf(QString &add) {
	if (!SettingData::sfMut) {
		QSoundEffect *sf = new QSoundEffect();
		sf->setSource(QUrl::fromLocalFile(add));
		sf->setVolume(SettingData::sfVol / 100.0);
		sf->play();
	}
}

void MyShipShield::cllsn_dtctn() {
	QList<QGraphicsItem *> clldng_items = collidingItems(Qt::ItemSelectionMode::IntersectsItemShape);
			foreach(QGraphicsItem *i, clldng_items) {
			if (dynamic_cast<MyAsteroid *>(i) && dynamic_cast<MyAsteroid *>(i)->isVisible() && isVisible()) {
				ply_sf(const_cast<QString &>(MyRes::sf_expln_astrd_add));
				MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_astrd_size));
				expln->setPos(
						dynamic_cast<MyAsteroid *>(i)->x() + (dynamic_cast<MyAsteroid *>(i)->pixmap().width() / 2) -
						(MyRes::expln_astrd_size.width() / 2),
						dynamic_cast<MyAsteroid *>(i)->y() + (dynamic_cast<MyAsteroid *>(i)->pixmap().height() / 2) -
								(MyRes::expln_astrd_size.height() / 2) + MyRes::expln_astrd_crrctn);
				expln->updt();
				scene()->addItem(expln);
				dynamic_cast<MyAsteroid *>(i)->hide();
			}
			if (dynamic_cast<MyBullet *>(i) && dynamic_cast<MyBullet *>(i)->isVisible() && isVisible()) {
				ply_sf(const_cast<QString &>(MyRes::sf_expln_lsr_add));
				MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_lsr_size));
				expln->setPos(dynamic_cast<MyBullet *>(i)->x() + (dynamic_cast<MyBullet *>(i)->pixmap().width() / 2) -
				              (MyRes::expln_lsr_size.width() / 2),
				              dynamic_cast<MyBullet *>(i)->y() + (dynamic_cast<MyBullet *>(i)->pixmap().height() / 2) -
						              (MyRes::expln_lsr_size.height() / 2) + MyRes::expln_lsr_crrctn);
				expln->updt();
				scene()->addItem(expln);
				dynamic_cast<MyBullet *>(i)->hide();
			}
			else if (dynamic_cast<MyAlien *>(i) && dynamic_cast<MyAlien *>(i)->isVisible() && isVisible()) {
				if (dynamic_cast<MyAlien *>(i)->getTyp() == 0) {
					ply_sf(const_cast<QString &>(MyRes::sf_expln_aln_bg_add));
					MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_aln_bg_size));
					expln->setPos(dynamic_cast<MyAlien *>(i)->x() + (dynamic_cast<MyAlien *>(i)->pixmap().width() / 2) -
					              (MyRes::expln_aln_bg_size.width() / 2), dynamic_cast<MyAlien *>(i)->y() +
					                                                      (dynamic_cast<MyAlien *>(i)->pixmap().height() /
					                                                       2) -
							(MyRes::expln_aln_bg_size.height() / 2) + MyRes::expln_aln_bg_crrctn);
					scene()->addItem(expln);
				}
				else {
					ply_sf(const_cast<QString &>(MyRes::sf_expln_aln_smll_add));
					MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_aln_smll_size));
					expln->setPos(dynamic_cast<MyAlien *>(i)->x() + (dynamic_cast<MyAlien *>(i)->pixmap().width() / 2) -
					              (MyRes::expln_aln_smll_size.width() / 2), dynamic_cast<MyAlien *>(i)->y() +
					                                                        (dynamic_cast<MyAlien *>(i)->pixmap().height() /
					                                                         2) -
							(MyRes::expln_aln_smll_size.height() / 2) + MyRes::expln_aln_smll_crrctn);
					scene()->addItem(expln);
				}
				ply_sf(const_cast<QString &>(MyRes::sf_expln_shpshld_add));
				dynamic_cast<MyAlien *>(i)->killTimer(dynamic_cast<MyAlien *>(i)->getTmr_id());
				dynamic_cast<MyAlien *>(i)->hide();
				emit shieldDestroyd();
			}
			else if (dynamic_cast<MyShipShield *>(i) && dynamic_cast<MyShipShield *>(i)->isVisible() && isVisible()) {
				ply_sf(const_cast<QString &>(MyRes::sf_expln_shpshld_add));
				dynamic_cast<MyShipShield *>(i)->dstry();
				emit shieldDestroyd();
			}
		}
}

void MyShipShield::updt() {
	cllsn_dtctn();
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}
