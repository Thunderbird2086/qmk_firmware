// Copyright 2021 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "includes/keycodes.h"

enum custom_keycodes {
    // Layer Macros
    COLEMAK = QK_USER,
    QWERTY,
    FUNCTION,
    CODE,
    ADJUST,
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
    _QWERTY,
    _FUNCTION,
    _CODE,
    _ADJUST,
#if defined(SECRETS_ENABLE)
    _SECRET,
#endif
};

// Layer Keys
#define FCT_BSP     LT(_FUNCTION, KC_BSPC)
#define FCT_DEL     LT(_FUNCTION, KC_DEL)

#define FCT_ENT     LT(_FUNCTION, KC_ENT)
#define RAI_ENT     LT(_CODE    , KC_ENT)

#define FCT_EQL     LT(_FUNCTION, KC_EQL)
#define RAI_EQL     LT(_CODE    , KC_EQL)

#define FCT_SPC     LT(_FUNCTION, KC_SPC)
#define RAI_SPC     LT(_CODE    , KC_SPC)

#define FCT_TAB     LT(_FUNCTION, KC_TAB)

#define ADJ_EQL     LT(_ADJUST, KC_EQL)
#define ADJ_GRV     LT(_ADJUST, KC_GRV)
