//
// Created by kahrabian on 7/12/15.
//

#include "../../Headers/Game/MyShip.h"

MyShip::MyShip(QGraphicsItem *parent) :
        QGraphicsPixmapItem(parent)
{

}

MyShip::MyShip(const QPixmap &pixmap, QGraphicsItem *parent) :
        QGraphicsPixmapItem(pixmap, parent)
{

}

MyShip::~MyShip()
{

}

int MyShip::getLf() const
{
	return lf;
}

void MyShip::setLf(int lf)
{
	MyShip::lf = lf;
}

int MyShip::getScr() const
{
	return scr;
}

void MyShip::setScr(int scr)
{
	MyShip::scr = scr;
}

bool MyShip::isShld() const
{
	return shld;
}

void MyShip::setShld(bool shld)
{
	MyShip::shld = shld;
}

bool MyShip::isMgc() const
{
	return mgc;
}

void MyShip::setMgc(bool mgc)
{
	MyShip::mgc = mgc;
}

void MyShip::updt(qint64)
{

}