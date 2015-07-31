//
// Created by kahrabian on 7/31/15.
//

#include <Sources/Headers/MyAi.h>

MyAi::MyAi(MyShip *shp) {
	MyAi::shp = shp;
	cmmnds = new QSet<int>();
}

MyAi::~MyAi() {

}

void MyAi::gnrt_cmmnds() {
	cmmnds->clear();
	QList<QGraphicsItem *> itms = shp->scene()->items();
	QGraphicsItem *nrst_itm = shp;
			foreach (QGraphicsItem *i, itms) {
			if (shp->scene()->views().first()->sceneRect().right() < i->sceneBoundingRect().left()) {
				continue;
			}
			if (dynamic_cast<MyLife *>(i) || dynamic_cast<MyMagic *>(i) || dynamic_cast<MyShield *>(i) ||
			    dynamic_cast<MyStar *>(i)) {
				nrst_itm = i;
			}
		}
			foreach (QGraphicsItem *i, itms) {
			if (shp->scene()->views().first()->sceneRect().right() < i->sceneBoundingRect().left()) {
				continue;
			}
			double dx = i->pos().x() + i->boundingRect().width() / 2 - shp->pos().x();
			double dy = i->pos().y() + i->boundingRect().height() / 2 - shp->pos().y();
			double dx_cur = nrst_itm->pos().x() + nrst_itm->boundingRect().width() / 2 - shp->pos().x();
			double dy_cur = nrst_itm->pos().y() + nrst_itm->boundingRect().height() / 2 - shp->pos().y();
			if ((dynamic_cast<MyLife *>(i) || dynamic_cast<MyMagic *>(i) || dynamic_cast<MyShield *>(i) ||
					dynamic_cast<MyStar *>(i)) && (dx * dx + dy * dy < dx_cur * dx_cur + dy_cur * dy_cur)) {
				nrst_itm = i;
			}
		}
	bool up = false, down = false, left = false, right = false;
	if (nrst_itm != shp && nrst_itm->pos().x() < shp->scene()->views().first()->sceneRect().x() +
			                                             (3.0 * shp->scene()->views().first()->sceneRect().width() /
			                                              4)) {
		if (shp->sceneBoundingRect().right() - shp->boundingRect().width() / 2 <
		    nrst_itm->sceneBoundingRect().left() +
				    nrst_itm->boundingRect().width() / 2 - MyRes::ai_view_offset) {
			right = true;
		}
		else if (shp->sceneBoundingRect().left() + shp->boundingRect().width() / 2 >
				nrst_itm->sceneBoundingRect().right() - nrst_itm->boundingRect().width() / 2 + MyRes::ai_view_offset) {
			left = true;
		}
		if (shp->sceneBoundingRect().bottom() - shp->boundingRect().height() / 2 <
		    nrst_itm->sceneBoundingRect().top() +
				    nrst_itm->boundingRect().height() / 2 - MyRes::ai_view_offset) {
			down = true;
		}
		else if (shp->sceneBoundingRect().top() + shp->boundingRect().height() / 2 >
				nrst_itm->sceneBoundingRect().bottom() - nrst_itm->boundingRect().height() / 2 +
				MyRes::ai_view_offset) {
			up = true;
		}
		if ((nrst_itm->pos().y() < MyRes::y_offset ||
		     nrst_itm->pos().y() > shp->scene()->views().first()->viewport()->rect().height() - MyRes::y_offset) &&
		    nrst_itm->pos().x() > shp->pos().x()) {
			right = true;
		}
	}
	else {
		left = true;
	}
	itms = shp->scene()->items(shp->sceneBoundingRect().x() + shp->sceneBoundingRect().width() / 2 - 100,
	                           shp->sceneBoundingRect().y() + shp->sceneBoundingRect().height() / 2 - 100, 200, 200,
	                           Qt::IntersectsItemShape, Qt::AscendingOrder);
			foreach (QGraphicsItem *i, itms) {
			if (!shp->shpshld->isVisible()) {
				if (dynamic_cast<MyAlien *>(i)) {
					if (dynamic_cast<MyAlien *>(i)->sceneBoundingRect().y() +
					    dynamic_cast<MyAlien *>(i)->pixmap().height() / 2 >
					    shp->sceneBoundingRect().y() + shp->pixmap().height() / 2) {
						up = false;
					}
					else {
						down = false;
					}
					if (dynamic_cast<MyAlien *>(i)->sceneBoundingRect().x() +
					    dynamic_cast<MyAlien *>(i)->pixmap().width() / 2 >
					    shp->sceneBoundingRect().x() + shp->pixmap().width() / 2) {
						right = false;
					}
					else {
						left = false;
					}
				}
				else if (dynamic_cast<MyAsteroid *>(i)) {
					if (dynamic_cast<MyAsteroid *>(i)->sceneBoundingRect().y() +
					    dynamic_cast<MyAsteroid *>(i)->pixmap().height() / 2 >
					    shp->sceneBoundingRect().y() + shp->pixmap().height() / 2) {
						up = false;
					}
					else {
						down = false;
					}
					if (dynamic_cast<MyAsteroid *>(i)->sceneBoundingRect().x() +
					    dynamic_cast<MyAsteroid *>(i)->pixmap().width() / 2 >
					    shp->sceneBoundingRect().x() + shp->pixmap().width() / 2) {
						right = false;
					}
					else {
						left = false;
					}
				}
				else if (dynamic_cast<MyBullet *>(i) && dynamic_cast<MyBullet *>(i)->getDir() == -1) {
					if (dynamic_cast<MyBullet *>(i)->sceneBoundingRect().y() +
					    dynamic_cast<MyBullet *>(i)->pixmap().height() / 2 >
					    shp->sceneBoundingRect().y() + shp->pixmap().height() / 2) {
						up = false;
					}
					else {
						down = false;
					}
					if (dynamic_cast<MyBullet *>(i)->sceneBoundingRect().x() +
					    dynamic_cast<MyBullet *>(i)->pixmap().width() / 2 >
					    shp->sceneBoundingRect().x() + shp->pixmap().width() / 2) {
						right = false;
					}
					else {
						left = false;
					}
				}
				else if (dynamic_cast<MyShip *>(i) && i != shp) {
					if (dynamic_cast<MyShip *>(i)->sceneBoundingRect().y() +
					    dynamic_cast<MyShip *>(i)->pixmap().height() / 2 >
					    shp->sceneBoundingRect().y() + shp->pixmap().height() / 2) {
						up = false;
					}
					else {
						down = false;
					}
					if (dynamic_cast<MyShip *>(i)->sceneBoundingRect().x() +
					    dynamic_cast<MyShip *>(i)->pixmap().width() / 2 >
					    shp->sceneBoundingRect().x() + shp->pixmap().width() / 2) {
						right = false;
					}
					else {
						left = false;
					}
				}
				else if (dynamic_cast<MyShipShield *>(i) && i->isVisible() && i != shp->shpshld) {
					if (dynamic_cast<MyShipShield *>(i)->sceneBoundingRect().y() +
					    dynamic_cast<MyShipShield *>(i)->pixmap().height() / 2 >
					    shp->sceneBoundingRect().y() + shp->pixmap().height() / 2) {
						up = false;
					}
					else {
						down = false;
					}
					if (dynamic_cast<MyShipShield *>(i)->sceneBoundingRect().x() +
					    dynamic_cast<MyShipShield *>(i)->pixmap().width() / 2 >
					    shp->sceneBoundingRect().x() + shp->pixmap().width() / 2) {
						right = false;
					}
					else {
						left = false;
					}
				}
			}
		}
	if (up) {
		cmmnds->insert(-Qt::Key_W);
	}
	if (down) {
		cmmnds->insert(-Qt::Key_S);
	}
	if (left) {
		cmmnds->insert(-Qt::Key_A);
	}
	if (right) {
		cmmnds->insert(-Qt::Key_D);
	}
	cmmnds->insert(-Qt::Key_X);
}

void MyAi::updt() {
	gnrt_cmmnds();
	shp->updt(cmmnds);
}