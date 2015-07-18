//
// Created by kahrabian on 7/12/15.
//

#ifndef SHOOTER_AP93UT_MYSHIP_H
#define SHOOTER_AP93UT_MYSHIP_H

#include <QGraphicsPixmapItem>
#include <QElapsedTimer>
#include <QTimer>
#include <QPointF>
#include <QString>
#include <QPixmap>

class MyShip : public QGraphicsPixmapItem {
public:
	MyShip(QGraphicsItem *parent = 0);

	MyShip(const QPixmap &pixmap, QGraphicsItem *parent = 0);

	~MyShip();

	int getLf() const;

	void setLf(int lf);

	int getScr() const;

	void setScr(int scr);

	bool isShld() const;

	void setShld(bool shld);

	bool isMgc() const;

	void setMgc(bool mgc);

	void updt(qint64 = 0);

private:
	QString *name;

	int lf;
	int scr;
	bool shld;
	QTimer *shld_tmr;
	bool mgc;
	QTimer *mgc_tmr;

	QElapsedTimer *frm_tmr;

	int mss;
	QPointF *pos;
	QPointF *vlc;
	QPointF *acc;
	QPointF *frc;
};

#endif //SHOOTER_AP93UT_MYSHIP_H
