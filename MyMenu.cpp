//
// Created by kahrabian on 7/3/15.
//

#include "MyMenu.h"

MyMenu::MyMenu(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    resize(1120, 630);
    setStyleSheet("image: url(/home/kahrabian/ClionProjects/Shooter-AP93UT/Contents/background_menu.jpg);");
    construct_buttons();
    construct_logo();
    construct_menu();
}

MyMenu::~MyMenu()
{
}

void MyMenu::construct_menu()
{
    menu = new QVBoxLayout(this);
    menu->addWidget(logo);
    menu->addSpacing(630);
    menu->addLayout(buttons);
}

void MyMenu::construct_buttons()
{
    buttons = new QHBoxLayout();
    start = new QPushButton("Start", this);
    buttons->addWidget(start);
    setting = new QPushButton("Setting", this);
    buttons->addWidget(setting);
    tutorial = new QPushButton("Tutorial", this);
    buttons->addWidget(tutorial);
    exit = new QPushButton("Exit", this);
    buttons->addWidget(exit);
}

void MyMenu::construct_logo()
{
    logo = new QLabel(this);
    QPixmap *my_pix = new QPixmap("/home/kahrabian/ClionProjects/Shooter-AP93UT/Contents/logo.png");
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