//
// Created by kahrabian on 7/9/15.
//

#include "../Headers/Resources.h"

namespace MyRes
{

    const QString *shp_adds = new QString[5] {"Resources/Ships/shp1.png",
                                              "Resources/Ships/shp2.png",
                                              "Resources/Ships/shp3.png",
                                              "Resources/Ships/shp4.png",
                                              "Resources/Ships/shp5.png"};
    const QSize img_init_size(541, 323);
    const QSize app_size(1120, 630);
    const QString stng_add("Resources/resume.txt");
    const QString mainmuse_add("/home/kahrabian/ClionProjects/Shooter-AP93UT/Resources/main_music.wav");
    const QString logo_add("Resources/logo.png");
    const QString background_add("{background-image: url(Resources/main_background.jpg);}");
    const QString mainwdg_stlsheet("QWidget {background-color: rgba(0, 0, 0, 60%);}");
    const QString wdg_stlsheet("QWidget {background-color: transparent;}");
    const QString rdbtn_stlsheet("QRadioButton {font-size: 12pt;}");
    const QString lbl_bstlsheet("QLabel {font-size: 25pt; font-weight: bold;}");
    const QString lbl_stlsheet("QLabel {font-size: 12pt;}");
    const QString chckbx_stlsheet("QCheckBox {font-size: 12pt;}");

    // MyMainWindow
    const QString mainwin_icon("Resources/icon.ico");

    // MyTutorial
    const QString ttrl_howto("A game is structured playing, usually undertaken for enjoyment and sometimes used as an educational tool. Games are distinct from work, which is usually carried out for remuneration, and from art, which is more often an expression of aesthetic or ideological elements. However, the distinction is not clear-cut, and many games are also considered to be work (such as professional players of spectator sports/games) or art (such as jigsaw puzzles or games involving an artistic layout such as Mahjong, solitaire, or some video games). Key components of games are goals, rules, challenge, and interaction. Games generally involve mental or physical stimulation, and often both. Many games help develop practical skills, serve as a form of exercise, or otherwise perform an educational, simulational, or psychological role. Attested as early as 2600 BC, games are a universal part of human experience and present in all cultures. The Royal Game of Ur, Senet, and Mancala are some of the oldest known games.");
    const QString ttrl_rule("Whereas games are often characterized by their tools, they are often defined by their rules. While rules are subject to variations and changes, enough change in the rules usually results in a \"new\" game. For instance, baseball can be played with \"real\" baseballs or with wiffleballs. However, if the players decide to play with only three bases, they are arguably playing a different game. There are exceptions to this in that some games deliberately involve the changing of their own rules, but even then there are often immutable meta-rules. Rules generally determine turn order, the rights and responsibilities of the players, and each player’s goals. Player rights may include when they may spend resources or move tokens. Common win conditions are being first to amass a certain quota of points or tokens (as in Settlers of Catan), having the greatest number of tokens at the end of the game (as in Monopoly), or some relationship of one’s game tokens to those of one’s opponent (as in chess's checkmate).");
    const QString ttrl_txt_stlsheet("background-color: rgba(0, 0, 0, 60%); color : #99FF33; font-size: 25pt");
}
