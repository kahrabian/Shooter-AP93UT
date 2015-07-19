//
// Created by kahrabian on 7/11/15.
//

#ifndef SHOOTER_AP93UT_MYTHMTAB_H
#define SHOOTER_AP93UT_MYTHMTAB_H

#include <QPainter>
#include <QStyleOption>
#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <Sources/Headers/Resources.h>

class MythmTab : public QWidget {
Q_OBJECT

	friend class MySetting;

public:
	MythmTab(QWidget * = 0, Qt::WindowFlags = 0);

	~MythmTab();

private:
	QHBoxLayout *thmTab_lay;
	QVBoxLayout *spc_lay;
	QLabel *spc_pic;
	QHBoxLayout *spcbtn_lay;
	QLabel *spc_txt;
	QToolButton *spc_prebtn;
	QToolButton *spc_nexbtn;
	QVBoxLayout *env_lay;
	QLabel *env_pic;
	QHBoxLayout *envbtn_lay;
	QLabel *env_txt;
	QToolButton *env_prebtn;
	QToolButton *env_nexbtn;

	void cnstrct_spc();

	void cnstrct_env();

	void paintEvent(QPaintEvent *);
};

#endif //SHOOTER_AP93UT_MYTHMTAB_H
