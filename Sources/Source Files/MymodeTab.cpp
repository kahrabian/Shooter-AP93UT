//
// Created by kahrabian on 7/11/15.
//

#include "../Headers/MymodeTab.h"

MymodeTab::MymodeTab(QWidget *parent, Qt::WindowFlags f) :
		QWidget(parent, f) {
	setStyleSheet(MyRes::wdg_stlsheet);
	modeTab_lay = new QHBoxLayout(this);
	cnstrct_mode();
	cnstrct_diff();
	modeTab_lay->addLayout(gMod_lay);
	modeTab_lay->addLayout(gDiff_lay);
	show();
}

MymodeTab::~MymodeTab() { }

void MymodeTab::cnstrct_mode() {
	gMod_lay = new QVBoxLayout();
	gMod_lay->setAlignment(Qt::AlignTop);
	gMod_txt = new QLabel("Game Mode:", this);
	gMod_txt->setStyleSheet(MyRes::lbl_bstlsheet);
	gMod_lay->addWidget(gMod_txt);
	gMods = new QButtonGroup();
	gMod_sng = new QRadioButton("Single", this);
	gMod_sng->setStyleSheet(MyRes::rdbtn_stlsheet);
	gMod_sng->setChecked(true);
	gMods->addButton(gMod_sng, 1);
	gMod_lay->addWidget(gMod_sng);
	gMod_co = new QRadioButton("Co-Op", this);
	gMod_co->setStyleSheet(MyRes::rdbtn_stlsheet);
	gMods->addButton(gMod_co, 2);
	gMod_lay->addWidget(gMod_co);
	gMod_vs = new QRadioButton("vs Ai", this);
	gMod_vs->setStyleSheet(MyRes::rdbtn_stlsheet);
	gMods->addButton(gMod_vs, 3);
	gMod_lay->addWidget(gMod_vs);
}

void MymodeTab::cnstrct_diff() {
	gDiff_lay = new QVBoxLayout();
	gDiff_lay->setAlignment(Qt::AlignTop);
	gDiff_txt = new QLabel("Game Difficulty:", this);
	gDiff_txt->setStyleSheet(MyRes::lbl_bstlsheet);
	gDiff_lay->addWidget(gDiff_txt);
	gDiffs = new QButtonGroup();
	gDiff_eas = new QRadioButton("Easy", this);
	gDiff_eas->setStyleSheet(MyRes::rdbtn_stlsheet);
	gDiff_eas->setChecked(true);
	gDiffs->addButton(gDiff_eas, 1);
	gDiff_lay->addWidget(gDiff_eas);
	gDiff_nor = new QRadioButton("Normal", this);
	gDiff_nor->setStyleSheet(MyRes::rdbtn_stlsheet);
	gDiffs->addButton(gDiff_nor, 2);
	gDiff_lay->addWidget(gDiff_nor);
	gDiff_har = new QRadioButton("Hard", this);
	gDiff_har->setStyleSheet(MyRes::rdbtn_stlsheet);
	gDiffs->addButton(gDiff_har, 3);
	gDiff_lay->addWidget(gDiff_har);
	gDiff_ext = new QRadioButton("Extreme", this);
	gDiff_ext->setStyleSheet(MyRes::rdbtn_stlsheet);
	gDiffs->addButton(gDiff_ext, 4);
	gDiff_lay->addWidget(gDiff_ext);
}

void MymodeTab::paintEvent(QPaintEvent *my_event) {
	QPainter *my_painter = new QPainter(this);
	QStyleOption *my_option = new QStyleOption();
	my_option->init(this);
	style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
	QWidget::paintEvent(my_event);
}

