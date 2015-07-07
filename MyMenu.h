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


class MyMenu : public QWidget
{
    Q_OBJECT
    friend class MyMainWindow;
public:
    MyMenu(QWidget * = 0, Qt::WindowFlags = 0);
    ~MyMenu();

private:
    QHBoxLayout *buttons;
    QVBoxLayout *menu;
    QPushButton *exit;
    QPushButton *start;
    QPushButton *setting;
    QPushButton *tutorial;
    QLabel *logo;

    void construct_buttons();
    void construct_logo();
    void construct_menu();
    void paintEvent(QPaintEvent *);
};


#endif //SHOOTER_AP93UT_MENU_H
