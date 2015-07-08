//
// Created by kahrabian on 7/7/15.
//

#ifndef SHOOTER_AP93UT_MYSETTING_H
#define SHOOTER_AP93UT_MYSETTING_H


#include <QtGui/qpainter.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qtabwidget.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qstyleoption.h>
#include <QtWidgets/qcheckbox.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qbuttongroup.h>


class MySetting : public QWidget
{
    Q_OBJECT
    friend class MyMainWindow;
public:
    MySetting(QWidget * = 0, Qt::WindowFlags = 0);
    ~MySetting();

private:
    QVBoxLayout *setting;
    QTabWidget *tabs;
    QPushButton *back;
    QLabel *logo;

    QWidget *mode_tab;
    QHBoxLayout *mode_tab_lay;
    QVBoxLayout *gmod_lay;
    QLabel *gmod_txt;
    QButtonGroup *gmods;
    QRadioButton *gmod_sng;
    QRadioButton *gmod_co;
    QRadioButton *gmod_vs;

    QVBoxLayout *gdiff_lay;
    QLabel *gdiff_txt;
    QButtonGroup *gdiffs;
    QRadioButton *gdiff_eas;
    QRadioButton *gdiff_nor;
    QRadioButton *gdiff_har;
    QRadioButton *gdiff_ext;

    QWidget *audio_tab;
    QVBoxLayout *audio_tab_lay;
    QHBoxLayout *snd_effs;
    QLabel *snd_effs_txt;
    QSlider *snd_effs_sli;
    QCheckBox *snd_effs_mute;
    QHBoxLayout *muse;
    QLabel *muse_txt;
    QSlider *muse_sli;
    QCheckBox *muse_mute;
//    QWidget *theme_tab;

    void cnstrct_logo();
    void cnstrct_stng();
    void cnstrct_tabs();
    void cnstrct_audio_tab();
    void cnstrct_mode_tab();
//    void construct_theme_tab();
    void paintEvent(QPaintEvent *);
};


#endif //SHOOTER_AP93UT_MYSETTING_H
