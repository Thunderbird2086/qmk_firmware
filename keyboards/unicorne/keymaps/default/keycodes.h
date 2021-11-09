// Copyright 2023 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "includes/keycodes.h"

enum custom_keycodes {
    // Layer Macros
    COLEMAK = QK_USER,
#if defined(QWERTY_ENABLED)
    QWERTY,
#   endif
    CODE,
    FUNCTION,
    NAV,
    MEDIA,
    MOUSE,
#   if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    RGBRST,
#   endif
    VRSN,
#if defined(SECRETS_ENABLE)
    // Secret Macros
    M_XXX1,
    M_XXX2,
    M_XXX3,
    M_XXX4,
    M_XXX5,
#endif
};


enum layers {
    _COLEMAK,
#if defined(QWERTY_ENABLED)
    _QWERTY,
#   endif
    _CODE,
    _FUNCTION,
    _NAV,
    _MEDIA,
    _MOUSE,
#if defined(SECRETS_ENABLE)
    _SECRET,
#endif
};


// Layer Keys
#define FCT_TAB     LT(_FUNCTION, KC_TAB)
#define FCT_BSPC    LT(_FUNCTION, KC_BSPC)

#define COD_ENT     LT(_CODE    , KC_ENT)
#define COD_SPC     LT(_CODE    , KC_SPC)

#define NAV_ESC     LT(_NAV     , KC_ESC)
#define MED_DEL     LT(_MEDIA   , KC_DEL)

#define MOU_ESC     LT(_MOUSE   , KC_ESC)
