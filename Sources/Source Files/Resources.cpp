//
// Created by kahrabian on 7/9/15.
//

#include <Sources/Headers/Resources.h>

namespace MyRes {
    // Game properties
    const QSize lf_size(35, 35);
    const QSize lsr_size(30, 8);
    const QSize str_size(30, 30);
    const QSize mgc_size(40, 40);
    const QSize shld_size(43, 43);
    const QSize astrd_size(350, 350);
    const QSize aln_bgsize(70, 70);
    const QSize aln_smllsize(140, 140);
    const QSize shp_size(100, 100);
    const QSize shp_shld_size(150, 150);
    const QSize expln_aln_smll_size(175, 175);
    const QSize expln_aln_bg_size(350, 350);
    const QSize expln_lsr_size(75, 75);
    const QSize expln_shp_size(300, 300);
    const QSize expln_astrd_size(400, 400);

    // Contents size
    const QSize img_init_size(541, 323);
    const QSize app_size(1120, 630);
    const QRect scn_rct(0, 0, app_size.width() + (gm_drtn / frm_dly), app_size.height());
    const QSize tl_size(50, 50);

    // Resource location addresses
    const QString shp_adds[shp_cnt] = {"Resources/Ships/shp1.png", "Resources/Ships/shp2.png",
                                       "Resources/Ships/shp3.png", "Resources/Ships/shp4.png",
                                       "Resources/Ships/shp5.png"};
    const QString shp_shld_add("Resources/Ships/shpshld.png");
    const QString aln_bss_adds[aln_bss_cnt] = {"Resources/Aliens/Boss/bss1.png", "Resources/Aliens/Boss/bss2.png",
                                               "Resources/Aliens/Boss/bss3.png", "Resources/Aliens/Boss/bss4.png",
                                               "Resources/Aliens/Boss/bss5.png"};
    const QString aln_nrml_adds[aln_nrml_cnt] = {"Resources/Aliens/Normal/aln1.png", "Resources/Aliens/Normal/aln2.png",
                                                 "Resources/Aliens/Normal/aln3.png", "Resources/Aliens/Normal/aln4.png",
                                                 "Resources/Aliens/Normal/aln5.png", "Resources/Aliens/Normal/aln6.png",
                                                 "Resources/Aliens/Normal/aln7.png", "Resources/Aliens/Normal/aln8.png",
                                                 "Resources/Aliens/Normal/aln9.png",
                                                 "Resources/Aliens/Normal/aln10.png",
                                                 "Resources/Aliens/Normal/aln11.png"};
    const QString env_adds[env_cnt] = {"Resources/Environments/txtr1.jpeg", "Resources/Environments/txtr2.jpeg",
                                       "Resources/Environments/txtr3.jpeg", "Resources/Environments/txtr4.jpeg",
                                       "Resources/Environments/txtr5.jpeg", "Resources/Environments/txtr6.jpeg",
                                       "Resources/Environments/txtr7.jpeg", "Resources/Environments/txtr8.jpeg",
                                       "Resources/Environments/txtr9.jpeg", "Resources/Environments/txtr10.jpeg",
                                       "Resources/Environments/txtr11.jpeg", "Resources/Environments/txtr12.jpeg",
                                       "Resources/Environments/txtr13.jpeg", "Resources/Environments/txtr14.jpeg",
                                       "Resources/Environments/txtr15.jpeg", "Resources/Environments/txtr16.jpeg"};
    const QString expln_adds[expln_frcnt] = {"Resources/Objects/Explosion/explsn1.png",
                                             "Resources/Objects/Explosion/explsn2.png",
                                             "Resources/Objects/Explosion/explsn3.png",
                                             "Resources/Objects/Explosion/explsn4.png",
                                             "Resources/Objects/Explosion/explsn5.png",
                                             "Resources/Objects/Explosion/explsn6.png",
                                             "Resources/Objects/Explosion/explsn7.png",
                                             "Resources/Objects/Explosion/explsn8.png",
                                             "Resources/Objects/Explosion/explsn9.png",
                                             "Resources/Objects/Explosion/explsn10.png",
                                             "Resources/Objects/Explosion/explsn11.png",
                                             "Resources/Objects/Explosion/explsn12.png",
                                             "Resources/Objects/Explosion/explsn13.png",
                                             "Resources/Objects/Explosion/explsn14.png",
                                             "Resources/Objects/Explosion/explsn15.png",
                                             "Resources/Objects/Explosion/explsn16.png",
                                             "Resources/Objects/Explosion/explsn17.png",
                                             "Resources/Objects/Explosion/explsn18.png",
                                             "Resources/Objects/Explosion/explsn19.png",
                                             "Resources/Objects/Explosion/explsn20.png",
                                             "Resources/Objects/Explosion/explsn21.png",
                                             "Resources/Objects/Explosion/explsn22.png",
                                             "Resources/Objects/Explosion/explsn23.png",
                                             "Resources/Objects/Explosion/explsn24.png",
                                             "Resources/Objects/Explosion/explsn25.png",
                                             "Resources/Objects/Explosion/explsn26.png",
                                             "Resources/Objects/Explosion/explsn27.png",
                                             "Resources/Objects/Explosion/explsn28.png",
                                             "Resources/Objects/Explosion/explsn29.png",
                                             "Resources/Objects/Explosion/explsn30.png",
                                             "Resources/Objects/Explosion/explsn31.png",
                                             "Resources/Objects/Explosion/explsn32.png",
                                             "Resources/Objects/Explosion/explsn33.png",
                                             "Resources/Objects/Explosion/explsn34.png",
                                             "Resources/Objects/Explosion/explsn35.png",
                                             "Resources/Objects/Explosion/explsn36.png",
                                             "Resources/Objects/Explosion/explsn37.png",
                                             "Resources/Objects/Explosion/explsn38.png",
                                             "Resources/Objects/Explosion/explsn39.png",
                                             "Resources/Objects/Explosion/explsn40.png",
                                             "Resources/Objects/Explosion/explsn41.png",
                                             "Resources/Objects/Explosion/explsn42.png",
                                             "Resources/Objects/Explosion/explsn43.png",
                                             "Resources/Objects/Explosion/explsn44.png",
                                             "Resources/Objects/Explosion/explsn45.png",
                                             "Resources/Objects/Explosion/explsn46.png",
                                             "Resources/Objects/Explosion/explsn47.png",
                                             "Resources/Objects/Explosion/explsn48.png",
                                             "Resources/Objects/Explosion/explsn49.png",
                                             "Resources/Objects/Explosion/explsn50.png",
                                             "Resources/Objects/Explosion/explsn51.png",
                                             "Resources/Objects/Explosion/explsn52.png",
                                             "Resources/Objects/Explosion/explsn53.png",
                                             "Resources/Objects/Explosion/explsn54.png",
                                             "Resources/Objects/Explosion/explsn55.png",
                                             "Resources/Objects/Explosion/explsn56.png",
                                             "Resources/Objects/Explosion/explsn57.png",
                                             "Resources/Objects/Explosion/explsn58.png",
                                             "Resources/Objects/Explosion/explsn59.png",
                                             "Resources/Objects/Explosion/explsn60.png",
                                             "Resources/Objects/Explosion/explsn61.png",
                                             "Resources/Objects/Explosion/explsn62.png",
                                             "Resources/Objects/Explosion/explsn63.png",
                                             "Resources/Objects/Explosion/explsn64.png",
                                             "Resources/Objects/Explosion/explsn65.png",
                                             "Resources/Objects/Explosion/explsn66.png",
                                             "Resources/Objects/Explosion/explsn67.png",
                                             "Resources/Objects/Explosion/explsn68.png",
                                             "Resources/Objects/Explosion/explsn69.png",
                                             "Resources/Objects/Explosion/explsn70.png",
                                             "Resources/Objects/Explosion/explsn71.png",
                                             "Resources/Objects/Explosion/explsn72.png",
                                             "Resources/Objects/Explosion/explsn73.png",
                                             "Resources/Objects/Explosion/explsn74.png",
                                             "Resources/Objects/Explosion/explsn75.png",
                                             "Resources/Objects/Explosion/explsn76.png",
                                             "Resources/Objects/Explosion/explsn77.png",
                                             "Resources/Objects/Explosion/explsn78.png",
                                             "Resources/Objects/Explosion/explsn79.png",
                                             "Resources/Objects/Explosion/explsn80.png",
                                             "Resources/Objects/Explosion/explsn81.png",
                                             "Resources/Objects/Explosion/explsn82.png",
                                             "Resources/Objects/Explosion/explsn83.png",
                                             "Resources/Objects/Explosion/explsn84.png",
                                             "Resources/Objects/Explosion/explsn85.png",
                                             "Resources/Objects/Explosion/explsn86.png",
                                             "Resources/Objects/Explosion/explsn87.png",
                                             "Resources/Objects/Explosion/explsn88.png",
                                             "Resources/Objects/Explosion/explsn89.png",
                                             "Resources/Objects/Explosion/explsn90.png"};

