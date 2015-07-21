//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game/MyStar.h>

MyStar::MyStar(QGraphicsItem *parent) :
		QGraphicsPixmapItem(QPixmap(MyRes::str_add).scaled(MyRes::str_size, Qt::KeepAspectRatio,
		                                                   Qt::SmoothTransformation), parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0, 0);
}

MyStar::~MyStar() {

}

void MyStar::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}
