//
// Created by kahrabian on 7/3/15.
//

#include "../Headers/MyMenu.h"

MyMenu::MyMenu(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    resize(MyRes::app_size);
    setStyleSheet("MyMenu " + MyRes::background_add);
    cnstrct_btns();
    cnstrct_logo();
    cnstrct_menu();
}

MyMenu::~MyMenu() { }

void MyMenu::cnstrct_menu()
{
    menu = new QVBoxLayout(this);
    menu->addWidget(logo);
    menu->addLayout(btns);
}

void MyMenu::cnstrct_btns()
{
    QFile file(MyRes::stng_add);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&file);
    QString tmp;
    stream >> tmp;

    btns = new QHBoxLayout();
    rsm = new QPushButton("Resume", this);
    btns->addWidget(rsm);
    if(tmp == "0")
        rsm->hide();
    start = new QPushButton("New Game", this);
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
    QPixmap *my_pix = new QPixmap(MyRes::logo_add);
    logo->setPixmap(*my_pix);
    logo->setAlignment(Qt::AlignHCenter);
    logo->setAttribute(Qt::WA_TranslucentBackground);
}

void MyMenu::paintEvent(QPaintEvent *my_event)
{
    QPainter *my_painter = new QPainter(this);
    QStyleOption *my_option = new QStyleOption();
    my_option->init(this);
    style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
    QWidget::paintEvent(my_event);
}