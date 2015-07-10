//
// Created by kahrabian on 7/4/15.
//

#include "../Headers/MyMainWindow.h"

MyMainWindow::MyMainWindow(QWidget * parent, Qt::WindowFlags flag) :
        QMainWindow(parent, flag)
{
    set_media();
    cnstrct_stack();
    set_prpts();
    set_cnctns();
}

MyMainWindow::~MyMainWindow() { }

void MyMainWindow::exit_bttn_clicked()
{
    close();
}

void MyMainWindow::back_bttn_clicked()
{
    widget_stack->setCurrentWidget(menu);
}

void MyMainWindow::ttrl_bttn_clicked()
{
    widget_stack->setCurrentWidget(ttrl);
}

void MyMainWindow::stng_bttn_clicked()
{
    widget_stack->setCurrentWidget(stng);
}

void MyMainWindow::set_init_pos()
{
    QDesktopWidget *desktop = new QDesktopWidget();
    setGeometry((desktop->screen()->width() / 2) - (frameGeometry().width() / 2), (desktop->screen()->height() / 2) - (frameGeometry().height() / 2), frameGeometry().width(), frameGeometry().height());
}

void MyMainWindow::set_media()
{
    med_player = new QMediaPlayer(this);
    med_playlist = new QMediaPlaylist(med_player);
//    med_playlist-addMedia(QUrl::fromLocalFile(MyRes::mainmuse_add));
    med_player->setMedia(QUrl::fromLocalFile(MyRes::mainmuse_add));
    update_stng();
    med_player->play();
}

void MyMainWindow::set_prpts()
{
    setFixedSize(1120, 630);
    set_init_pos();
    setWindowTitle("Awsome Space Shooter");
    QIcon *icon = new QIcon(MyRes::mainwin_icon);
    setWindowIcon(*icon);
    setCentralWidget(widget_stack);
    show();
    delete icon;
}

void MyMainWindow::cnstrct_stack()
{
    widget_stack = new QStackedWidget(this);
    menu = new MyMenu(widget_stack);
    widget_stack->addWidget(menu);
    ttrl = new MyTutorial(widget_stack);
    widget_stack->addWidget(ttrl);
    stng = new MySetting(widget_stack);
    widget_stack->addWidget(stng);
}

void MyMainWindow::set_cnctns()
{
    QObject::connect(stng, SIGNAL(settingChanged()), this, SLOT(update_stng()));
    QObject::connect(med_player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(reset_music()));
    QObject::connect(menu->exit, SIGNAL(clicked()), this, SLOT(exit_bttn_clicked()));
    QObject::connect(menu->ttrl, SIGNAL(clicked()), this, SLOT(ttrl_bttn_clicked()));
    QObject::connect(menu->stng, SIGNAL(clicked()), this, SLOT(stng_bttn_clicked()));
    QObject::connect(ttrl->back, SIGNAL(clicked()), this, SLOT(back_bttn_clicked()));
    QObject::connect(stng->back, SIGNAL(clicked()), this, SLOT(back_bttn_clicked()));
}

void MyMainWindow::reset_music()
{
    med_player->setPosition(0);
    med_player->play();
}

void MyMainWindow::update_stng()
{
    med_player->setVolume(SettingData::mVol);
    med_player->setMuted(SettingData::mMut);
}
