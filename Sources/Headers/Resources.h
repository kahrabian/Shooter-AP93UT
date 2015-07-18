//
// Created by kahrabian on 7/9/15.
//

#ifndef SHOOTER_AP93UT_RESOURCES_H
#define SHOOTER_AP93UT_RESOURCES_H

#include <QString>
#include <QSize>
#include <QVector>
#include <QMediaPlaylist>
#include <QRect>
#include "SettingData.h"

namespace MyRes {
    // Project properties
    const int frm_dly = 30;
    const int gm_drtn = 120000;
    const int vw_mvmnt = 1;
    const int shp_mvmnt = 5;
    const int lsr_cnt = 2;
    const int mgc_cnt = 4;
    const int env_cnt = 16;
    const int shp_cnt = 5;
    const int aln_bss_cnt = 5;
    const int aln_nrml_cnt = 11;
    const int astrd_frcnt = 16;
    const int astrd_typcnt = 7;

    // Contents size
    extern const QSize img_init_size;
    extern const QSize app_size;
    extern const QRect scn_rct;
    extern const QSize tl_size;

    // Resource location addresses
    extern const QString shp_adds[shp_cnt];
    extern const QString shp_shld_add;
    extern const QString aln_bss_adds[aln_bss_cnt];
    extern const QString aln_nrml_adds[aln_nrml_cnt];
    extern const QString env_adds[env_cnt];
    extern const QString astrd_adds[astrd_typcnt][astrd_frcnt];
    extern const QString str_add;
    extern const QString shld_add;
    extern const QString hrt_add;
    extern const QString lsr_add[lsr_cnt];
    extern const QString mgc_add[mgc_cnt];
    extern const QString stng_add;
    extern const QString mainmuse_add;
    extern const QString logo_add;
    extern const QString background_add;
    extern const QString scrnsht_add;
    extern const QString mainwin_icon_add;

    // Stylesheets
    extern const QString mainwdg_stlsheet;
    extern const QString wdg_stlsheet;
    extern const QString rdbtn_stlsheet;
    extern const QString lbl_bstlsheet;
    extern const QString lbl_stlsheet;
    extern const QString chckbx_stlsheet;
    extern const QString ttrl_txt_stlsheet;
    extern const QString nm_txt_stlsheet;
    extern const QString ps_stlsheet;

    // MyTutorial
    extern const QString ttrl_rule;
    extern const QString ttrl_howto;
}

#endif //SHOOTER_AP93UT_RESOURCES_H
