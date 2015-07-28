//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game Objects/MyAsteroid.h>

MyAsteroid::MyAsteroid() :
		QGraphicsPixmapItem(), QObject() {
	astrd_frms = new QPixmap[MyRes::astrd_frcnt];
	astrd_num = rand() % MyRes::astrd_typcnt;
	frm_num = 0;
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(-10, 0);
	for (int i = 0; i < MyRes::astrd_frcnt; i++)
		astrd_frms[i] = QPixmap(MyRes::astrd_adds[astrd_num][i]).scaled(MyRes::astrd_size, Qt::KeepAspectRatio,
		                                                                Qt::SmoothTransformation);
	setPixmap(astrd_frms[0]);
}

MyAsteroid::~MyAsteroid() {

}

void MyAsteroid::updt() {
	frm_num = (frm_num + 1) % (3 * MyRes::astrd_frcnt);
	setPixmap(astrd_frms[(frm_num / 3) % MyRes::astrd_frcnt]);
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}