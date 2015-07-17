//
// Created by kahrabian on 7/16/15.
//

#include "../Headers/MyPause.h"

MyPause::MyPause(QWidget *parent, Qt::WindowFlags f) :
		QWidget(parent, f)
{
	resize(MyRes::app_size);
	cnstrct_btns();
	cnstrct_logo();
	cnstrct_ps();
	set_cnctns();
}

MyPause::~MyPause() { }

void MyPause::set_cnctns()
{
	QObject::connect(aud->sndEffs_sli , SIGNAL(valueChanged(int)), this, SLOT(update_stng()));
	QObject::connect(aud->sndEffs_mute , SIGNAL(stateChanged(int)), this, SLOT(update_stng()));
	QObject::connect(aud->muse_sli , SIGNAL(valueChanged(int)), this, SLOT(update_stng()));
	QObject::connect(aud->muse_mute , SIGNAL(stateChanged(int)), this, SLOT(update_stng()));
}

void MyPause::update_stng()
{
	SettingData::mVol = aud->muse_sli->value();
	SettingData::mMut = aud->muse_mute->isChecked();
	SettingData::sfVol = aud->sndEffs_sli->value();
	SettingData::sfMut = aud->sndEffs_mute->isChecked();
	emit settingChanged();
}

void MyPause::cnstrct_ps()
{
	ps_lay = new QVBoxLayout(this);
	ps_lay->addWidget(logo);
	aud = new MyaudioTab(this);
	ps_lay->addWidget(aud);
	ps_lay->addLayout(btns);
}

void MyPause::cnstrct_btns()
{
	btns = new QHBoxLayout();
	resm = new QPushButton("Resume", this);
	btns->addWidget(resm);
	rest = new QPushButton("Restart", this);
	btns->addWidget(rest);
	exit = new QPushButton("Exit", this);
	btns->addWidget(exit);
}

void MyPause::cnstrct_logo()
{
	logo = new QLabel(this);
	logo->setPixmap(QPixmap(MyRes::logo_add));
	logo->setAlignment(Qt::AlignHCenter);
	logo->setAttribute(Qt::WA_TranslucentBackground);
}

void MyPause::set_bckgrnd()
{
	setStyleSheet("MyPause " + MyRes::ps_stlsheet);
}

void MyPause::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_Escape)
		emit gameUnpaused();
	QWidget::keyPressEvent(event);
}

void MyPause::paintEvent(QPaintEvent *my_event)
{
	QPainter *my_painter = new QPainter(this);
	QStyleOption *my_option = new QStyleOption();
	my_option->init(this);
	style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
	QWidget::paintEvent(my_event);
}