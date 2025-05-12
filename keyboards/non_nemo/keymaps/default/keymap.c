// Copyright 2021 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keycodes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐                ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ F │ P │ B │                │ J │ L │ U │ Y │ ' │
      * ├───┼───┼───┼───┼───┤                ├───┼───┼───┼───┼───┤
      * │ A │ R │ S │ T │ G │                │ M │ N │ E │ I │ O │
      * ├───┼───┼───┼───┼───┤                ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ D │ V │                │ K │ H │ , │ . │ / │
      * └───┴───┴───┴───┴───┘                └───┴───┴───┴───┴───┘
      *                ┌───┬───┬───┐   ┌───┬───┬───┐
      *                │ESC│TAB│Spc│   │ESC│TAB│Spc│
      *                └───┴───┴───┘   └───┴───┴───┘
      */
    [_COLEMAK] = LAYOUT_split_3x5_3(
        KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,                                 KC_J,      KC_L,      KC_U,      KC_Y,      KC_QUOT,
        LOPT_A,    LSFT_R,    LCTL_S,    M_LCMD_T,  KC_G,                                 KC_M,      RCMD_N,    RCTL_E,    RSFT_I,    ROPT_O,
        KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,                                 KC_K,      KC_H,      KC_COMM,   KC_DOT,    KC_SLSH,
                                         NAV_ESC,   FCT_TAB,   COD_SPC,        COD_ENT,   FCT_BSPC,  MED_DEL
    ),
#if defined(QWERTY_ENABLE)
     /*
      * ┌───┬───┬───┬───┬───┐                ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │                │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤                ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │                │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤                ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │                │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘                └───┴───┴───┴───┴───┘
      *                ┌───┬───┬───┐   ┌───┬───┬───┐
      *                │ESC│TAB│Spc│   │ESC│TAB│Spc│
      *                └───┴───┴───┘   └───┴───┴───┘
      */
    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                 KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,
        LOPT_A,    LSFT_S,    LCTL_D,    M_LCMD_F,  KC_G,                                 KC_H,      RCMD_J,    RCTL_K,    RSFT_L,    ROPT_SCLN,
        KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,                                 KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,
                                         NAV_ESC,   FCT_TAB,   COD_SPC,        COD_ENT,   FCT_BSPC,  MED_DEL
    ),
