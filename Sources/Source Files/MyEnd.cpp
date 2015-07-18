//
// Created by kahrabian on 7/17/15.
//

#include "../Headers/MyEnd.h"

MyEnd::MyEnd(QWidget *parent, Qt::WindowFlags f) :
		QWidget(parent, f) {
	resize(MyRes::app_size);
	setStyleSheet("MyEnd " + MyRes::background_add);
	cnstrct_btns();
	cnstrct_logo();
	cnstrct_end();
}

MyEnd::~MyEnd() { }

void MyEnd::cnstrct_end() {
	end = new QVBoxLayout(this);
	end->addWidget(logo);
	txt = new QLabel("Something goes here ...", this);
	txt->setStyleSheet(MyRes::lbl_bstlsheet);
	txt->setAlignment(Qt::AlignCenter);
	end->addWidget(txt);
	end->addLayout(btns);
}

void MyEnd::cnstrct_btns() {
	btns = new QHBoxLayout();
	rest = new QPushButton("Restart", this);
	btns->addWidget(rest);
	exit = new QPushButton("Exit", this);
	btns->addWidget(exit);
}

void MyEnd::cnstrct_logo() {
	logo = new QLabel(this);
	logo->setPixmap(QPixmap(MyRes::logo_add));
	logo->setAlignment(Qt::AlignHCenter);
	logo->setAttribute(Qt::WA_TranslucentBackground);
}

void MyEnd::paintEvent(QPaintEvent *my_event) {
	QPainter *my_painter = new QPainter(this);
	QStyleOption *my_option = new QStyleOption();
	my_option->init(this);
	style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
	QWidget::paintEvent(my_event);
}