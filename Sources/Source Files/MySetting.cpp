//
// Created by kahrabian on 7/7/15.
//

#include "../Headers/MySetting.h"

MySetting::MySetting(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    resize(1120, 630);
    setStyleSheet("MySetting " + MyRes::background_add);
    back = new QPushButton("Back", this);
    cnstrct_logo();
    cnstrct_tabs();
    cnstrct_stng();
}

MySetting::~MySetting() { }

void MySetting::cnstrct_tabs()
{
    tabs = new QTabWidget(this);
    cnstrct_mode_tab();
    cnstrct_thm_tab();
    cnstrct_aud_tab();
    cnstrct_ai_tab();
    tabs->setStyleSheet(MyRes::mainwdg_stlsheet);
    tabs->addTab(modeTab, "Game Mode");
    tabs->addTab(thmTab, "Theme");
    tabs->addTab(audTab, "Audio");
    tabs->addTab(aiTab, "Ai");
}

void MySetting::cnstrct_mode_tab()
{
    modeTab = new QWidget(tabs);
    modeTab->setStyleSheet(MyRes::wdg_stlsheet);
    modeTab_lay = new QHBoxLayout(modeTab);

    gMod_lay = new QVBoxLayout(modeTab);
    gMod_lay->setAlignment(Qt::AlignTop);
    gMod_txt = new QLabel("Game Mode:", modeTab);
    gMod_txt->setStyleSheet(MyRes::lbl_bstlsheet);
    gMod_lay->addWidget(gMod_txt);
    gMods = new QButtonGroup();
    gMod_sng = new QRadioButton("Single", modeTab);
    gMod_sng->setStyleSheet(MyRes::rdbtn_stlsheet);
    gMod_sng->setChecked(true);
    gMods->addButton(gMod_sng, 1);
    gMod_lay->addWidget(gMod_sng);
    gMod_co = new QRadioButton("Co-Op", modeTab);
    gMod_co->setStyleSheet(MyRes::rdbtn_stlsheet);
    gMods->addButton(gMod_co, 2);
    gMod_lay->addWidget(gMod_co);
    gMod_vs = new QRadioButton("vs Ai", modeTab);
    gMod_vs->setStyleSheet(MyRes::rdbtn_stlsheet);
    gMods->addButton(gMod_vs, 3);
    gMod_lay->addWidget(gMod_vs);

    gDiff_lay = new QVBoxLayout(modeTab);
    gDiff_lay->setAlignment(Qt::AlignTop);
    gDiff_txt = new QLabel("Game Difficulty:", modeTab);
    gDiff_txt->setStyleSheet(MyRes::lbl_bstlsheet);
    gDiff_lay->addWidget(gDiff_txt);
    gDiffs = new QButtonGroup();
    gDiff_eas = new QRadioButton("Easy", modeTab);
    gDiff_eas->setStyleSheet(MyRes::rdbtn_stlsheet);
    gDiff_eas->setChecked(true);
    gDiffs->addButton(gDiff_eas, 1);
    gDiff_lay->addWidget(gDiff_eas);
    gDiff_nor = new QRadioButton("Normal", modeTab);
    gDiff_nor->setStyleSheet(MyRes::rdbtn_stlsheet);
    gDiffs->addButton(gDiff_nor, 2);
    gDiff_lay->addWidget(gDiff_nor);
    gDiff_har = new QRadioButton("Hard", modeTab);
    gDiff_har->setStyleSheet(MyRes::rdbtn_stlsheet);
    gDiffs->addButton(gDiff_har, 3);
    gDiff_lay->addWidget(gDiff_har);
    gDiff_ext = new QRadioButton("Extreme", modeTab);
    gDiff_ext->setStyleSheet(MyRes::rdbtn_stlsheet);
    gDiffs->addButton(gDiff_ext, 4);
    gDiff_lay->addWidget(gDiff_ext);

    modeTab_lay->addLayout(gMod_lay);
    modeTab_lay->addLayout(gDiff_lay);
}

