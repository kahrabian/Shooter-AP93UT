//
// Created by kahrabian on 7/4/15.
//

#ifndef SHOOTER_AP93UT_MYMAINWINDOW_H
#define SHOOTER_AP93UT_MYMAINWINDOW_H


#include <QDebug>
#include <QTextStream>
#include <QMainWindow>
#include <QStackedWidget>
#include <QDesktopWidget>
#include <QMediaPlayer>
#include <QPixmap>
#include <Sources/Headers/Game/MyGame.h>
#include <Sources/Headers/Resources.h>
#include <Sources/Headers/MyMenu.h>
#include <Sources/Headers/MyTutorial.h>
#include <Sources/Headers/MySetting.h>
#include <Sources/Headers/MyName.h>
#include <Sources/Headers/MyPause.h>
#include <Sources/Headers/MyEnd.h>

class MyMainWindow : QMainWindow {
Q_OBJECT
public:
	MyMainWindow(QWidget * = 0, Qt::WindowFlags = 0);

	~MyMainWindow();

public slots:

	void game_paused();

	void game_unpaused();

	void game_restart();

	void game_ended();

	void strt_bttn_clicked();

	void newg_bttn_clicked();

	void resm_bttn_clicked();

	void exit_bttn_clicked();

	void ttrl_bttn_clicked();

	void stng_bttn_clicked();

	void back_bttn_clicked();

	void reset_music();

	void update_stng();

private:
	QMediaPlayer *med_player;
	QStackedWidget *widget_stack;
	MyMenu *menu;
	MyTutorial *ttrl;
	MySetting *stng;
	MyName *name;
	MyGame *game;
	MyPause *ps;
	MyEnd *end;

	void set_init_pos();

	void set_media();

	void set_prpts();

	void cnstrct_stack();

	void set_cnctns();
};


#endif //SHOOTER_AP93UT_MYMAINWINDOW_H
