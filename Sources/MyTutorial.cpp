//
// Created by kahrabian on 7/5/15.
//

#include "MyTutorial.h"

MyTutorial::MyTutorial(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    resize(1120, 630);
    setStyleSheet("MyTutorial {background-image: url(/home/kahrabian/ClionProjects/Shooter-AP93UT/Resources/background.jpg);}");
    back = new QPushButton("Back", this);
    cnstrct_logo();
    cnstrct_txt();
    cnstrct_ttrl();
}

MyTutorial::~MyTutorial()
{
}

void MyTutorial::cnstrct_ttrl()
{
    ttrl = new QVBoxLayout(this);
    ttrl->addWidget(logo);
    ttrl->addWidget(txt);
    ttrl->addWidget(back);
}

void MyTutorial::cnstrct_txt()
{
    txt = new QTextEdit("A game is structured playing, usually undertaken for enjoyment and sometimes used as an educational tool. Games are distinct from work, which is usually carried out for remuneration, and from art, which is more often an expression of aesthetic or ideological elements. However, the distinction is not clear-cut, and many games are also considered to be work (such as professional players of spectator sports/games) or art (such as jigsaw puzzles or games involving an artistic layout such as Mahjong, solitaire, or some video games). Key components of games are goals, rules, challenge, and interaction. Games generally involve mental or physical stimulation, and often both. Many games help develop practical skills, serve as a form of exercise, or otherwise perform an educational, simulational, or psychological role. Attested as early as 2600 BC, games are a universal part of human experience and present in all cultures. The Royal Game of Ur, Senet, and Mancala are some of the oldest known games.", this);
    txt->setReadOnly(true);
    txt->setStyleSheet("background-color: rgba(0, 0, 0, 60%); color : #99FF33; font-size: 25pt");
    txt->setFocusPolicy(Qt::NoFocus);
}

void MyTutorial::cnstrct_logo()
{
    logo = new QLabel(this);
    QPixmap *my_pix = new QPixmap("/home/kahrabian/ClionProjects/Shooter-AP93UT/Resources/logo.png");
    logo->setPixmap(*my_pix);
    logo->setAlignment(Qt::AlignHCenter);
    logo->setAttribute(Qt::WA_TranslucentBackground, true);
    delete my_pix;
}

void MyTutorial::paintEvent(QPaintEvent *my_event)
{
    QPainter *my_painter = new QPainter(this);
    QStyleOption *my_option = new QStyleOption();
    my_option->init(this);
    style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
    QWidget::paintEvent(my_event);
}