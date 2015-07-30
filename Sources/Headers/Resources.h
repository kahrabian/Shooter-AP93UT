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
#include <QFont>
#include <Sources/Headers/SettingData.h>

namespace MyRes {
    // Project properties
    const int frm_dly = 32;
    const int gm_drtn = 120000;
    const int vw_mvmnt = 3;
    const int shp_mvmnt = 5;
    const int lsr_mvmnt = 40;
    const int lsr_cnt = 2;
    const int mgc_cnt = 4;
    const int env_cnt = 16;
    const int shp_cnt = 5;
    const int aln_bss_cnt = 5;
    const int aln_nrml_cnt = 11;
    const int expln_frcnt = 90;
    const int astrd_frcnt = 16;
    const int astrd_typcnt = 7;
    const int dff_cnt = 4;

    // Game properties
    const int fst_vlc = 4;
    const int shp_lf = 5;
    const int spcl_tm = 5000;
    const int lf_tm = 5000;
    const int aln_lsrdly = 500;
    const int shp_lsrdly = 400;
    const int stg_cnt = 3;
    const int rtn_max = 30;
    const int rtn_stp = 3;
    const int lsr_rtn_max = 30;
    const int lsr_rtn_stp = 3;
    const int x_offset = 10;
    const int y_offset = 15;
    const int expln_astrd_crrctn = 30;
    const int expln_aln_bg_crrctn = 30;
    const int expln_aln_smll_crrctn = 15;
    const int expln_lsr_crrctn = 7;
    const int txtitem_x_crrctn = 10;
    const int txtitem_y_crrctn = 5;
    extern const QSize stg_size;
    extern const QSize lf_size;
    extern const QSize lsr_size;
    extern const QSize str_size;
    extern const QSize mgc_size;
    extern const QSize shld_size;
    extern const QSize astrd_size;
    extern const QSize aln_bgsize;
    extern const QSize aln_smllsize;
    extern const QSize shp_size;
    extern const QSize shp_shld_size;
    extern const QSize expln_aln_smll_size;
    extern const QSize expln_aln_bg_size;
    extern const QSize expln_lsr_size;
    extern const QSize expln_shp_size;
    extern const QSize expln_astrd_size;
    extern const QFont txt_font;

    // Game stages properties
    const int bss_offset = 120;
    const int stg_str = 30;
    const int stg_lf = 3;
    const int stg_mgc[dff_cnt] = {5, 4, 3, 2};
    const int stg_shld[dff_cnt] = {5, 4, 3, 2};
    const int stg_astrd[stg_cnt][dff_cnt] = {{20, 30, 40, 50},
                                             {0,  0,  0,  0},
                                             {10, 20, 30, 40}};
    const int stg_aln_bg[stg_cnt][dff_cnt] = {{0,  0,  0,  0},
                                              {20, 30, 40, 50},
                                              {10, 15, 25, 35}};
    const int stg_aln_smll[stg_cnt][dff_cnt] = {{0,  0,  0,  0},
                                                {5,  15, 25, 35},
                                                {10, 15, 25, 35}};

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
    extern const QString expln_adds[expln_frcnt];
    extern const QString astrd_adds[astrd_typcnt][astrd_frcnt];
    extern const QString str_add;
    extern const QString shld_add;
    extern const QString lf_add;
    extern const QString lsr_add[lsr_cnt];
    extern const QString mgc_add[mgc_cnt];
    extern const QString stng_add;
    extern const QString mnmuse_add;
    extern const QString gmmuse_add;
    extern const QString psmuse_add;
    extern const QString endmuse_add;
    extern const QString logo_add;
    extern const QString background_add;
    extern const QString scrnsht_add;
    extern const QString mainwin_icon_add;
    extern const QString stg_add[stg_cnt];
    extern const QString sf_expln_aln_bg_add;
    extern const QString sf_expln_aln_smll_add;
    extern const QString sf_expln_astrd_add;
    extern const QString sf_expln_lsr_add;
    extern const QString sf_expln_shp_add;
    extern const QString sf_expln_shpshld_add;
    extern const QString sf_lf_add;
    extern const QString sf_aln_lsr_add;
    extern const QString sf_shp_lsr_add;
    extern const QString sf_mgc_add;
    extern const QString sf_shld_add;
    extern const QString sf_str_add;
    extern const QString sf_shp_shp_add;

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
