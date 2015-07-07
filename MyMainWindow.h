//
// Created by kahrabian on 7/4/15.
//

#ifndef SHOOTER_AP93UT_MYMAINWINDOW_H
#define SHOOTER_AP93UT_MYMAINWINDOW_H


#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qstackedwidget.h>
#include <QtWidgets/qdesktopwidget.h>
#include "MyMenu.h"
#include "MyTutorial.h"
#include "MySetting.h"

class MyMainWindow : QMainWindow
{
    Q_OBJECT
public:
    MyMainWindow(QWidget * = 0, Qt::WindowFlags = 0);
    ~MyMainWindow();

public slots:
    void exit_button_clicked();
    void tutorial_button_clicked();
    void setting_button_clicked();
    void back_button_clicked();


private:
    QStackedWidget *widget_stack;
    MyMenu *menu;
    MyTutorial *tutorial;
    MySetting *setting;
//    MyGame *game;
    void set_initial_position();
    void set_properties();
    void construct_stack();
    void set_connections();
};


#endif //SHOOTER_AP93UT_MYMAINWINDOW_H
