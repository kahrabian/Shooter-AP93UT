//
// Created by kahrabian on 7/5/15.
//

#include <Sources/Headers/MyTutorial.h>

MyTutorial::MyTutorial(QWidget *parent, Qt::WindowFlags f) :
		QWidget(parent, f) {
	resize(MyRes::app_size);
	setStyleSheet("MyTutorial " + MyRes::background_add);
	back = new QPushButton("Back", this);
	cnstrct_logo();
	cnstrct_ttrl();
}

MyTutorial::~MyTutorial() { }

void MyTutorial::cnstrct_ttrl() {
	ttrl = new QVBoxLayout(this);
	ttrl->addWidget(logo);
	txt = new QHBoxLayout();
	cnstrct_rule();
	cnstrct_howto();
	txt->addLayout(howto_lay);
	txt->addLayout(rule_lay);
	ttrl->addLayout(txt);
	ttrl->addWidget(back);
}

void MyTutorial::cnstrct_rule() {
	rule_lay = new QVBoxLayout();
	rule = new QTextEdit(MyRes::ttrl_rule, this);
	rule_txt = new QLabel("Games Rule:", this);
	rule_txt->setStyleSheet(MyRes::lbl_bstlsheet);
	rule->setReadOnly(true);
	rule->setStyleSheet(MyRes::ttrl_txt_stlsheet);
	rule->setFocusPolicy(Qt::NoFocus);
	rule_lay->addWidget(rule_txt);
	rule_lay->addWidget(rule);
}

void MyTutorial::cnstrct_howto() {
	howto_lay = new QVBoxLayout();
	howto_txt = new QLabel("How To Play:", this);
	howto_txt->setStyleSheet(MyRes::lbl_bstlsheet);
	howto = new QTextEdit(MyRes::ttrl_howto, this);
	howto->setReadOnly(true);
	howto->setStyleSheet(MyRes::ttrl_txt_stlsheet);
	howto->setFocusPolicy(Qt::NoFocus);
	howto_lay->addWidget(howto_txt);
	howto_lay->addWidget(howto);
}

void MyTutorial::cnstrct_logo() {
	logo = new QLabel(this);
	logo->setPixmap(QPixmap(MyRes::logo_add));
	logo->setAlignment(Qt::AlignHCenter);
	logo->setAttribute(Qt::WA_TranslucentBackground, true);
}

void MyTutorial::paintEvent(QPaintEvent *my_event) {
	QPainter *my_painter = new QPainter(this);
	QStyleOption *my_option = new QStyleOption();
	my_option->init(this);
	style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
	QWidget::paintEvent(my_event);
}