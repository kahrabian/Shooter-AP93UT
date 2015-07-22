//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game Objects/MyAlien.h>

MyAlien::MyAlien(QGraphicsItem *parent) :
		QGraphicsPixmapItem(
				QPixmap(MyRes::aln_nrml_adds[rand() % MyRes::aln_nrml_cnt]).scaled(140, 140, Qt::KeepAspectRatio,
		                                                   Qt::SmoothTransformation), parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
	tmr_id = startTimer(1000);
}

MyAlien::~MyAlien() {

}

void MyAlien::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}

void MyAlien::timerEvent(QTimerEvent *event) {
	for (int i = -45; i <= 45; i += 9) {
		MyBullet *tmp = new MyBullet(1, i, -1);
		tmp->setPos(pos().x(),
		            pos().y() + (pixmap().height() / 2) - (MyRes::lsr_size.height() / 2));
		scene()->addItem(tmp);
	}

//	MyBullet *tmp = new MyBullet(1, 0, -1);
//	tmp->setPos(pos().x(),
//	            pos().y() + (pixmap().height() / 2) - (MyRes::lsr_size.height() / 2));
//	scene()->addItem(tmp);
}


