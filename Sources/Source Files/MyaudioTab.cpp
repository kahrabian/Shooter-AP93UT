//
// Created by kahrabian on 7/11/15.
//

#include "../Headers/MyaudioTab.h"

MyaudioTab::MyaudioTab(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    setStyleSheet(MyRes::wdg_stlsheet);
    audTab_lay = new QVBoxLayout(this);
    cnstrct_sndeffs();
    cnstrct_muse();
    audTab_lay->addLayout(muse);
    audTab_lay->addLayout(sndEffs);
    show();
}

MyaudioTab::~MyaudioTab() { }

void MyaudioTab::cnstrct_sndeffs()
{
    sndEffs = new QHBoxLayout(this);
    sndEffs_txt = new QLabel("Sound Effects:", this);
    sndEffs_txt->setStyleSheet(MyRes::lbl_stlsheet);
    sndEffs->addWidget(sndEffs_txt);
    sndEffs_sli = new QSlider(Qt::Orientation::Horizontal, this);
    sndEffs_sli->setRange(0, 100);
    sndEffs_sli->setValue(50);
    sndEffs_sli->setTickInterval(1);
    sndEffs_sli->setTickPosition(QSlider::TicksBelow);
    sndEffs->addWidget(sndEffs_sli);
    sndEffs_mute = new QCheckBox("Mute", this);
    sndEffs_mute->setStyleSheet(MyRes::chckbx_stlsheet);
    sndEffs->addWidget(sndEffs_mute);
}

void MyaudioTab::cnstrct_muse()
{
    muse = new QHBoxLayout(this);
    muse_txt = new QLabel("Musics:", this);
    muse_txt->setStyleSheet(MyRes::lbl_stlsheet);
    muse->addWidget(muse_txt);
    muse->addSpacing(sndEffs_txt->fontMetrics().width("Sound Effects:") - muse_txt->fontMetrics().width("Musics:"));
    muse_sli = new QSlider(Qt::Orientation::Horizontal, this);
    muse_sli->setRange(0, 100);
    muse_sli->setValue(50);
    muse_sli->setTickInterval(1);
    muse_sli->setTickPosition(QSlider::TicksBelow);
    muse->addWidget(muse_sli);
    muse_mute = new QCheckBox("Mute", this);
    muse_mute->setStyleSheet(MyRes::chckbx_stlsheet);
    muse->addWidget(muse_mute);
}

void MyaudioTab::paintEvent(QPaintEvent *my_event)
{
    QPainter *my_painter = new QPainter(this);
    QStyleOption *my_option = new QStyleOption();
    my_option->init(this);
    style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
    QWidget::paintEvent(my_event);
}
