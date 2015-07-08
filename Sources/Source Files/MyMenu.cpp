//
// Created by kahrabian on 7/3/15.
//

#include "../Headers/MyMenu.h"

MyMenu::MyMenu(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    resize(1120, 630);
    setStyleSheet("MyMenu {background-image: url(/home/kahrabian/ClionProjects/Shooter-AP93UT/Resources/background.jpg);}");
    cnstrct_btns();
    cnstrct_logo();
    cnstrct_menu();
}

MyMenu::~MyMenu()
{
}

void MyMenu::cnstrct_menu()
{
    menu = new QVBoxLayout(this);
    menu->addWidget(logo);
    menu->addSpacing(630);
    menu->addLayout(btns);
}

void MyMenu::cnstrct_btns()
{
    btns = new QHBoxLayout();
    start = new QPushButton("Start", this);
    btns->addWidget(start);
    stng = new QPushButton("Setting", this);
    btns->addWidget(stng);
    ttrl = new QPushButton("Tutorial", this);
    btns->addWidget(ttrl);
    exit = new QPushButton("Exit", this);
    btns->addWidget(exit);
}

void MyMenu::cnstrct_logo()
{
    logo = new QLabel(this);
    QPixmap *my_pix = new QPixmap("/home/kahrabian/ClionProjects/Shooter-AP93UT/Resources/logo.png");
    logo->setPixmap(*my_pix);
    logo->setAlignment(Qt::AlignHCenter);
    logo->setAttribute(Qt::WA_TranslucentBackground);
    delete my_pix;
}

void MyMenu::paintEvent(QPaintEvent *my_event)
{
    QPainter *my_painter = new QPainter(this);
    QStyleOption *my_option = new QStyleOption();
    my_option->init(this);
    style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
    QWidget::paintEvent(my_event);
}