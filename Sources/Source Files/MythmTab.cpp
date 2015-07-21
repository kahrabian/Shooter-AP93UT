//
// Created by kahrabian on 7/11/15.
//

#include <Sources/Headers/MythmTab.h>

MythmTab::MythmTab(QWidget *parent, Qt::WindowFlags f) :
		QWidget(parent, f) {
	setStyleSheet(MyRes::wdg_stlsheet);
	thmTab_lay = new QHBoxLayout(this);
	cnstrct_spc();
	cnstrct_env();
	thmTab_lay->addLayout(spc_lay);
	thmTab_lay->addLayout(env_lay);
	show();
}

MythmTab::~MythmTab() { }

void MythmTab::cnstrct_spc() {
	spc_lay = new QVBoxLayout();
	spc_pic = new QLabel(this);
	spc_pic->setFixedSize(MyRes::img_init_size);
	spc_pic->setPixmap(QPixmap(MyRes::shp_adds[SettingData::uShp]).scaled(spc_pic->size(), Qt::KeepAspectRatio,
	                                                                      Qt::SmoothTransformation));
	spc_pic->setAlignment(Qt::AlignCenter);
	spc_pic->setAttribute(Qt::WA_TranslucentBackground);
	spc_lay->addWidget(spc_pic);
	spcbtn_lay = new QHBoxLayout();
	spc_prebtn = new QToolButton(this);
	spc_prebtn->setArrowType(Qt::LeftArrow);
	spcbtn_lay->addWidget(spc_prebtn);
	spc_txt = new QLabel("User Space Ship", this);
	spc_txt->setStyleSheet(MyRes::lbl_stlsheet);
	spc_txt->setAlignment(Qt::AlignCenter);
	spcbtn_lay->addWidget(spc_txt);
	spc_nexbtn = new QToolButton(this);
	spc_nexbtn->setArrowType(Qt::RightArrow);
	spcbtn_lay->addWidget(spc_nexbtn);
	spc_lay->addLayout(spcbtn_lay);
}

void MythmTab::cnstrct_env() {
	env_lay = new QVBoxLayout();
	env_pic = new QLabel(this);
	env_pic->setFixedSize(MyRes::img_init_size);
	env_pic->setPixmap(QPixmap(MyRes::env_adds[SettingData::env]).scaled(env_pic->size(), Qt::KeepAspectRatio,
	                                                                     Qt::SmoothTransformation));
	env_pic->setAlignment(Qt::AlignCenter);
	env_pic->setAttribute(Qt::WA_TranslucentBackground);
	env_lay->addWidget(env_pic);
	envbtn_lay = new QHBoxLayout();
	env_prebtn = new QToolButton(this);
	env_prebtn->setArrowType(Qt::LeftArrow);
	envbtn_lay->addWidget(env_prebtn);
	env_txt = new QLabel("Environment", this);
	env_txt->setAlignment(Qt::AlignCenter);
	env_txt->setStyleSheet(MyRes::lbl_stlsheet);
	envbtn_lay->addWidget(env_txt);
	env_nexbtn = new QToolButton(this);
	env_nexbtn->setArrowType(Qt::RightArrow);
	envbtn_lay->addWidget(env_nexbtn);
	env_lay->addLayout(envbtn_lay);
}

void MythmTab::paintEvent(QPaintEvent *my_event) {
	QPainter *my_painter = new QPainter(this);
	QStyleOption *my_option = new QStyleOption();
	my_option->init(this);
	style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
	QWidget::paintEvent(my_event);
}
