//
// Created by kahrabian on 7/5/15.
//

#ifndef SHOOTER_AP93UT_MYTUTORIAL_H
#define SHOOTER_AP93UT_MYTUTORIAL_H


#include <QtWidgets/qwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qtextedit.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qstyleoption.h>
#include <QtGui/qpainter.h>


class MyTutorial : public QWidget
{
    Q_OBJECT
    friend class MyMainWindow;
public:
    MyTutorial(QWidget * = 0, Qt::WindowFlags = 0);
    ~MyTutorial();

private:
    QVBoxLayout *tutorial;
    QPushButton *back;
    QTextEdit *text;
    QLabel *logo;

    void construct_logo();
    void construct_text();
    void construct_tutorial();
    void paintEvent(QPaintEvent *);
};


#endif //SHOOTER_AP93UT_MYTUTORIAL_H
