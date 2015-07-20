//
// Created by kahrabian on 7/13/15.
//

#include <Sources/Headers/Game/MyStar.h>

MyStar::MyStar(QGraphicsItem *parent) :
		QGraphicsPixmapItem(parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0.0, 0.0);
}

MyStar::MyStar(const QPixmap &pixmap, QGraphicsItem *parent) :
		QGraphicsPixmapItem(pixmap, parent) {
	setGraphicsEffect(new QGraphicsDropShadowEffect());
	vlc = new QPointF(0.0, 0.0);
}

MyStar::~MyStar() {

}

void MyStar::setVlc(QPointF *vlc) {
	MyStar::vlc = vlc;
}

QPointF *MyStar::getVlc() const {
	return vlc;
}

void MyStar::updt() {
	setPos(pos().x() + vlc->x(), pos().y() + vlc->y());
}