    const QString astrd_adds[astrd_typcnt][astrd_frcnt] = {{"Resources/Asteroids/astrd11.png", "Resources/Asteroids/astrd12.png", "Resources/Asteroids/astrd13.png", "Resources/Asteroids/astrd14.png", "Resources/Asteroids/astrd15.png", "Resources/Asteroids/astrd16.png", "Resources/Asteroids/astrd17.png", "Resources/Asteroids/astrd18.png", "Resources/Asteroids/astrd19.png", "Resources/Asteroids/astrd110.png", "Resources/Asteroids/astrd111.png", "Resources/Asteroids/astrd112.png", "Resources/Asteroids/astrd113.png", "Resources/Asteroids/astrd114.png", "Resources/Asteroids/astrd115.png", "Resources/Asteroids/astrd116.png"},
                                                           {"Resources/Asteroids/astrd21.png", "Resources/Asteroids/astrd22.png", "Resources/Asteroids/astrd23.png", "Resources/Asteroids/astrd24.png", "Resources/Asteroids/astrd25.png", "Resources/Asteroids/astrd26.png", "Resources/Asteroids/astrd27.png", "Resources/Asteroids/astrd28.png", "Resources/Asteroids/astrd29.png", "Resources/Asteroids/astrd210.png", "Resources/Asteroids/astrd211.png", "Resources/Asteroids/astrd212.png", "Resources/Asteroids/astrd213.png", "Resources/Asteroids/astrd214.png", "Resources/Asteroids/astrd215.png", "Resources/Asteroids/astrd216.png"},
                                                           {"Resources/Asteroids/astrd31.png", "Resources/Asteroids/astrd32.png", "Resources/Asteroids/astrd33.png", "Resources/Asteroids/astrd34.png", "Resources/Asteroids/astrd35.png", "Resources/Asteroids/astrd36.png", "Resources/Asteroids/astrd37.png", "Resources/Asteroids/astrd38.png", "Resources/Asteroids/astrd39.png", "Resources/Asteroids/astrd310.png", "Resources/Asteroids/astrd311.png", "Resources/Asteroids/astrd312.png", "Resources/Asteroids/astrd313.png", "Resources/Asteroids/astrd314.png", "Resources/Asteroids/astrd315.png", "Resources/Asteroids/astrd316.png"},
                                                           {"Resources/Asteroids/astrd41.png", "Resources/Asteroids/astrd42.png", "Resources/Asteroids/astrd43.png", "Resources/Asteroids/astrd44.png", "Resources/Asteroids/astrd45.png", "Resources/Asteroids/astrd46.png", "Resources/Asteroids/astrd47.png", "Resources/Asteroids/astrd48.png", "Resources/Asteroids/astrd49.png", "Resources/Asteroids/astrd410.png", "Resources/Asteroids/astrd411.png", "Resources/Asteroids/astrd412.png", "Resources/Asteroids/astrd413.png", "Resources/Asteroids/astrd414.png", "Resources/Asteroids/astrd415.png", "Resources/Asteroids/astrd416.png"},
                                                           {"Resources/Asteroids/astrd51.png", "Resources/Asteroids/astrd52.png", "Resources/Asteroids/astrd53.png", "Resources/Asteroids/astrd54.png", "Resources/Asteroids/astrd55.png", "Resources/Asteroids/astrd56.png", "Resources/Asteroids/astrd57.png", "Resources/Asteroids/astrd58.png", "Resources/Asteroids/astrd59.png", "Resources/Asteroids/astrd510.png", "Resources/Asteroids/astrd511.png", "Resources/Asteroids/astrd512.png", "Resources/Asteroids/astrd513.png", "Resources/Asteroids/astrd514.png", "Resources/Asteroids/astrd515.png", "Resources/Asteroids/astrd516.png"},
                                                           {"Resources/Asteroids/astrd61.png", "Resources/Asteroids/astrd62.png", "Resources/Asteroids/astrd63.png", "Resources/Asteroids/astrd64.png", "Resources/Asteroids/astrd65.png", "Resources/Asteroids/astrd66.png", "Resources/Asteroids/astrd67.png", "Resources/Asteroids/astrd68.png", "Resources/Asteroids/astrd69.png", "Resources/Asteroids/astrd610.png", "Resources/Asteroids/astrd611.png", "Resources/Asteroids/astrd612.png", "Resources/Asteroids/astrd613.png", "Resources/Asteroids/astrd614.png", "Resources/Asteroids/astrd615.png", "Resources/Asteroids/astrd616.png"},
                                                           {"Resources/Asteroids/astrd71.png", "Resources/Asteroids/astrd72.png", "Resources/Asteroids/astrd73.png", "Resources/Asteroids/astrd74.png", "Resources/Asteroids/astrd75.png", "Resources/Asteroids/astrd76.png", "Resources/Asteroids/astrd77.png", "Resources/Asteroids/astrd78.png", "Resources/Asteroids/astrd79.png", "Resources/Asteroids/astrd710.png", "Resources/Asteroids/astrd711.png", "Resources/Asteroids/astrd712.png", "Resources/Asteroids/astrd713.png", "Resources/Asteroids/astrd714.png", "Resources/Asteroids/astrd715.png", "Resources/Asteroids/astrd716.png"}};
    const QString str_add("Resources/Objects/str.png");
    const QString shld_add("Resources/Objects/shld.png");
    const QString lf_add("Resources/Objects/lf.png");
    const QString lsr_add[lsr_cnt] = {"Resources/Objects/Laser/lsr1.png", "Resources/Objects/Laser/lsr2.png"};
    const QString mgc_add[mgc_cnt] = {"Resources/Objects/Magic/mgc1.png", "Resources/Objects/Magic/mgc2.png",
                                      "Resources/Objects/Magic/mgc3.png", "Resources/Objects/Magic/mgc4.png"};
    const QString stng_add("Resources/resume.txt");
    const QString mainmuse_add("/home/kahrabian/ClionProjects/Shooter-AP93UT/Resources/main_music.wav");
    const QString logo_add("Resources/logo.png");
    const QString background_add("{background-image: url(Resources/main_background.jpg);}");
    const QString scrnsht_add("Resources/scrnsht.png");
    const QString mainwin_icon_add("Resources/icon.ico");

