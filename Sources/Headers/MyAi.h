//
// Created by kahrabian on 7/31/15.
//

#ifndef SHOOTER_AP93UT_MYAI_H
#define SHOOTER_AP93UT_MYAI_H

#include <Sources/Headers/Game Objects/MyShip.h>

class MyAi {
public:
	MyAi(MyShip *);

	~MyAi();

	void updt();

private:
	MyShip *shp;
	QSet<int> *cmmnds;

	void gnrt_cmmnds();
};

#endif //SHOOTER_AP93UT_MYAI_H
