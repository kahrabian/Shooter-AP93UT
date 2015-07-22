//
// Created by kahrabian on 7/17/15.
//

#ifndef SHOOTER_AP93UT_MYEND_H
#define SHOOTER_AP93UT_MYEND_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QStyleOption>
#include <QPainter>
#include <QFile>
#include <Sources/Headers/Resources.h>

class MyEnd : public QWidget {
Q_OBJECT

	friend class MyMainWindow;

public:
	MyEnd(QWidget * = 0, Qt::WindowFlags = 0);

	~MyEnd();

private:
	QVBoxLayout *end;
	QHBoxLayout *btns;
	QPushButton *exit;
	QPushButton *rest;
	QLabel *txt;
	QLabel *logo;

	void cnstrct_btns();

	void cnstrct_logo();

	void cnstrct_end();

	void paintEvent(QPaintEvent *);
};

#endif //SHOOTER_AP93UT_MYEND_H
