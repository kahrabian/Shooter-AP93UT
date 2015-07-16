//
// Created by kahrabian on 7/16/15.
//

#ifndef SHOOTER_AP93UT_MYNAME_H
#define SHOOTER_AP93UT_MYNAME_H

#include <QBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QStyleOption>
#include <QPainter>
#include "Resources.h"


class MyName : public QWidget
{
	Q_OBJECT
	friend class MyMainWindow;
public:
	MyName(QWidget * = 0, Qt::WindowFlags = 0);
	~MyName();

private:
	QVBoxLayout *nm_lay;

	QHBoxLayout *btns;
	QPushButton *strt;
	QPushButton *back;

	QVBoxLayout *frm_lay;
	QHBoxLayout *frst_nm_lay;
	QLabel *frst_nm_lbl;
	QLineEdit *frst_nm_txt;
	QHBoxLayout *scnd_nm_lay;
	QLabel *scnd_nm_lbl;
	QLineEdit *scnd_nm_txt;

	QLabel *logo;

	void cnstrct_logo();
	void cnstrct_frm();
	void cnstrct_btns();
	void cnstrct_nm();
	void reset();
	void paintEvent(QPaintEvent *);
};

#endif //SHOOTER_AP93UT_MYNAME_H
