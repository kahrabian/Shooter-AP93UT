//
// Created by kahrabian on 7/7/15.
//

#include "MySetting.h"

MySetting::MySetting(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    resize(1120, 630);
    setStyleSheet("image: url(/home/kahrabian/ClionProjects/Shooter-AP93UT/Contents/background_menu.jpg);");
    back = new QPushButton("Back", this);
    construct_logo();
    construct_tabs();
    construct_setting();
}

MySetting::~MySetting()
{
}

void MySetting::construct_tabs()
{
    tabs = new QTabWidget(this);
    construct_audio_tab();
    tabs->addTab(audio_tab, "Audio:");
}

void MySetting::construct_audio_tab()
{
    audio_tab = new QWidget(tabs);
    sound_effects = new QHBoxLayout(audio_tab);
    sound_effects_text = new QLabel("Sound Effects:", audio_tab);
    sound_effects->addWidget(sound_effects_text);
    sound_effects_slider = new QSlider(Qt::Orientation::Horizontal ,audio_tab);
    sound_effects_slider->setRange(0, 100);
    sound_effects_slider->setValue(50);
    sound_effects_slider->setTickInterval(1);
    sound_effects_slider->setTickPosition(QSlider::TicksBelow);
    sound_effects->addWidget(sound_effects_slider);
    sound_effects_mute = new QLabel("Mute:", audio_tab);
    sound_effects->addWidget(sound_effects_mute);
    sound_effects_mute_checkbox = new QCheckBox(audio_tab);
    sound_effects->addWidget(sound_effects_mute_checkbox);
    musics = new QHBoxLayout(audio_tab);
    musics_text = new QLabel("Sound Effects:", audio_tab);
    musics->addWidget(musics_text);
    musics_slider = new QSlider(Qt::Orientation::Horizontal ,audio_tab);
    musics_slider->setRange(0, 100);
    musics_slider->setValue(50);
    musics_slider->setTickInterval(1);
    musics_slider->setTickPosition(QSlider::TicksBelow);
    musics->addWidget(musics_slider);
    musics_mute = new QLabel("Mute:", audio_tab);
    musics->addWidget(musics_mute);
    musics_mute_checkbox = new QCheckBox(audio_tab);
    musics->addWidget(musics_mute_checkbox);
    audio_tab_layout = new QVBoxLayout(audio_tab);
    audio_tab_layout->addLayout(musics);
    audio_tab_layout->addLayout(sound_effects);
}


void MySetting::construct_setting()
{
    setting = new QVBoxLayout(this);
    setting->addWidget(logo);
    setting->addWidget(tabs);
    setting->addWidget(back);
}

void MySetting::construct_logo()
{
    logo = new QLabel(this);
    QPixmap *my_pix = new QPixmap("/home/kahrabian/ClionProjects/Shooter-AP93UT/Contents/logo.png");
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