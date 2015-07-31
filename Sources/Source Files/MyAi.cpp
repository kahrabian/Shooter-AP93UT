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
	QList<QGraphicsItem *> itms = shp->scene()->views().first()->items();
	QGraphicsItem *nrst_itm = itms.first();
			foreach (QGraphicsItem *i, itms) {
			double dx = i->pos().x() - shp->pos().x();
			double dy = i->pos().y() - shp->pos().y();
			double dx_cur = nrst_itm->pos().x() - shp->pos().x();
			double dy_cur = nrst_itm->pos().y() - shp->pos().y();
			if ((dynamic_cast<MyLife *>(i) || dynamic_cast<MyMagic *>(i) || dynamic_cast<MyShield *>(i) ||
			     dynamic_cast<MyStar *>(i)) && dx * dx + dy * dy < dx_cur * dx_cur + dy_cur * dy_cur) {
				nrst_itm = i;
			}
		}
}

void MyAi::updt() {
	gnrt_cmmnds();
	shp->updt(cmmnds);
}