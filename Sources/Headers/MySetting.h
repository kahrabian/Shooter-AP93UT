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
#include <QtWidgets/qtoolbutton.h>


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

    QWidget *modeTab;
    QHBoxLayout *modeTab_lay;
    QVBoxLayout *gMod_lay;
    QLabel *gMod_txt;
    QButtonGroup *gMods;
    QRadioButton *gMod_sng;
    QRadioButton *gMod_co;
    QRadioButton *gMod_vs;
    QVBoxLayout *gDiff_lay;
    QLabel *gDiff_txt;
    QButtonGroup *gDiffs;
    QRadioButton *gDiff_eas;
    QRadioButton *gDiff_nor;
    QRadioButton *gDiff_har;
    QRadioButton *gDiff_ext;

    QWidget *thmTab;
    QHBoxLayout *thmTab_lay;
    QVBoxLayout *aln_spc_lay;
    QLabel *spc_pic;
    QHBoxLayout *spcbtn_lay;
    QLabel *spc_txt;
    QToolButton *spc_prebtn;
    QToolButton *spc_nexbtn;
    QLabel *aln_pic;
    QHBoxLayout *alnbtn_lay;
    QLabel *aln_txt;
    QToolButton *aln_prebtn;
    QToolButton *aln_nexbtn;
    QVBoxLayout *env_lay;
    QLabel *env_pic;
    QHBoxLayout *envbtn_lay;
    QLabel *env_txt;
    QToolButton *env_prebtn;
    QToolButton *env_nexbtn;

    QWidget *audTab;
    QVBoxLayout *audTab_lay;
    QHBoxLayout *sndEffs;
    QLabel *sndEffs_txt;
    QSlider *sndEffs_sli;
    QCheckBox *sndEffs_mute;
    QHBoxLayout *muse;
    QLabel *muse_txt;
    QSlider *muse_sli;
    QCheckBox *muse_mute;

    QWidget *aiTab;
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

    void cnstrct_logo();
    void cnstrct_stng();
    void cnstrct_tabs();
    void cnstrct_aud_tab();
    void cnstrct_mode_tab();
    void cnstrct_ai_tab();
    void cnstrct_thm_tab();
    void paintEvent(QPaintEvent *);
};


#endif //SHOOTER_AP93UT_MYSETTING_H
