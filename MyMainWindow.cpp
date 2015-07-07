//
// Created by kahrabian on 7/4/15.
//

#include "MyMainWindow.h"

MyMainWindow::MyMainWindow(QWidget * parent, Qt::WindowFlags flag) :
        QMainWindow(parent, flag)
{
    construct_stack();
    set_properties();
    set_connections();
}

MyMainWindow::~MyMainWindow()
{
}

void MyMainWindow::exit_button_clicked()
{
    close();
}

void MyMainWindow::back_button_clicked()
{
    widget_stack->setCurrentWidget(menu);
}

void MyMainWindow::tutorial_button_clicked()
{
    widget_stack->setCurrentWidget(tutorial);
}

void MyMainWindow::setting_button_clicked()
{
    widget_stack->setCurrentWidget(setting);
}

void MyMainWindow::set_initial_position()
{
    QDesktopWidget desktop;
    setGeometry((desktop.screen()->width() / 2) - (frameGeometry().width() / 2), (desktop.screen()->height() / 2) - (frameGeometry().height() / 2), frameGeometry().width(), frameGeometry().height());
}

void MyMainWindow::set_properties()
{
    setFixedSize(1120, 630);
    set_initial_position();
    setWindowTitle("Awsome Space Shooter");
    QIcon *icon = new QIcon("/home/kahrabian/ClionProjects/Shooter-AP93UT/Contents/icon.ico");
    setWindowIcon(*icon);
    setCentralWidget(widget_stack);
    show();
    delete icon;
}

void MyMainWindow::construct_stack()
{
    widget_stack = new QStackedWidget(this);
    menu = new MyMenu(widget_stack);
    widget_stack->addWidget(menu);
    tutorial = new MyTutorial(widget_stack);
    widget_stack->addWidget(tutorial);
    setting = new MySetting(widget_stack);
    widget_stack->addWidget(setting);
}

void MyMainWindow::set_connections()
{
    QObject::connect(menu->exit, SIGNAL(clicked()), this, SLOT(exit_button_clicked()));
    QObject::connect(menu->tutorial, SIGNAL(clicked()), this, SLOT(tutorial_button_clicked()));
    QObject::connect(menu->setting, SIGNAL(clicked()), this, SLOT(setting_button_clicked()));
    QObject::connect(tutorial->back, SIGNAL(clicked()), this, SLOT(back_button_clicked()));
    QObject::connect(setting->back, SIGNAL(clicked()), this, SLOT(back_button_clicked()));
}