//
// Created by kahrabian on 7/5/15.
//

#ifndef SHOOTER_AP93UT_MYTUTORIAL_H
#define SHOOTER_AP93UT_MYTUTORIAL_H


#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QStyleOption>
#include <QPainter>
#include "Resources.h"


class MyTutorial : public QWidget
{
    Q_OBJECT
    friend class MyMainWindow;
public:
    MyTutorial(QWidget * = 0, Qt::WindowFlags = 0);
    ~MyTutorial();

private:
    QVBoxLayout *ttrl;
    QPushButton *back;
    QHBoxLayout *txt;
    QVBoxLayout *howto_lay;
    QLabel *howto_txt;
    QTextEdit *howto;
    QVBoxLayout *rule_lay;
    QLabel *rule_txt;
    QTextEdit *rule;
    QLabel *logo;

    void cnstrct_logo();
    void cnstrct_howto();
    void cnstrct_rule();
    void cnstrct_ttrl();
    void paintEvent(QPaintEvent *);
};


#endif //SHOOTER_AP93UT_MYTUTORIAL_H