void MySetting::cnstrct_thm_tab()
{
    thmTab = new QWidget(tabs);
    thmTab->setStyleSheet(MyRes::wdg_stlsheet);
    thmTab_lay = new QHBoxLayout(thmTab);

    aln_spc_lay = new QVBoxLayout(thmTab);
//    aln_spc_lay->setAlignment(Qt::AlignTop);
//     Spaceship selector
    spc_pic = new QLabel(thmTab);
    aln_spc_lay->addWidget(spc_pic);
    spcbtn_lay = new QHBoxLayout(thmTab);
    spc_prebtn = new QToolButton(thmTab);
    spc_prebtn->setArrowType(Qt::LeftArrow);
    spcbtn_lay->addWidget(spc_prebtn);
    spc_txt = new QLabel("User Space Ship", thmTab);
    spc_txt->setStyleSheet(MyRes::lbl_stlsheet);
    spc_txt->setAlignment(Qt::AlignCenter);
    spcbtn_lay->addWidget(spc_txt);
    spc_nexbtn = new QToolButton(thmTab);
    spc_nexbtn->setArrowType(Qt::RightArrow);
    spcbtn_lay->addWidget(spc_nexbtn);
    aln_spc_lay->addLayout(spcbtn_lay);

    aln_pic = new QLabel(thmTab);
    aln_spc_lay->addWidget(aln_pic);
    alnbtn_lay = new QHBoxLayout(thmTab);
    aln_prebtn = new QToolButton(thmTab);
    aln_prebtn->setArrowType(Qt::LeftArrow);
    alnbtn_lay->addWidget(aln_prebtn);
    aln_txt = new QLabel("Alien", thmTab);
    aln_txt->setStyleSheet(MyRes::lbl_stlsheet);
    aln_txt->setAlignment(Qt::AlignCenter);
    alnbtn_lay->addWidget(aln_txt);
    aln_nexbtn = new QToolButton(thmTab);
    aln_nexbtn->setArrowType(Qt::RightArrow);
    alnbtn_lay->addWidget(aln_nexbtn);
    aln_spc_lay->addLayout(alnbtn_lay);

    env_lay = new QVBoxLayout(thmTab);
//    env_lay->setAlignment(Qt::AlignTop);
    env_pic = new QLabel(thmTab);
    env_lay->addWidget(env_pic);
    envbtn_lay = new QHBoxLayout(thmTab);
    env_prebtn = new QToolButton(thmTab);
    env_prebtn->setArrowType(Qt::LeftArrow);
    envbtn_lay->addWidget(env_prebtn);
    env_txt = new QLabel("Environment", thmTab);
    env_txt->setAlignment(Qt::AlignCenter);
    env_txt->setStyleSheet(MyRes::lbl_stlsheet);
    envbtn_lay->addWidget(env_txt);
    env_nexbtn = new QToolButton(thmTab);
    env_nexbtn->setArrowType(Qt::RightArrow);
    envbtn_lay->addWidget(env_nexbtn);
    env_lay->addLayout(envbtn_lay);

    thmTab_lay->addLayout(aln_spc_lay);
    thmTab_lay->addLayout(env_lay);
}

void MySetting::cnstrct_aud_tab()
{
    audTab = new QWidget(tabs);
    audTab->setStyleSheet(MyRes::wdg_stlsheet);
    audTab_lay = new QVBoxLayout(audTab);

    sndEffs = new QHBoxLayout(audTab);
    sndEffs_txt = new QLabel("Sound Effects:", audTab);
    sndEffs_txt->setStyleSheet(MyRes::lbl_stlsheet);
    sndEffs->addWidget(sndEffs_txt);
    sndEffs_sli = new QSlider(Qt::Orientation::Horizontal ,audTab);
    sndEffs_sli->setRange(0, 100);
    sndEffs_sli->setValue(50);
    sndEffs_sli->setTickInterval(1);
    sndEffs_sli->setTickPosition(QSlider::TicksBelow);
    sndEffs->addWidget(sndEffs_sli);
    sndEffs_mute = new QCheckBox("Mute", audTab);
    sndEffs_mute->setStyleSheet(MyRes::chckbx_stlsheet);
    sndEffs->addWidget(sndEffs_mute);
    muse = new QHBoxLayout(audTab);
    muse_txt = new QLabel("Musics:", audTab);
    muse_txt->setStyleSheet(MyRes::lbl_stlsheet);
    muse->addWidget(muse_txt);
    muse->addSpacing(sndEffs_txt->fontMetrics().width("Sound Effects:") - muse_txt->fontMetrics().width("Musics:"));
    muse_sli = new QSlider(Qt::Orientation::Horizontal ,audTab);
    muse_sli->setRange(0, 100);
    muse_sli->setValue(50);
    muse_sli->setTickInterval(1);
    muse_sli->setTickPosition(QSlider::TicksBelow);
    muse->addWidget(muse_sli);
    muse_mute = new QCheckBox("Mute", audTab);
    muse_mute->setStyleSheet(MyRes::chckbx_stlsheet);
    muse->addWidget(muse_mute);

    audTab_lay->addLayout(muse);
    audTab_lay->addLayout(sndEffs);
}

