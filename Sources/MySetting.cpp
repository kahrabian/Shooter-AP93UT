//
// Created by kahrabian on 7/7/15.
//

#include "MySetting.h"

MySetting::MySetting(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    resize(1120, 630);
    setStyleSheet("MySetting {background-image: url(/home/kahrabian/ClionProjects/Shooter-AP93UT/Resources/background.jpg);}");    back = new QPushButton("Back", this);
    cnstrct_logo();
    cnstrct_tabs();
    cnstrct_stng();
}

MySetting::~MySetting()
{
}

void MySetting::cnstrct_tabs()
{
    tabs = new QTabWidget(this);
    cnstrct_audio_tab();
    cnstrct_mode_tab();
    tabs->setStyleSheet("QTabWidget {background-color: rgba(0, 0, 0, 60%);}");
    tabs->addTab(mode_tab, "Game Mode");
    tabs->addTab(audio_tab, "Audio");
}

void MySetting::cnstrct_audio_tab()
{
    audio_tab = new QWidget(tabs);
    audio_tab->setStyleSheet("QWidget {background-color: transparent;}");
    audio_tab_lay = new QVBoxLayout(audio_tab);

    snd_effs = new QHBoxLayout(audio_tab);
    snd_effs_txt = new QLabel("Sound Effects:", audio_tab);
    snd_effs_txt->setStyleSheet("QLabel {font-size: 12pt;}");
    snd_effs->addWidget(snd_effs_txt);
    snd_effs_sli = new QSlider(Qt::Orientation::Horizontal ,audio_tab);
    snd_effs_sli->setRange(0, 100);
    snd_effs_sli->setValue(50);
    snd_effs_sli->setTickInterval(1);
    snd_effs_sli->setTickPosition(QSlider::TicksBelow);
    snd_effs->addWidget(snd_effs_sli);
    snd_effs_mute = new QCheckBox("Mute", audio_tab);
    snd_effs_mute->setStyleSheet("QCheckBox {font-size: 12pt;}");
    snd_effs->addWidget(snd_effs_mute);
    muse = new QHBoxLayout(audio_tab);
    muse_txt = new QLabel("Musics:", audio_tab);
    muse_txt->setStyleSheet("QLabel {font-size: 12pt;}");
    muse->addWidget(muse_txt);
    muse->addSpacing(snd_effs_txt->fontMetrics().width("Sound Effects:") - muse_txt->fontMetrics().width("Musics:"));
    muse_sli = new QSlider(Qt::Orientation::Horizontal ,audio_tab);
    muse_sli->setRange(0, 100);
    muse_sli->setValue(50);
    muse_sli->setTickInterval(1);
    muse_sli->setTickPosition(QSlider::TicksBelow);
    muse->addWidget(muse_sli);
    muse_mute = new QCheckBox("Mute", audio_tab);
    muse_mute->setStyleSheet("QCheckBox {font-size: 12pt;}");
    muse->addWidget(muse_mute);

    audio_tab_lay->addLayout(muse);
    audio_tab_lay->addLayout(snd_effs);
}

void MySetting::cnstrct_mode_tab()
{
    mode_tab = new QWidget(tabs);
    mode_tab->setStyleSheet("QWidget {background-color: transparent;}");
    mode_tab_lay = new QHBoxLayout(mode_tab);

    gmod_lay = new QVBoxLayout(mode_tab);
    gmod_lay->setAlignment(Qt::AlignTop);
    gmod_txt = new QLabel("Game Mode:", mode_tab);
    gmod_txt->setStyleSheet("QLabel {font-size: 25pt; font-weight: bold;}");
    gmod_lay->addWidget(gmod_txt);
    gmods = new QButtonGroup();
    gmod_sng = new QRadioButton("Single", mode_tab);
    gmod_sng->setStyleSheet("QRadioButton {font-size: 12pt;}");
    gmods->addButton(gmod_sng, 1);
    gmod_lay->addWidget(gmod_sng);
    gmod_co = new QRadioButton("Co-Op", mode_tab);
    gmod_co->setStyleSheet("QRadioButton {font-size: 12pt;}");
    gmods->addButton(gmod_co, 2);
    gmod_lay->addWidget(gmod_co);
    gmod_vs = new QRadioButton("vs CPU", mode_tab);
    gmod_vs->setStyleSheet("QRadioButton {font-size: 12pt;}");
    gmods->addButton(gmod_vs, 3);
    gmod_lay->addWidget(gmod_vs);

    gdiff_lay = new QVBoxLayout(mode_tab);
    gdiff_lay->setAlignment(Qt::AlignTop);
    gdiff_txt = new QLabel("Game Difficulty:", mode_tab);
    gdiff_txt->setStyleSheet("QLabel {font-size: 25pt; font-weight: bold;}");
    gdiff_lay->addWidget(gdiff_txt);
    gdiffs = new QButtonGroup();
    gdiff_eas = new QRadioButton("Easy", mode_tab);
    gdiff_eas->setStyleSheet("QRadioButton {font-size: 12pt;}");
    gdiffs->addButton(gdiff_eas, 1);
    gdiff_lay->addWidget(gdiff_eas);
    gdiff_nor = new QRadioButton("Normal", mode_tab);
    gdiff_nor->setStyleSheet("QRadioButton {font-size: 12pt;}");
    gdiffs->addButton(gdiff_nor, 2);
    gdiff_lay->addWidget(gdiff_nor);
    gdiff_har = new QRadioButton("Hard", mode_tab);
    gdiff_har->setStyleSheet("QRadioButton {font-size: 12pt;}");
    gdiffs->addButton(gdiff_har, 3);
    gdiff_lay->addWidget(gdiff_har);
    gdiff_ext = new QRadioButton("Extreme", mode_tab);
    gdiff_ext->setStyleSheet("QRadioButton {font-size: 12pt;}");
    gdiffs->addButton(gdiff_ext, 4);
    gdiff_lay->addWidget(gdiff_ext);

    mode_tab_lay->addLayout(gmod_lay);
    mode_tab_lay->addLayout(gdiff_lay);
}

void MySetting::cnstrct_stng()
{
    setting = new QVBoxLayout(this);
    setting->addWidget(logo);
    setting->addWidget(tabs);
    setting->addWidget(back);
}

void MySetting::cnstrct_logo()
{
    logo = new QLabel(this);
    QPixmap *my_pix = new QPixmap("/home/kahrabian/ClionProjects/Shooter-AP93UT/Resources/logo.png");
    logo->setPixmap(*my_pix);
    logo->setAlignment(Qt::AlignHCenter);
    logo->setAttribute(Qt::WA_TranslucentBackground);
    delete my_pix;
}

void MySetting::paintEvent(QPaintEvent *my_event)
{
    QPainter *my_painter = new QPainter(this);
    QStyleOption *my_option = new QStyleOption();
    my_option->init(this);
    style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
    QWidget::paintEvent(my_event);
}