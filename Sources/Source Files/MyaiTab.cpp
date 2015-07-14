//
// Created by kahrabian on 7/11/15.
//

#include "../Headers/MyaiTab.h"

MyaiTab::MyaiTab(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    setStyleSheet(MyRes::wdg_stlsheet);
    aiTab_lay = new QHBoxLayout(this);
    cnstrct_diff();
    cnstrct_shp();
    aiTab_lay->addLayout(aiDiff_lay);
    aiTab_lay->addLayout(aiShip_lay);
    hide();
}

MyaiTab::~MyaiTab() { }

void MyaiTab::cnstrct_diff()
{
    aiDiff_lay = new QVBoxLayout();
    aiDiff_lay->setAlignment(Qt::AlignTop);
    aiDiff_txt = new QLabel("Ai Difficulty:", this);
    aiDiff_txt->setStyleSheet(MyRes::lbl_bstlsheet);
    aiDiff_lay->addWidget(aiDiff_txt);
    aiDiffs = new QButtonGroup();
    aiDiff_eas = new QRadioButton("Easy", this);
    aiDiff_eas->setStyleSheet(MyRes::rdbtn_stlsheet);
    aiDiff_eas->setChecked(true);
    aiDiffs->addButton(aiDiff_eas, 1);
    aiDiff_lay->addWidget(aiDiff_eas);
    aiDiff_nor = new QRadioButton("Normal", this);
    aiDiff_nor->setStyleSheet(MyRes::rdbtn_stlsheet);
    aiDiffs->addButton(aiDiff_nor, 2);
    aiDiff_lay->addWidget(aiDiff_nor);
    aiDiff_har = new QRadioButton("Hard", this);
    aiDiff_har->setStyleSheet(MyRes::rdbtn_stlsheet);
    aiDiffs->addButton(aiDiff_har, 3);
    aiDiff_lay->addWidget(aiDiff_har);
    aiDiff_ext = new QRadioButton("Extreme", this);
    aiDiff_ext->setStyleSheet(MyRes::rdbtn_stlsheet);
    aiDiffs->addButton(aiDiff_ext, 4);
    aiDiff_lay->addWidget(aiDiff_ext);
}

void MyaiTab::cnstrct_shp()
{
    aiShip_lay = new QVBoxLayout();
    aiShip_pic = new QLabel(this);
    aiShip_pic->setFixedSize(MyRes::img_init_size);
    aiShip_pic->setPixmap(QPixmap(MyRes::shp_adds[SettingData::aiShp]).scaled(aiShip_pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    aiShip_pic->setAlignment(Qt::AlignCenter);
    aiShip_pic->setAttribute(Qt::WA_TranslucentBackground);
    aiShip_lay->addWidget(aiShip_pic);
    aiShipbtn_lay = new QHBoxLayout();
    aiShip_prebtn = new QToolButton(this);
    aiShip_prebtn->setArrowType(Qt::LeftArrow);
    aiShipbtn_lay->addWidget(aiShip_prebtn);
    aiShip_txt = new QLabel("Ai Space Ship", this);
    aiShip_txt->setStyleSheet(MyRes::lbl_stlsheet);
    aiShip_txt->setAlignment(Qt::AlignCenter);
    aiShipbtn_lay->addWidget(aiShip_txt);
    aiShip_nexbtn = new QToolButton(this);
    aiShip_nexbtn->setArrowType(Qt::RightArrow);
    aiShipbtn_lay->addWidget(aiShip_nexbtn);
    aiShip_lay->addLayout(aiShipbtn_lay);
}

void MyaiTab::paintEvent(QPaintEvent *my_event)
{
    QPainter *my_painter = new QPainter(this);
    QStyleOption *my_option = new QStyleOption();
    my_option->init(this);
    style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
    QWidget::paintEvent(my_event);
}