void MySetting::cnstrct_ai_tab()
{
    aiTab = new QWidget(tabs);
    aiTab->setStyleSheet(MyRes::wdg_stlsheet);
    aiTab_lay = new QHBoxLayout(aiTab);

    aiDiff_lay = new QVBoxLayout(aiTab);
    aiDiff_lay->setAlignment(Qt::AlignTop);
    aiDiff_txt = new QLabel("Ai Difficulty:", aiTab);
    aiDiff_txt->setStyleSheet(MyRes::lbl_bstlsheet);
    aiDiff_lay->addWidget(aiDiff_txt);
    aiDiffs = new QButtonGroup();
    aiDiff_eas = new QRadioButton("Easy", aiTab);
    aiDiff_eas->setStyleSheet(MyRes::rdbtn_stlsheet);
    aiDiff_eas->setChecked(true);
    aiDiffs->addButton(aiDiff_eas, 1);
    aiDiff_lay->addWidget(aiDiff_eas);
    aiDiff_nor = new QRadioButton("Normal", aiTab);
    aiDiff_nor->setStyleSheet(MyRes::rdbtn_stlsheet);
    aiDiffs->addButton(aiDiff_nor, 2);
    aiDiff_lay->addWidget(aiDiff_nor);
    aiDiff_har = new QRadioButton("Hard", aiTab);
    aiDiff_har->setStyleSheet(MyRes::rdbtn_stlsheet);
    aiDiffs->addButton(aiDiff_har, 3);
    aiDiff_lay->addWidget(aiDiff_har);
    aiDiff_ext = new QRadioButton("Extreme", aiTab);
    aiDiff_ext->setStyleSheet(MyRes::rdbtn_stlsheet);
    aiDiffs->addButton(aiDiff_ext, 4);
    aiDiff_lay->addWidget(aiDiff_ext);

    aiShip_lay = new QVBoxLayout(aiTab);
//    aiShip_lay->setAlignment(Qt::AlignTop);
//     Use label to show the Ai ship pictures
    aiShip_pic = new QLabel(aiTab);
    aiShip_lay->addWidget(aiShip_pic);
    aiShipbtn_lay = new QHBoxLayout(aiTab);
    aiShip_prebtn = new QToolButton(aiTab);
    aiShip_prebtn->setArrowType(Qt::LeftArrow);
    aiShipbtn_lay->addWidget(aiShip_prebtn);
    aiShip_txt = new QLabel("Ai Space Ship", aiTab);
    aiShip_txt->setStyleSheet(MyRes::lbl_stlsheet);
    aiShip_txt->setAlignment(Qt::AlignCenter);
    aiShipbtn_lay->addWidget(aiShip_txt);
    aiShip_nexbtn = new QToolButton(aiTab);
    aiShip_nexbtn->setArrowType(Qt::RightArrow);
    aiShipbtn_lay->addWidget(aiShip_nexbtn);
    aiShip_lay->addLayout(aiShipbtn_lay);

    aiTab_lay->addLayout(aiDiff_lay);
    aiTab_lay->addLayout(aiShip_lay);
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
    QPixmap *my_pix = new QPixmap(MyRes::logo_add);
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