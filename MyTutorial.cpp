//
// Created by kahrabian on 7/5/15.
//

#include "MyTutorial.h"

MyTutorial::MyTutorial(QWidget *parent, Qt::WindowFlags f) :
        QWidget(parent, f)
{
    this->resize(1120, 630);
    this->setStyleSheet("image: url(/home/kahrabian/ClionProjects/Shooter-AP93UT/Contents/background_menu.jpg);");
    this->back = new QPushButton("Back", this);
    this->construct_logo();
    this->construct_text();
    this->construct_tutorial();
}

MyTutorial::~MyTutorial()
{
}

void MyTutorial::construct_tutorial()
{
    this->tutorial = new QVBoxLayout(this);
    this->tutorial->addWidget(this->logo);
//    this->tutorial->addSpacing(630);
    this->tutorial->addWidget(this->text);
    this->tutorial->addSpacing(630);
    this->tutorial->addWidget(this->back);
}

void MyTutorial::construct_text()
{
    this->text = new QTextEdit("A game is structured playing, usually undertaken for enjoyment and sometimes used as an educational tool. Games are distinct from work, which is usually carried out for remuneration, and from art, which is more often an expression of aesthetic or ideological elements. However, the distinction is not clear-cut, and many games are also considered to be work (such as professional players of spectator sports/games) or art (such as jigsaw puzzles or games involving an artistic layout such as Mahjong, solitaire, or some video games). Key components of games are goals, rules, challenge, and interaction. Games generally involve mental or physical stimulation, and often both. Many games help develop practical skills, serve as a form of exercise, or otherwise perform an educational, simulational, or psychological role. Attested as early as 2600 BC, games are a universal part of human experience and present in all cultures. The Royal Game of Ur, Senet, and Mancala are some of the oldest known games.", this);
    this->text->setReadOnly(true);
    this->text->setStyleSheet("background-color: rgba(255, 255, 255, 15); color : yellow; font-size: 15pt");
}

void MyTutorial::construct_logo()
{
    this->logo = new QLabel(this);
    QPixmap *my_pix = new QPixmap("/home/kahrabian/ClionProjects/Shooter-AP93UT/Contents/logo.png");
    this->logo->setPixmap(*my_pix);
    this->logo->setAlignment(Qt::AlignHCenter);
    this->logo->setAttribute(Qt::WA_TranslucentBackground);
    delete my_pix;
}

void MyTutorial::paintEvent(QPaintEvent *my_event)
{
    QPainter *my_painter = new QPainter(this);
    QStyleOption *my_option = new QStyleOption();
    my_option->init(this);
    this->style()->drawPrimitive(QStyle::PE_Widget, my_option, my_painter, this);
    QWidget::paintEvent(my_event);
}