//
// Created by kahrabian on 7/5/15.
//

#include "../Headers/MyTutorial.h"

MyTutorial::MyTutorial(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    resize(MyRes::app_size);
    setStyleSheet("MyTutorial " + MyRes::background_add);
    back = new QPushButton("Back", this);
    cnstrct_logo();
    cnstrct_txt();
    cnstrct_ttrl();
}

MyTutorial::~MyTutorial() { }

void MyTutorial::cnstrct_ttrl()
{
    ttrl = new QVBoxLayout(this);
    ttrl->addWidget(logo);
    ttrl->addWidget(txt);
    ttrl->addWidget(back);
}

void MyTutorial::cnstrct_txt()
{
    txt = new QTextEdit(MyRes::ttrl_txt, this);
    txt->setReadOnly(true);
    txt->setStyleSheet(MyRes::ttrl_txt_stlsheet);
    txt->setFocusPolicy(Qt::NoFocus);
}

void MyTutorial::cnstrct_logo()
{
    logo = new QLabel(this);
    QPixmap *my_pix = new QPixmap(MyRes::logo_add);
    logo->setPixmap(*my_pix);
    logo->setAlignment(Qt::AlignHCenter);
    logo->setAttribute(Qt::WA_TranslucentBackground, true);
}

void MyTutorial::paintEvent(QPaintEvent *my_event)
{
    QPainter *my_painter = new QPainter(this);
    QStyleOption *my_option = new QStyleOption();
    my_option->init(this);
    style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
    QWidget::paintEvent(my_event);
}