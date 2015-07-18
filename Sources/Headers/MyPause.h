//
// Created by kahrabian on 7/16/15.
//

#ifndef SHOOTER_AP93UT_MYPAUSE_H
#define SHOOTER_AP93UT_MYPAUSE_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QStyleOption>
#include <QPainter>
#include <QFile>
#include <QKeyEvent>
#include "Resources.h"
#include "MyaudioTab.h"

class MyPause : public QWidget {
Q_OBJECT

	friend class MyMainWindow;

public:
	MyPause(QWidget * = 0, Qt::WindowFlags = 0);

	~MyPause();

public slots:

	void update_stng();

signals:

	void settingChanged();

	void gameUnpaused();

private:
	QVBoxLayout *ps_lay;
	MyaudioTab *aud;
	QHBoxLayout *btns;
	QPushButton *exit;
	QPushButton *resm;
	QPushButton *rest;
	QLabel *logo;

	void set_cnctns();

	void cnstrct_btns();

	void cnstrct_logo();

	void cnstrct_ps();

	void set_bckgrnd();

protected:
	void keyPressEvent(QKeyEvent *);

	void paintEvent(QPaintEvent *);
};


#endif //SHOOTER_AP93UT_MYPAUSE_H
