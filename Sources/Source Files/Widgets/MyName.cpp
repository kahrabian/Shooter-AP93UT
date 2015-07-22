//
// Created by kahrabian on 7/16/15.
//

#include <Sources/Headers/Widgets/MyName.h>

MyName::MyName(QWidget *parent, Qt::WindowFlags f) :
		QWidget(parent, f) {
	resize(MyRes::app_size);
	setStyleSheet("MyName " + MyRes::background_add);
	nm_lay = new QVBoxLayout(this);
	cnstrct_logo();
	cnstrct_frm();
	cnstrct_btns();
	cnstrct_nm();
}

MyName::~MyName() { }

void MyName::reset() {
	if (SettingData::gMode == 3) {
		scnd_nm_lbl->hide();
		scnd_nm_txt->hide();
		frst_nm_lbl->setText("Player name:");
	}
	else {
		scnd_nm_lbl->show();
		scnd_nm_txt->show();
		frst_nm_lbl->setText("First player name:");
	}
}

void MyName::cnstrct_nm() {
	nm_lay->addWidget(logo);
//	nm_lay->addLayout(frst_nm_lay);
	nm_lay->addLayout(frm_lay);
	nm_lay->addLayout(btns);
}

void MyName::cnstrct_btns() {
	btns = new QHBoxLayout();
	strt = new QPushButton("Start", this);
	btns->addWidget(strt);
	back = new QPushButton("Back", this);
	btns->addWidget(back);
}

void MyName::cnstrct_frm() {
	frm_lay = new QVBoxLayout();
	frm_lay->setAlignment(Qt::AlignTop);

	scnd_nm_lay = new QHBoxLayout();
	scnd_nm_lbl = new QLabel("Second player name:", this);
	scnd_nm_lbl->setStyleSheet(MyRes::lbl_stlsheet);
	scnd_nm_lay->addWidget(scnd_nm_lbl);
	scnd_nm_txt = new QLineEdit(this);
	scnd_nm_txt->setStyleSheet(MyRes::nm_txt_stlsheet);
	scnd_nm_txt->setText(SettingData::p2_nm);
	scnd_nm_lay->addWidget(scnd_nm_txt);

	frst_nm_lay = new QHBoxLayout();
	frst_nm_lbl = new QLabel("First player name:", this);
	frst_nm_lbl->setStyleSheet(MyRes::lbl_stlsheet);
	frst_nm_lay->addWidget(frst_nm_lbl);
	frst_nm_lay->addSpacing(scnd_nm_lbl->fontMetrics().width("Second player name:  ") -
	                        frst_nm_lbl->fontMetrics().width("First player name:") - 1);
	frst_nm_txt = new QLineEdit(this);
	frst_nm_txt->setStyleSheet(MyRes::nm_txt_stlsheet);
	frst_nm_txt->setText(SettingData::p1_nm);
	frst_nm_txt->setFocus();
	frst_nm_lay->addWidget(frst_nm_txt);

	frm_lay->addLayout(frst_nm_lay);
	frm_lay->addSpacing(50);
	frm_lay->addLayout(scnd_nm_lay);
}

void MyName::cnstrct_logo() {
	logo = new QLabel(this);
	logo->setPixmap(QPixmap(MyRes::logo_add));
	logo->setAlignment(Qt::AlignHCenter);
	logo->setAttribute(Qt::WA_TranslucentBackground);
}

void MyName::paintEvent(QPaintEvent *my_event) {
	QPainter *my_painter = new QPainter(this);
	QStyleOption *my_option = new QStyleOption();
	my_option->init(this);
	style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
	QWidget::paintEvent(my_event);
}