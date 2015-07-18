//
// Created by kahrabian on 7/11/15.
//

#ifndef SHOOTER_AP93UT_MYMODETAB_H
#define SHOOTER_AP93UT_MYMODETAB_H


#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QCheckBox>
#include <QStyleOption>
#include <QPainter>
#include <QRadioButton>
#include <QButtonGroup>
#include "Resources.h"

class MymodeTab : public QWidget {
Q_OBJECT

	friend class MySetting;

public:
	MymodeTab(QWidget * = 0, Qt::WindowFlags = 0);

	~MymodeTab();

private:
	QHBoxLayout *modeTab_lay;
	QVBoxLayout *gMod_lay;
	QLabel *gMod_txt;
	QButtonGroup *gMods;
	QRadioButton *gMod_sng;
	QRadioButton *gMod_co;
	QRadioButton *gMod_vs;
	QVBoxLayout *gDiff_lay;
	QLabel *gDiff_txt;
	QButtonGroup *gDiffs;
	QRadioButton *gDiff_eas;
	QRadioButton *gDiff_nor;
	QRadioButton *gDiff_har;
	QRadioButton *gDiff_ext;

	void cnstrct_mode();

	void cnstrct_diff();

	void paintEvent(QPaintEvent *);
};

#endif //SHOOTER_AP93UT_MYMODETAB_H
