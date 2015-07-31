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
	cmmnds->insert(-Qt::Key_X);
	QList<QGraphicsItem *> itms = shp->scene()->items();
	QGraphicsItem *nrst_itm = shp;
			foreach (QGraphicsItem *i, itms) {
			if (shp->scene()->views().first()->sceneRect().right() < i->sceneBoundingRect().left())
				continue;
			if (dynamic_cast<MyLife *>(i) || dynamic_cast<MyMagic *>(i) || dynamic_cast<MyShield *>(i) ||
			    dynamic_cast<MyStar *>(i)) {
				nrst_itm = i;
			}
		}
			foreach (QGraphicsItem *i, itms) {
			if (shp->scene()->views().first()->sceneRect().right() < i->sceneBoundingRect().left())
				continue;
			double dx = i->pos().x() + i->boundingRect().width() / 2 - shp->pos().x();
			double dy = i->pos().y() + i->boundingRect().height() / 2 - shp->pos().y();
			double dx_cur = nrst_itm->pos().x() + nrst_itm->boundingRect().width() / 2 - shp->pos().x();
			double dy_cur = nrst_itm->pos().y() + nrst_itm->boundingRect().height() / 2 - shp->pos().y();
			if ((dynamic_cast<MyLife *>(i) || dynamic_cast<MyMagic *>(i) || dynamic_cast<MyShield *>(i) ||
					dynamic_cast<MyStar *>(i)) && (dx * dx + dy * dy < dx_cur * dx_cur + dy_cur * dy_cur)) {
				nrst_itm = i;
			}
		}
	if (!dynamic_cast<MyShip *>(nrst_itm)) {
		if (shp->sceneBoundingRect().right() - shp->boundingRect().width() / 2 <
		    nrst_itm->sceneBoundingRect().left() +
		    nrst_itm->boundingRect().width() / 2) {
			cmmnds->insert(-Qt::Key_D);
		}
		else if (shp->sceneBoundingRect().left() + shp->boundingRect().width() / 2 >
		         nrst_itm->sceneBoundingRect().right() - nrst_itm->boundingRect().width() / 2) {
			cmmnds->insert(-Qt::Key_A);
		}
		if (shp->sceneBoundingRect().bottom() - shp->boundingRect().height() / 2 <
		    nrst_itm->sceneBoundingRect().top() +
		    nrst_itm->boundingRect().height() / 2) {
			cmmnds->insert(-Qt::Key_S);
		}
		else if (shp->sceneBoundingRect().top() + shp->boundingRect().height() / 2 >
		         nrst_itm->sceneBoundingRect().bottom() - nrst_itm->boundingRect().height() / 2) {
			cmmnds->insert(-Qt::Key_W);
		}
	}
}

void MyAi::updt() {
	gnrt_cmmnds();
	shp->updt(cmmnds);
}