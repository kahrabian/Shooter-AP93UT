//
// Created by kahrabian on 7/11/15.
//

#ifndef SHOOTER_AP93UT_MYAITAB_H
#define SHOOTER_AP93UT_MYAITAB_H

#include <QPainter>
#include <QStyleOption>
#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <QRadioButton>
#include <QButtonGroup>
#include "Resources.h"

class MyaiTab : public QWidget
{
    Q_OBJECT
    friend class MySetting;
public:
    MyaiTab(QWidget * = 0, Qt::WindowFlags = 0);
    ~MyaiTab();

private:
    QHBoxLayout *aiTab_lay;
    QVBoxLayout *aiDiff_lay;
    QLabel *aiDiff_txt;
    QButtonGroup *aiDiffs;
    QRadioButton *aiDiff_eas;
    QRadioButton *aiDiff_nor;
    QRadioButton *aiDiff_har;
    QRadioButton *aiDiff_ext;
    QVBoxLayout *aiShip_lay;
    QLabel *aiShip_pic;
    QHBoxLayout *aiShipbtn_lay;
    QLabel *aiShip_txt;
    QToolButton *aiShip_nexbtn;
    QToolButton *aiShip_prebtn;

    void cnstrct_diff();
    void cnstrct_shp();
    void paintEvent(QPaintEvent *);
};

#endif //SHOOTER_AP93UT_MYAITAB_H
