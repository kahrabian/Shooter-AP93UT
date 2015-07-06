//
// Created by kahrabian on 7/4/15.
//

#include "MyMainWindow.h"

MyMainWindow::MyMainWindow(QWidget * parent, Qt::WindowFlags flag) :
        QMainWindow(parent, flag)
{
    this->construct_stack();
    this->set_properties();
    this->set_connections();
}

MyMainWindow::~MyMainWindow()
{
}

void MyMainWindow::exit_button_clicked()
{
    this->close();
}

void MyMainWindow::back_button_clicked()
{
    this->widget_stack->setCurrentWidget(this->menu);
}

void MyMainWindow::tutorial_button_clicked()
{
    this->widget_stack->setCurrentWidget(this->tutorial);
}

void MyMainWindow::set_initial_position()
{
    QDesktopWidget desktop;
    this->setGeometry((desktop.screen()->width() / 2) - (this->frameGeometry().width() / 2), (desktop.screen()->height() / 2) - (this->frameGeometry().height() / 2), this->frameGeometry().width(), this->frameGeometry().height());
}

void MyMainWindow::set_properties()
{
    this->setFixedSize(1120, 630);
    this->set_initial_position();
    this->setWindowTitle("Awsome Space Shooter");
    QIcon *icon = new QIcon("/home/kahrabian/ClionProjects/Shooter-AP93UT/Contents/icon.ico");
    this->setWindowIcon(*icon);
    this->setCentralWidget(widget_stack);
    this->show();
    delete icon;
}

void MyMainWindow::construct_stack()
{
    this->widget_stack = new QStackedWidget(this);
    this->menu = new MyMenu(widget_stack);
    this->widget_stack->addWidget(menu);
    this->tutorial = new MyTutorial(widget_stack);
    this->widget_stack->addWidget(tutorial);
}

void MyMainWindow::set_connections()
{
    QObject::connect(this->menu->exit, SIGNAL(clicked()), this, SLOT(exit_button_clicked()));
    QObject::connect(this->tutorial->back, SIGNAL(clicked()), this, SLOT(back_button_clicked()));
    QObject::connect(this->menu->tutorial, SIGNAL(clicked()), this, SLOT(tutorial_button_clicked()));
}