    // Stylesheets
    const QString mainwdg_stlsheet("QWidget {background-color: rgba(0, 0, 0, 60%);}");
    const QString wdg_stlsheet("QWidget {background-color: transparent;}");
    const QString rdbtn_stlsheet("QRadioButton {font-size: 12pt;}");
    const QString lbl_bstlsheet("QLabel {font-size: 25pt; font-weight: bold;}");
    const QString lbl_stlsheet("QLabel {font-size: 12pt;}");
    const QString chckbx_stlsheet("QCheckBox {font-size: 12pt;}");
    const QString ttrl_txt_stlsheet("background-color: rgba(0, 0, 0, 60%); color : #99FF33; font-size: 25pt");
    const QString nm_txt_stlsheet("background-color: rgba(0, 0, 0, 60%); color : #99FF33; font-size: 10pt");
    const QString ps_stlsheet("{background-image: url(Resources/scrnsht.png);}");

    // MyTutorial
    const QString ttrl_howto(
		    "A game is structured playing, usually undertaken for enjoyment and sometimes used as an educational tool. Games are distinct from work, which is usually carried out for remuneration, and from art, which is more often an expression of aesthetic or ideological elements. However, the distinction is not clear-cut, and many games are also considered to be work (such as professional players of spectator sports/games) or art (such as jigsaw puzzles or games involving an artistic layout such as Mahjong, solitaire, or some video games). Key components of games are goals, rules, challenge, and interaction. Games generally involve mental or physical stimulation, and often both. Many games help develop practical skills, serve as a form of exercise, or otherwise perform an educational, simulational, or psychological role. Attested as early as 2600 BC, games are a universal part of human experience and present in all cultures. The Royal Game of Ur, Senet, and Mancala are some of the oldest known games.");
    const QString ttrl_rule(
		    "Whereas games are often characterized by their tools, they are often defined by their rules. While rules are subject to variations and changes, enough change in the rules usually results in a \"new\" game. For instance, baseball can be played with \"real\" baseballs or with wiffleballs. However, if the players decide to play with only three bases, they are arguably playing a different game. There are exceptions to this in that some games deliberately involve the changing of their own rules, but even then there are often immutable meta-rules. Rules generally determine turn order, the rights and responsibilities of the players, and each player’s goals. Player rights may include when they may spend resources or move tokens. Common win conditions are being first to amass a certain quota of points or tokens (as in Settlers of Catan), having the greatest number of tokens at the end of the game (as in Monopoly), or some relationship of one’s game tokens to those of one’s opponent (as in chess's checkmate).");
}
