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
#include <Sources/Headers/Game Objects/MyBullet.h>
#include <Sources/Headers/Resources.h>


class MyAlien : public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
	MyAlien();

	~MyAlien();

	void game_paused();

	void game_unpaused();

	void change_speed();

	void updt_pos();

	void updt();

	void ply_sf(QString &);

	int getTmr_id() const;

	int getTyp() const;

private:
	bool fast;

	int typ;

	int tmr_id;

	int mss;
	QPointF *vlc;
	QPointF *acc;
	QPointF *frc;

protected:
	void timerEvent(QTimerEvent *);
};

#endif //SHOOTER_AP93UT_MYALIEN_H
