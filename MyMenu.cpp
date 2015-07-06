//
// Created by kahrabian on 7/3/15.
//

#include "MyMenu.h"

MyMenu::MyMenu(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    this->resize(1120, 630);
    this->setStyleSheet("image: url(/home/kahrabian/ClionProjects/Shooter-AP93UT/Contents/background_menu.jpg);");
    this->construct_buttons();
    this->construct_logo();
    this->construct_menu();
}

MyMenu::~MyMenu()
{
}

void MyMenu::construct_menu()
{
    this->menu = new QVBoxLayout(this);
    this->menu->addWidget(this->logo);
    this->menu->addSpacing(630);
    this->menu->addLayout(this->buttons);
}

void MyMenu::construct_buttons()
{
    this->buttons = new QHBoxLayout();
    this->start = new QPushButton("Start", this);
    this->buttons->addWidget(this->start);
    this->setting = new QPushButton("Setting", this);
    this->buttons->addWidget(this->setting);
    this->tutorial = new QPushButton("Tutorial", this);
    this->buttons->addWidget(this->tutorial);
    this->exit = new QPushButton("Exit", this);
    this->buttons->addWidget(this->exit);
}

void MyMenu::construct_logo()
{
    this->logo = new QLabel(this);
    QPixmap *my_pix = new QPixmap("/home/kahrabian/ClionProjects/Shooter-AP93UT/Contents/logo.png");
    this->logo->setPixmap(*my_pix);
    this->logo->setAlignment(Qt::AlignHCenter);
    this->logo->setAttribute(Qt::WA_TranslucentBackground);
    delete my_pix;
}

void MyMenu::paintEvent(QPaintEvent *my_event)
{
    QPainter *my_painter = new QPainter(this);
    QStyleOption *my_option = new QStyleOption();
    my_option->init(this);
    this->style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
    QWidget::paintEvent(my_event);
}