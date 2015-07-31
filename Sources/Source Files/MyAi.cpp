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
}

void MyAi::updt() {
	gnrt_cmmnds();
	shp->updt(cmmnds);
}