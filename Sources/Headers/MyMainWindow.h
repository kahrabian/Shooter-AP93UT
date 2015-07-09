//
// Created by kahrabian on 7/4/15.
//

#ifndef SHOOTER_AP93UT_MYMAINWINDOW_H
#define SHOOTER_AP93UT_MYMAINWINDOW_H


#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qstackedwidget.h>
#include <QtWidgets/qdesktopwidget.h>
#include <QtMultimedia/qmediaplayer.h>
#include "Resources.h"
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
    void exit_bttn_clicked();
    void ttrl_bttn_clicked();
    void stng_bttn_clicked();
    void back_bttn_clicked();


private:
    QMediaPlayer *med_player;
    QStackedWidget *widget_stack;
    MyMenu *menu;
    MyTutorial *ttrl;
    MySetting *stng;
//    MyGame *game;

    void set_init_pos();
    void set_prpts();
    void cnstrct_stack();
    void set_cnctns();
};


#endif //SHOOTER_AP93UT_MYMAINWINDOW_H
