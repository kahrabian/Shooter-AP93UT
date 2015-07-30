//
// Created by kahrabian on 7/13/15.
//

#ifndef SHOOTER_AP93UT_MYALIEN_H
#define SHOOTER_AP93UT_MYALIEN_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QElapsedTimer>
#include <QPointF>
#include <QPixmap>
#include <Sources/Headers/Game Objects/MyAsteroid.h>
#include <Sources/Headers/Game Objects/MyBullet.h>
#include <Sources/Headers/Resources.h>


class MyAlien : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
	MyAlien(int);

	~MyAlien();

	void game_paused();

	void game_unpaused();

	void change_speed();

	void updt();

	void ply_sf(QString &);

	int getTmr_id() const;

	int getTyp() const;

private:
	MyAsteroid *par;

	bool fast;

	int typ;

	bool rttn;
	int rtn;

	int tmr_id;

	QPointF *vlc;

	void cllsn_dtctn();

protected:
	void timerEvent(QTimerEvent *);
};

#endif //SHOOTER_AP93UT_MYALIEN_H
