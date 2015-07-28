//
// Created by kahrabian on 7/28/15.
//

#include <Sources/Headers/Game Objects/MyAlienBoss.h>

MyAlienBoss::MyAlienBoss(int stg) :
		QGraphicsPixmapItem(), QObject() {
	MyAlienBoss::stg = stg;
	astrd_frms = new QPixmap *[MyRes::astrd_frcnt];
	astrd_num = rand() % MyRes::astrd_typcnt;
	frm_num = 0;
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(-10, -10);
	for (int i = 0; i < MyRes::astrd_frcnt; i++) {
		astrd_frms[i] = new QPixmap(MyRes::astrd_adds[astrd_num][i]);
	}
	setPixmap(*astrd_frms[0]);
}

MyAlienBoss::~MyAlienBoss() {
	for (int i = 0; i < MyRes::astrd_frcnt; i++) {
		delete astrd_frms[i];
	}
	delete[] astrd_frms;
	delete vlc;
}

void MyAlienBoss::cllsn_dtctn() {
	QList<QGraphicsItem *> clldng_items = collidingItems(Qt::ItemSelectionMode::IntersectsItemShape);
			foreach(QGraphicsItem *i, clldng_items) {
//			if (dynamic_cast<MyShip *>(i) && dynamic_cast<MyShip *>(i)->isVisible()) {
//				ply_sf(const_cast<QString &>(MyRes::sf_shp_shp_add));
//				lf--;
//			}
//			else if (dynamic_cast<MyShipShield *>(i) && dynamic_cast<MyShipShield *>(i)->isVisible() &&
//			         dynamic_cast<MyShipShield *>(i) != shpshld) {
//				ply_sf(const_cast<QString &>(MyRes::sf_expln_shpshld_add));
//				lf--;
//				dynamic_cast<MyShipShield *>(i)->dstry();
//			}
//			if (dynamic_cast<MyBullet *>(i) && dynamic_cast<MyBullet *>(i)->isVisible() && isVisible()) {
//				ply_sf(const_cast<QString &>(MyRes::sf_expln_lsr_add));
//				MyExplosion *expln = new MyExplosion(const_cast<QSize *>(&MyRes::expln_lsr_size));
//				expln->setPos(dynamic_cast<MyBullet *>(i)->x() + (dynamic_cast<MyBullet *>(i)->pixmap().width() / 2) -
//				              (MyRes::expln_lsr_size.width() / 2),
//				              dynamic_cast<MyBullet *>(i)->y() + (dynamic_cast<MyBullet *>(i)->pixmap().height() / 2) -
//				              (MyRes::expln_lsr_size.height() / 2) + MyRes::expln_lsr_crrctn);
//				expln->updt();
//				scene()->addItem(expln);
//				dynamic_cast<MyBullet *>(i)->hide();
//			}
		}
}

void MyAlienBoss::updt() {
	cllsn_dtctn();
	frm_num = (frm_num + 1) % (3 * MyRes::astrd_frcnt);
	setPixmap(astrd_frms[(frm_num / 3) % MyRes::astrd_frcnt]->scaled(MyRes::astrd_size, Qt::KeepAspectRatio,
	                                                                 Qt::SmoothTransformation));
	QPointF tplft(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().topLeft()))));
	QPointF bttmrght(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().bottomRight()))));
	QRectF vw_rct(scene()->views().first()->viewport()->rect());
	if ((tplft.x() + vlc->x() >= 0 && bttmrght.x() + vlc->x() <= vw_rct.width()) ||
	    (tplft.x() + vlc->x() < 0 && vlc->x() > 0) ||
	    (bttmrght.x() + vlc->x() > vw_rct.width() && vlc->x() < 0)) {
		setPos(pos().x() + vlc->x(), pos().y());
	}
	else {
		vlc->setX(vlc->x() * (-1));
	}
	if ((tplft.y() + vlc->y() >= 0 && bttmrght.y() + vlc->y() <= vw_rct.height()) ||
	    (tplft.y() + vlc->y() < 0 && vlc->y() > 0) ||
	    (bttmrght.y() + vlc->y() > vw_rct.height() && vlc->y() < 0)) {
		setPos(pos().x(), pos().y() + vlc->y());
	}
	else {
		vlc->setY(vlc->y() * (-1));
	}
}