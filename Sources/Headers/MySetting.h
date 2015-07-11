//
// Created by kahrabian on 7/7/15.
//

#ifndef SHOOTER_AP93UT_MYSETTING_H
#define SHOOTER_AP93UT_MYSETTING_H


#include <QPainter>
#include <QWidget>
#include <QBoxLayout>
#include <QTabWidget>
#include <QPushButton>
#include <QLabel>
#include <QStyleOption>
#include <QCheckBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QToolButton>
#include <QTextStream>
#include "Resources.h"
#include "MythmTab.h"
#include "MyaudioTab.h"
#include "MymodeTab.h"
#include "MyaiTab.h"


class MySetting : public QWidget
{
    Q_OBJECT
    friend class MyMainWindow;
public:
    MySetting(QWidget * = 0, Qt::WindowFlags = 0);
    ~MySetting();

public slots:
    void update_stng();
    void pre_env();
    void nxt_env();
    void pre_shp();
    void nxt_shp();
    void pre_aishp();
    void nxt_aishp();

signals:
    void settingChanged();


private:
    QVBoxLayout *setting;
    QTabWidget *tabs;
    QPushButton *back;
    QLabel *logo;

    MymodeTab *modeTab;
    MythmTab *thmTab;
    MyaudioTab *audTab;
    MyaiTab *aiTab;

    void set_cnctns();
    void cnstrct_stng();
    void cnstrct_logo();
    void cnstrct_tabs();
    void paintEvent(QPaintEvent *);
};


#endif //SHOOTER_AP93UT_MYSETTING_H
