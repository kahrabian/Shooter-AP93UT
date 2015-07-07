//
// Created by kahrabian on 7/7/15.
//

#ifndef SHOOTER_AP93UT_MYSETTING_H
#define SHOOTER_AP93UT_MYSETTING_H


#include <QtWidgets/qwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qtabwidget.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qstyleoption.h>
#include <QtGui/qpainter.h>
#include <QtWidgets/qcheckbox.h>


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

    QWidget *audio_tab;
    QVBoxLayout *audio_tab_layout;
    QHBoxLayout *sound_effects;
    QLabel *sound_effects_text;
    QLabel *sound_effects_mute;
    QSlider *sound_effects_slider;
    QCheckBox *sound_effects_mute_checkbox;

    QHBoxLayout *musics;
    QLabel *musics_text;
    QLabel *musics_mute;
    QSlider *musics_slider;
    QCheckBox *musics_mute_checkbox;

//    QWidget *theme_tab;
//    QWidget *mode_tab;

    void construct_logo();
    void construct_setting();
    void construct_tabs();
    void construct_audio_tab();
//    void construct_mode_tab();
//    void construct_theme_tab();
    void paintEvent(QPaintEvent *);
};


#endif //SHOOTER_AP93UT_MYSETTING_H
