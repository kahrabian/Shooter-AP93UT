//
// Created by kahrabian on 7/4/15.
//

#include <Sources/Headers/MyMainWindow.h>

MyMainWindow::MyMainWindow(QWidget *parent, Qt::WindowFlags flag) :
		QMainWindow(parent, flag) {
	set_media();
	cnstrct_stack();
	set_prpts();
	set_cnctns();
}

MyMainWindow::~MyMainWindow() { }

void MyMainWindow::game_paused() {
	QPixmap::grabWidget(game, game->frameGeometry()).save(MyRes::scrnsht_add);
	ps->set_bckgrnd();
	widget_stack->setCurrentWidget(ps);
}

void MyMainWindow::game_unpaused() {
	widget_stack->setCurrentWidget(game);
	game->unpause();
}

void MyMainWindow::game_restart() {
	widget_stack->setCurrentWidget(game);
	game->restart();
}

void MyMainWindow::game_ended() {
	widget_stack->setCurrentWidget(end);
	game->restart();
}

void MyMainWindow::exit_bttn_clicked() {
	close();
}

void MyMainWindow::back_bttn_clicked() {
	widget_stack->setCurrentWidget(menu);
}

void MyMainWindow::ttrl_bttn_clicked() {
	widget_stack->setCurrentWidget(ttrl);
}

void MyMainWindow::stng_bttn_clicked() {
	widget_stack->setCurrentWidget(stng);
}

void MyMainWindow::newg_bttn_clicked() {
	name->reset();
	widget_stack->setCurrentWidget(name);
}

void MyMainWindow::resm_bttn_clicked() {
	widget_stack->setCurrentWidget(stng);
}

void MyMainWindow::strt_bttn_clicked() {
	SettingData::p1_nm = name->frst_nm_txt->text();
	SettingData::p2_nm = name->scnd_nm_txt->text();
	game = new MyGame(widget_stack);
	widget_stack->addWidget(game);
	widget_stack->setCurrentWidget(game);
	QObject::connect(game, SIGNAL(gamePaused()), this, SLOT(game_paused()));
	QObject::connect(game, SIGNAL(gameEnded()), this, SLOT(game_ended()));
}

void MyMainWindow::set_init_pos() {
	QDesktopWidget *desktop = new QDesktopWidget();
	setGeometry((desktop->screen()->width() / 2) - (frameGeometry().width() / 2),
	            (desktop->screen()->height() / 2) - (frameGeometry().height() / 2), frameGeometry().width(),
	            frameGeometry().height());
}

void MyMainWindow::set_media() {
	med_player = new QMediaPlayer(this);
	med_player->setMedia(QUrl::fromLocalFile(MyRes::mainmuse_add));
	med_player->setVolume(SettingData::mVol);
	med_player->setMuted(SettingData::mMut);
	med_player->play();
}

void MyMainWindow::set_prpts() {
	setFixedSize(MyRes::app_size);
	set_init_pos();
	setWindowTitle("Awesome Space Shooter");
	setWindowIcon(QIcon(MyRes::mainwin_icon_add));
	setCentralWidget(widget_stack);
	show();
}

void MyMainWindow::cnstrct_stack() {
	widget_stack = new QStackedWidget(this);
	menu = new MyMenu(widget_stack);
	widget_stack->addWidget(menu);
	ttrl = new MyTutorial(widget_stack);
	widget_stack->addWidget(ttrl);
	stng = new MySetting(widget_stack);
	widget_stack->addWidget(stng);
	name = new MyName(widget_stack);
	widget_stack->addWidget(name);
	ps = new MyPause(widget_stack);
	widget_stack->addWidget(ps);
	end = new MyEnd(widget_stack);
	widget_stack->addWidget(end);
}

void MyMainWindow::set_cnctns() {
	QObject::connect(med_player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(reset_music()));

	QObject::connect(menu->rsm, SIGNAL(clicked()), this, SLOT(resm_bttn_clicked()));
	QObject::connect(menu->start, SIGNAL(clicked()), this, SLOT(newg_bttn_clicked()));
	QObject::connect(menu->exit, SIGNAL(clicked()), this, SLOT(exit_bttn_clicked()));
	QObject::connect(menu->ttrl, SIGNAL(clicked()), this, SLOT(ttrl_bttn_clicked()));
	QObject::connect(menu->stng, SIGNAL(clicked()), this, SLOT(stng_bttn_clicked()));

	QObject::connect(ttrl->back, SIGNAL(clicked()), this, SLOT(back_bttn_clicked()));

	QObject::connect(stng, SIGNAL(settingChanged()), this, SLOT(update_stng()));
	QObject::connect(stng->back, SIGNAL(clicked()), this, SLOT(back_bttn_clicked()));

	QObject::connect(name->strt, SIGNAL(clicked()), this, SLOT(strt_bttn_clicked()));
	QObject::connect(name->back, SIGNAL(clicked()), this, SLOT(back_bttn_clicked()));

	QObject::connect(ps, SIGNAL(settingChanged()), this, SLOT(update_stng()));
	QObject::connect(ps, SIGNAL(gameUnpaused()), this, SLOT(game_unpaused()));
	QObject::connect(ps->exit, SIGNAL(clicked()), this, SLOT(back_bttn_clicked()));
	QObject::connect(ps->rest, SIGNAL(clicked()), this, SLOT(game_restart()));
	QObject::connect(ps->resm, SIGNAL(clicked()), this, SLOT(game_unpaused()));

	QObject::connect(end->exit, SIGNAL(clicked()), this, SLOT(back_bttn_clicked()));
	QObject::connect(end->rest, SIGNAL(clicked()), this, SLOT(game_restart()));
}

void MyMainWindow::reset_music() {
	med_player->setPosition(0);
	med_player->play();
}

void MyMainWindow::update_stng() {
	stng->audTab->sync();
	ps->aud->sync();
	med_player->setVolume(SettingData::mVol);
	med_player->setMuted(SettingData::mMut);
}
