// Copyright 2021 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "includes/keycodes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ ' │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤Del│
      *           └───┤TAB├───┐   ┌───┤Bsp├───┘
      *               └───┤Spc│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [_COLEMAK] = LAYOUT_split_3x5_3(
        KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,                                 KC_J,      KC_L,      KC_U,      KC_Y,      KC_QUOT,
        LOPT_A,    LSFT_R,    LCTL_S,    M_LCMD_T,  KC_G,                                 KC_M,      RCMD_N,    RCTL_E,    RSFT_I,    ROPT_O,
        KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,                                 KC_K,      KC_H,      KC_COMM,   KC_DOT,    KC_SLSH,
                                         NAV_ESC,   FCT_TAB,   COD_SPC,        COD_ENT,   FCT_BSPC,  MED_DEL
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ ` │SFT│CTL│OPT│   │       │   │   │ ; │ - │ = │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │CAP│       │   │   │ [ │ ] │ \ │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤Del│
      *           └───┤TAB├───┐   ┌───┤Bsp├───┘
      *               └───┤Spc│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [_CODE] = LAYOUT_split_3x5_3(
        KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                 KC_6,      KC_7,      KC_8,      KC_9,      KC_0,
        LOPT_GRV,  KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_NO,                                KC_NO,     KC_RCMD,   RCTL_SCLN, RSFT_MINS, ROPT_EQL,
        KC_NO,     KC_N,      KC_NO,     KC_NO,     KC_CAPS,                              KC_NO,     KC_NO,     KC_LBRC,   KC_RBRC,   KC_BSLS,
                                         NAV_ESC,   FCT_TAB,   COD_SPC,        COD_ENT,   FCT_BSPC,  MED_DEL
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │F1 │F2 │F3 │F4 │F5 │       │F6 │F7 │F8 │F9 │F10│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │OPT│SFT│CTL│CMD│F12│       │F11│CMD│CTL│SFT│OPT│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │CAP│       │   │   │   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤Del│
      *           └───┤TAB├───┐   ┌───┤Bsp├───┘
      *               └───┤Spc│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [_FUNCTION] = LAYOUT_split_3x5_3(
        KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                                KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,
        KC_LOPT,   KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_F12,                               KC_F11,    KC_RCMD,   KC_RCTL,   KC_RSFT,   KC_ROPT,
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_CAPS,                              KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
                                         NAV_ESC,   FCT_TAB,   COD_SPC,        COD_ENT,   FCT_BSPC,  MED_DEL
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │   │   │   │   │   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │OPT│SFT│CTL│CMD│   │       │Ins│Lef│UP │Rig│PU │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │   │Hom│Dn │End│PD │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤Del│
      *           └───┤TAB├───┐   ┌───┤Bsp├───┘
      *               └───┤Spc│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [_NAV] = LAYOUT_split_3x5_3(
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        KC_LOPT,   KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_NO,                                KC_INS,    KC_LEFT,   KC_UP,     KC_RIGHT,  KC_PGUP,
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                KC_NO,     KC_HOME,   KC_DOWN,   KC_END,    KC_PGDN,
                                         NAV_ESC,   FCT_TAB,   COD_SPC,        COD_ENT,   FCT_BSPC,  MED_DEL
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │PWR│SLP│WAK│   │   │       │R.T│R.M│LOK│R.R│Res│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Br+│RWD│PLY│Vo+│W.B│       │   │Va+│Hu+│Sa+│Sp+│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │Br-│FWD│Mut│Vo-│W.F│       │   │Va-│Hu-│Ss-│Sp-│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤   │
      *           └───┤TAB├───┐   ┌───┤Bsp├───┘
      *               └───┤Spc│   │Ent├───┘
      *                   └───┘   └───┘
      */
    [_MEDIA] = LAYOUT_split_3x5_3(
        KC_PWR,    KC_SLEP,   KC_WAKE,   KC_NO,     KC_NO,                                RGB_TOG,   RGB_MOD,   K_LOCK,    EE_CLR,    QK_BOOT,
        KC_BRIU,   KC_MPRV,   KC_MPLY,   KC_VOLU,   K_BACK,                               KC_NO,     RGB_VAI,   RGB_HUI,   RGB_SAI,   RGB_SPI,
        KC_BRID,   KC_MNXT,   KC_MUTE,   KC_VOLD,   K_FWRD,                               KC_NO,     RGB_VAD,   RGB_HUD,   RGB_SAD,   RGB_SPD,
                                         MOU_ESC,   FCT_TAB,   COD_SPC,        COD_ENT,   FCT_BSPC,  MED_DEL
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │   │   │   │   │   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │OPT│SFT│CTL│CMD│   │       │   │ML │MU │MR │WU │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │   │WL │MD │WR │WD │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤MB3│
      *           └───┤TAB├───┐   ┌───┤MB2├───┘
      *               └───┤Spc│   │MB1├───┘
      *                   └───┘   └───┘
      */
    [_MOUSE] = LAYOUT_split_3x5_3(
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                KC_NO,     KC_ACL0,   KC_ACL1,   KC_ACL2,   KC_NO,
        KC_LOPT,   KC_LSFT,   KC_LCTL,   KC_LCMD,   KC_NO,                                KC_NO,     KC_MS_L,   KC_MS_U,   KC_MS_R,   KC_WH_U,
        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                                KC_NO,     KC_WH_L,   KC_MS_D,   KC_WH_R,   KC_WH_D,
                                         MOU_ESC,   FCT_TAB,   COD_SPC,        KC_BTN1,   KC_BTN2,   KC_BTN3
    )
};