#endif
     /*
      * ┌───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┐
      * │ 1 │ 2 │ 3 │ 4 │ 5 │               │ 6 │ 7 │ 8 │ 9 │ 0 │
      * ├───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┤
      * │ ` │SFT│CTL│OPT│   │               │   │   │ ; │ - │ = │
      * ├───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┤
      * │   │   │   │   │CAP│               │   │ ' │ [ │ ] │ \ │
      * └───┴───┴───┴───┴───┘               └───┴───┴───┴───┴───┘
      *               ┌───┬───┬───┐   ┌───┬───┬───┐
      *               │ESC│TAB│Spc│   │ESC│TAB│Spc│
      *               └───┴───┴───┘   └───┴───┴───┘
      */
    [_CODE] = LAYOUT_split_3x5_3(
        KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                 KC_6,      KC_7,      KC_8,      KC_9,      KC_0,
        LOPT_GRV,  KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_NO,                                KC_NO,     KC_RCMD,   RCTL_SCLN, RSFT_MINS, ROPT_EQL,
        KC_NO,     KC_N,      KC_NO,     KC_NO,     KC_CAPS,                              KC_NO,     KC_QUOT,   KC_LBRC,   KC_RBRC,   KC_BSLS,
                                         NAV_ESC,   FCT_TAB,   COD_SPC,        COD_ENT,   FCT_BSPC,  MED_DEL
    ),
     /*
      * ┌───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┐
      * │F1 │F2 │F3 │F4 │F5 │               │F6 │F7 │F8 │F9 │F10│
      * ├───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┤
      * │OPT│SFT│CTL│CMD│F12│               │F11│CMD│CTL│SFT│OPT│
      * ├───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┤
      * │   │   │   │   │CAP│               │   │   │   │   │   │
      * └───┴───┴───┴───┴───┘               └───┴───┴───┴───┴───┘
      *               ┌───┬───┬───┐   ┌───┬───┬───┐
      *               │ESC│TAB│Spc│   │ESC│TAB│Spc│
      *               └───┴───┴───┘   └───┴───┴───┘
      */
    [_FUNCTION] = LAYOUT_split_3x5_3(
        KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                                KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,
        KC_LOPT,   KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_F12,                               KC_F11,    KC_RCMD,   KC_RCTL,   KC_RSFT,   KC_ROPT,
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_CAPS,                              KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
                                         NAV_ESC,   FCT_TAB,   COD_SPC,        COD_ENT,   FCT_BSPC,  MED_DEL
    ),
     /*
      * ┌───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┐
      * │Cha│Who│Vie│Dua│   │               │   │Mut│Cam│Han│Sha│
      * ├───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┤
      * │OPT│SFT│CTL│CMD│   │               │Ins│Lef│UP │Rig│PU │
      * ├───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │               │   │Hom│Dn │End│PD │
      * └───┴───┴───┴───┴───┘               └───┴───┴───┴───┴───┘
      *               ┌───┬───┬───┐   ┌───┬───┬───┐
      *               │ESC│TAB│Spc│   │ESC│TAB│Spc│
      *               └───┴───┴───┘   └───┴───┴───┘
      */
    [_NAV] = LAYOUT_split_3x5_3(
        Z_CHAT,    Z_WHOS,    Z_VIEW,    Z_DUAL,    KC_NO,                                KC_NO,     Z_AUDIO,   Z_VIDEO,   Z_HAND,    Z_SHARE,
        KC_LOPT,   KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_NO,                                KC_INS,    KC_LEFT,   KC_UP,     KC_RIGHT,  KC_PGUP,
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                KC_NO,     KC_HOME,   KC_DOWN,   KC_END,    KC_PGDN,
                                         NAV_ESC,   FCT_TAB,   COD_SPC,        COD_ENT,   FCT_BSPC,  MED_DEL
    ),
     /*
      * ┌───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┐
      * │PWR│SLP│WAK│   │   │               │R.T│R.M│LOK│R.R│   │
      * ├───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┤
      * │Br+│RWD│PLY│Vo+│W.B│               │   │Va+│Hu+│Sa+│Sp+│
      * ├───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┤
      * │Br-│FWD│Mut│Vo-│W.F│               │   │Va-│Hu-│Sa-│Sp-│
      * └───┴───┴───┴───┴───┘               └───┴───┴───┴───┴───┘
      *               ┌───┬───┬───┐   ┌───┬───┬───┐
      *               │ESC│TAB│Spc│   │ESC│TAB│Spc│
      *               └───┴───┴───┘   └───┴───┴───┘
      */
    [_MEDIA] = LAYOUT_split_3x5_3(
        KC_PWR,    KC_SLEP,   KC_WAKE,   KC_NO,     KC_NO,                                RGB_TOG,   RGB_MOD,   K_LOCK,    EE_CLR,    KC_NO,
        KC_BRIU,   KC_MPRV,   KC_MPLY,   KC_VOLU,   K_BACK,                               KC_NO,     RGB_VAI,   RGB_HUI,   RGB_SAI,   RGB_SPI,
        KC_BRID,   KC_MNXT,   KC_MUTE,   KC_VOLD,   K_FWRD,                               KC_NO,     RGB_VAD,   RGB_HUD,   RGB_SAD,   RGB_SPD,
                                         MOU_ESC,   FCT_TAB,   ADJ_SPC,        COD_ENT,   FCT_BSPC,  MED_DEL
    ),
     /*
      * ┌───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┐
      * │   │   │   │   │   │               │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┤
      * │OPT│SFT│CTL│CMD│QWT│               │   │ML │MU │MR │WU │
      * ├───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┤
      * │   │   │   │   │CLM│               │   │WL │MD │WR │WD │
      * └───┴───┴───┴───┴───┘               └───┴───┴───┴───┴───┘
      *               ┌───┬───┬───┐   ┌───┬───┬───┐
      *               │ESC│TAB│Spc│   │MB1│MB2│MB3│
      *               └───┴───┴───┘   └───┴───┴───┘
      */
    [_MOUSE] = LAYOUT_split_3x5_3(
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                VRSN,      KC_ACL0,   KC_ACL1,   KC_ACL2,   KC_NO,
        KC_LOPT,   KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_NO,                                KC_NO,     KC_MS_L,   KC_MS_U,   KC_MS_R,   KC_WH_U,
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                KC_NO,     KC_WH_L,   KC_MS_D,   KC_WH_R,   KC_WH_D,
                                         MOU_ESC,   FCT_TAB,   COD_SPC,        KC_BTN1,   KC_BTN2,   KC_BTN3
    ),
     /*
      * ┌───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┐
      * │   │   │   │   │   │               │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┤
      * │OPT│SFT│CTL│CMD│   │               │QWT│CMD│CTL│SFT│OPT│
      * ├───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │               │CLM│WL │MD │WR │WD │
      * └───┴───┴───┴───┴───┘               └───┴───┴───┴───┴───┘
      *               ┌───┬───┬───┐   ┌───┬───┬───┐
      *               │ESC│TAB│Spc│   │MB1│MB2│MB3│
      *               └───┴───┴───┘   └───┴───┴───┘
      */
    [_ADJUST] = LAYOUT_split_3x5_3(
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                KC_NO,     KC_NO,     KC_NO,     KC_NO,     QK_BOOT,
        KC_LOPT,   KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_NO,                                QWERTY,    KC_RCMD,   KC_RCTL,   KC_RSFT,   KC_ROPT,
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                COLEMAK,   KC_NO,     KC_NO,     KC_NO,     KC_NO,  
                                         MOU_ESC,   FCT_TAB,   ADJ_SPC,        COD_SPC,   FCT_BSPC,  MED_DEL
    )
};