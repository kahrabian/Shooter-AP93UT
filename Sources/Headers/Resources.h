//
// Created by kahrabian on 7/9/15.
//

#ifndef SHOOTER_AP93UT_RESOURCES_H
#define SHOOTER_AP93UT_RESOURCES_H

#include <QString>
#include <QSize>
#include <QVector>
#include <QMediaPlaylist>
#include "SettingData.h"

namespace MyRes
{
    const int env_cnt = 16;
    const int shp_cnt = 5;
    const int astrd_frcnt = 16;
    const int astrd_typcnt = 7;
	extern const QString shp_adds[shp_cnt];
	extern const QString env_adds[env_cnt];
    extern const QString astrd_adds[astrd_typcnt][astrd_frcnt];
    extern const QSize img_init_size;
    extern const QSize app_size;
    extern const QString stng_add;
    extern const QString mainmuse_add;
    extern const QString logo_add;
    extern const QString background_add;
    extern const QString mainwdg_stlsheet;
    extern const QString wdg_stlsheet;
    extern const QString rdbtn_stlsheet;
    extern const QString lbl_bstlsheet;
    extern const QString lbl_stlsheet;
    extern const QString chckbx_stlsheet;

    // MyMainWindow
    extern const QString mainwin_icon;

    // MyTutorial
    extern const QString ttrl_rule;
    extern const QString ttrl_howto;
    extern const QString ttrl_txt_stlsheet;

	// MyName
	extern const QString nm_txt_stlsheet;

	// MyPause
	extern const QString scrnsht_add;
    extern const QString ps_stlsheet;
}

#endif //SHOOTER_AP93UT_RESOURCES_H
