//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game Objects/MyAsteroid.h>

MyAsteroid::MyAsteroid(int typ) :
		QGraphicsPixmapItem(), QObject() {
	astrd_frms = new QPixmap *[MyRes::astrd_frcnt];
	astrd_num = rand() % MyRes::astrd_typcnt;
	frm_num = 0;
	aln = false;
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	if (typ == 1) {
		vlc = new QPointF(-10, 0);
	}
	else {
		if (rand() % 2 == 0) {
			vlc = new QPointF(-10, -10);
		}
		else {
			vlc = new QPointF(-10, 10);
		}
	}
	if (typ == 1) {
		grv = true;
		grv_fld = new QGraphicsEllipseItem(boundingRect());
	}
	else {
		grv = false;
	}
	for (int i = 0; i < MyRes::astrd_frcnt; i++) {
		astrd_frms[i] = new QPixmap(MyRes::astrd_adds[astrd_num][i]);
	}
	setPixmap(*astrd_frms[0]);
}

MyAsteroid::~MyAsteroid() {
	for (int i = 0; i < MyRes::astrd_frcnt; i++) {
		delete astrd_frms[i];
	}
	delete[] astrd_frms;
	delete vlc;
}

void MyAsteroid::setAln(bool aln) {
	MyAsteroid::aln = aln;
}

bool MyAsteroid::isAln() const {
	return aln;
}

QPointF *MyAsteroid::getVlc() const {
	return vlc;
}

void MyAsteroid::updt() {
	frm_num = (frm_num + 1) % (3 * MyRes::astrd_frcnt);
	setPixmap(astrd_frms[(frm_num / 3) % MyRes::astrd_frcnt]->scaled(MyRes::astrd_size, Qt::KeepAspectRatio,
	                                                                 Qt::SmoothTransformation));
	QPointF tplft(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().topLeft()))));
	QPointF bttmrght(scene()->views().first()->viewport()->mapToParent(
			scene()->views().first()->mapFromScene(mapToScene(boundingRect().bottomRight()))));
	QRectF vw_rct(scene()->views().first()->viewport()->rect());
	setPos(pos().x() + vlc->x(), pos().y());
	if ((tplft.y() + vlc->y() >= 0 && bttmrght.y() + vlc->y() <= vw_rct.height()) ||
	    (tplft.y() + vlc->y() < 0 && vlc->y() > 0) ||
	    (bttmrght.y() + vlc->y() > vw_rct.height() && vlc->y() < 0)) {
		setPos(pos().x(), pos().y() + vlc->y());
	}
	else {
		vlc->setY(vlc->y() * (-1));
	}
	if (grv) {
		grv_fld->setRect(sceneBoundingRect().x() + pixmap().width() / 2 - MyRes::astrd_grv_size.width() / 2,
		                 sceneBoundingRect().y() + pixmap().height() / 2 - MyRes::astrd_grv_size.height() / 2,
		                 MyRes::astrd_grv_size.width(), MyRes::astrd_grv_size.height());
	}
}