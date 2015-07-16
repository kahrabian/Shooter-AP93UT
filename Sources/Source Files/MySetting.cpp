//
// Created by kahrabian on 7/7/15.
//

#include "../Headers/MySetting.h"

MySetting::MySetting(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    resize(MyRes::app_size);
    setStyleSheet("MySetting " + MyRes::background_add);
    back = new QPushButton("Back", this);
    cnstrct_logo();
    cnstrct_tabs();
    cnstrct_stng();
    set_cnctns();
}

MySetting::~MySetting() { }

void MySetting::cnstrct_tabs()
{
    tabs = new QTabWidget(this);
    modeTab = new MymodeTab(tabs);
    thmTab = new MythmTab(tabs);
    aiTab = new MyaiTab(tabs);
    audTab = new MyaudioTab(tabs);
    tabs->setStyleSheet(MyRes::mainwdg_stlsheet);
    tabs->addTab(modeTab, "Game");
    tabs->addTab(thmTab, "Theme");
    tabs->addTab(audTab, "Audio");
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
    logo->setPixmap(QPixmap(MyRes::logo_add));
    logo->setAlignment(Qt::AlignHCenter);
    logo->setAttribute(Qt::WA_TranslucentBackground);
}

void MySetting::set_cnctns()
{
    QObject::connect(modeTab->gMods, SIGNAL(buttonToggled(int, bool)), this, SLOT(update_stng()));
    QObject::connect(modeTab->gDiffs, SIGNAL(buttonToggled(int, bool)), this, SLOT(update_stng()));

    QObject::connect(thmTab->spc_prebtn , SIGNAL(clicked()), this, SLOT(pre_shp()));
    QObject::connect(thmTab->spc_nexbtn , SIGNAL(clicked()), this, SLOT(nxt_shp()));
    QObject::connect(thmTab->env_prebtn , SIGNAL(clicked()), this, SLOT(pre_env()));
    QObject::connect(thmTab->env_nexbtn , SIGNAL(clicked()), this, SLOT(nxt_env()));

    QObject::connect(audTab->sndEffs_sli , SIGNAL(valueChanged(int)), this, SLOT(update_stng()));
    QObject::connect(audTab->sndEffs_mute , SIGNAL(stateChanged(int)), this, SLOT(update_stng()));
    QObject::connect(audTab->muse_sli , SIGNAL(valueChanged(int)), this, SLOT(update_stng()));
    QObject::connect(audTab->muse_mute , SIGNAL(stateChanged(int)), this, SLOT(update_stng()));

    QObject::connect(aiTab->aiDiffs , SIGNAL(buttonToggled(int, bool)), this, SLOT(update_stng()));
    QObject::connect(aiTab->aiShip_prebtn , SIGNAL(clicked()), this, SLOT(pre_aishp()));
    QObject::connect(aiTab->aiShip_nexbtn , SIGNAL(clicked()), this, SLOT(nxt_aishp()));
}

void MySetting::update_stng()
{
    if(modeTab->gMods->checkedId() == 3 && SettingData::gMode != 3)
    {
        aiTab->show();
        tabs->addTab(aiTab, "Ai");
    }
    else if(modeTab->gMods->checkedId() != 3 && SettingData::gMode == 3)
    {
        aiTab->hide();
        tabs->removeTab(3);
    }
    SettingData::gMode = modeTab->gMods->checkedId();
    SettingData::gDiff = modeTab->gDiffs->checkedId();
    SettingData::mVol = audTab->muse_sli->value();
    SettingData::mMut = audTab->muse_mute->isChecked();
    SettingData::sfVol = audTab->sndEffs_sli->value();
    SettingData::sfMut = audTab->sndEffs_mute->isChecked();
    SettingData::aiDiff = aiTab->aiDiffs->checkedId();
	thmTab->spc_pic->setPixmap(QPixmap(MyRes::shp_adds[SettingData::uShp]).scaled(thmTab->spc_pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	thmTab->env_pic->setPixmap(QPixmap(MyRes::env_adds[SettingData::env]).scaled(thmTab->env_pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	aiTab->aiShip_pic->setPixmap(QPixmap(MyRes::shp_adds[SettingData::aiShp]).scaled(aiTab->aiShip_pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    emit settingChanged();
}

void MySetting::paintEvent(QPaintEvent *my_event)
{
    QPainter *my_painter = new QPainter(this);
    QStyleOption *my_option = new QStyleOption();
    my_option->init(this);
    style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
    QWidget::paintEvent(my_event);
}

void MySetting::pre_env()
{
    SettingData::env = (SettingData::env + MyRes::env_cnt - 1) % MyRes::env_cnt;
    update_stng();
}

void MySetting::nxt_env()
{
    SettingData::env = (SettingData::env + MyRes::env_cnt + 1) % MyRes::env_cnt;
    update_stng();
}

void MySetting::pre_shp()
{
    SettingData::uShp = (SettingData::uShp + MyRes::shp_cnt - 1) % MyRes::shp_cnt;
    update_stng();
}

void MySetting::nxt_shp()
{
    SettingData::uShp = (SettingData::uShp + MyRes::shp_cnt + 1) % MyRes::shp_cnt;
    update_stng();
}

void MySetting::pre_aishp()
{
    SettingData::aiShp = (SettingData::aiShp + MyRes::shp_cnt - 1) % MyRes::shp_cnt;
    update_stng();
}

void MySetting::nxt_aishp()
{
    SettingData::aiShp = (SettingData::aiShp + MyRes::shp_cnt + 1) % MyRes::shp_cnt;
    update_stng();
}