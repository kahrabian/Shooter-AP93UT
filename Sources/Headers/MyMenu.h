//
// Created by kahrabian on 7/3/15.
//

#ifndef SHOOTER_AP93UT_MENU_H
#define SHOOTER_AP93UT_MENU_H


#include <QtWidgets/qwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qstyleoption.h>
#include <QtGui/qpainter.h>
#include "Resources.h"

class MyMenu : public QWidget
{
    Q_OBJECT
    friend class MyMainWindow;
public:
    MyMenu(QWidget * = 0, Qt::WindowFlags = 0);
    ~MyMenu();

private:
    QHBoxLayout *btns;
    QVBoxLayout *menu;
    QPushButton *exit;
    QPushButton *start;
    QPushButton *stng;
    QPushButton *ttrl;
    QLabel *logo;

    void cnstrct_btns();
    void cnstrct_logo();
    void cnstrct_menu();
    void paintEvent(QPaintEvent *);
};


#endif //SHOOTER_AP93UT_MENU_H
