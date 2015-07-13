//
// Created by kahrabian on 7/12/15.
//

#ifndef SHOOTER_AP93UT_MYGAME_H
#define SHOOTER_AP93UT_MYGAME_H

#include <QGraphicsScene>
#include <QElapsedTimer>

class MyGame : public QGraphicsScene
{
    Q_OBJECT
    friend class MyMainWindow;
public:
    MyGame(QObject * = 0);
    MyGame(const QRectF &, QObject * = 0);
    MyGame(qreal, qreal, qreal, qreal, QObject * = 0);
    ~MyGame();

private:
//    QVector<> shps;
//    QVector<> blts;
//    QVector<> astrs;
//    QVector<> strs;
//    QVector<> alns;
//    QVector<> lfs;
//    QVector<> shlds;
//    QVector<> mgns;

	QTimer *g_tmr;
	QElapsedTimer *stp_tmr;
	qint64 stp_tmr_val;
};

#endif //SHOOTER_AP93UT_MYGAME_H
