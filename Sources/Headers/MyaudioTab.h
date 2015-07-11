//
// Created by kahrabian on 7/11/15.
//

#ifndef SHOOTER_AP93UT_MYAUDIOTAB_H
#define SHOOTER_AP93UT_MYAUDIOTAB_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QCheckBox>
#include <QStyleOption>
#include <QPainter>
#include "Resources.h"

class MyaudioTab : public QWidget
{
    Q_OBJECT
    friend class MySetting;
public:
    MyaudioTab(QWidget * = 0, Qt::WindowFlags = 0);
    ~MyaudioTab();

private:
    QVBoxLayout *audTab_lay;
    QHBoxLayout *sndEffs;
    QLabel *sndEffs_txt;
    QSlider *sndEffs_sli;
    QCheckBox *sndEffs_mute;
    QHBoxLayout *muse;
    QLabel *muse_txt;
    QSlider *muse_sli;
    QCheckBox *muse_mute;

    void cnstrct_sndeffs();
    void cnstrct_muse();
    void paintEvent(QPaintEvent *);
};

#endif //SHOOTER_AP93UT_MYAUDIOTAB_H
