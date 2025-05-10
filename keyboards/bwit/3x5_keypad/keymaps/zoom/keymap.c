// Copyright 2025 Allen Choi (@Thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keycodes.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _ZOOM_M,
  _ZOOM_W,
  _ADJUST,
  _LAYER0,
  _LAYER1,
  _LAYER2,
  _LAYER3,
};

//  macOS       | Windows     |  Description
//  ------------+-------------+------------------------------------
//  SCMD(KC_A)  | LALT(KC_A)  |  Audio On/Off
//  SCMD(KC_D)  |             |  Switch to Dual Monitors
//  SCMD(KC_F)  | LALT(KC_F)  |  Enter/Exit Full Screen Mode
//  SCMD(KC_H)  | LALT(KC_H)  |  Show/Hide In-meeting Chat Panel
//  SCMD(KC_Y)  | LATL(KC_Y)  |  Raise/Lower Hand
//  SCMD(KC_N)  | LALT(KC_N)  |  Switch Camera
//  SCMD(KC_S)  | LALT(KC_S)  |  Start/Stop Screen Sharing
//  SCMD(KC_T)  | LALT(KC_T)  |  Pause Screen Sharing
//  SCMD(KC_V)  | LALT(KC_V)  |  Video On/Off
//  SCMD(KC_Y)  | LATL(KC_Y)  |  Raise/Lower Hand
//  SCMD(KC_W)  |             |  Switch to Speaker/Gallery View
//              | LALT(KC_F1) |  Switch to Speaker View
//              | LALT(KC_F2) |  Switch to Gallery View
//  SCMD(KC_M)  |             |  Switch to Minimal Window
//              | C(A(S(KC_H) |  Show/Hide Meeting Controls
//
//  LCMD(KC_L)  | LALT(KC_L)  |  Switch to Portrait/Landscape View
//  LCMD(KC_U)  | LALT(KC_U)  |  Show/Hide Participants Panel
//  LCMD(KC_W)  | LALT(KC_F4) |  Close Current Window

#define ZOOM_M DF(_ZOOM_M)
#define ZOOM_W DF(_ZOOM_W)
#define ______ KC_NO

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ZOOM_M] = LAYOUT_top(
    KC_ESC      , LCMD(KC_U) , SCMD(KC_W)  , SCMD(KC_D) , KC_ENT     ,
    TT(_ADJUST) , SCMD(KC_H) , SCMD(KC_N)  , SCMD(KC_T) , SCMD(KC_M) ,
    LALT(KC_Y)  , SCMD(KC_A) , SCMD(KC_V)  , SCMD(KC_S) , LCMD(KC_W)
    ),

    [_ZOOM_W] = LAYOUT_top(
    KC_ESC      , LALT(KC_U) , LALT(KC_F1) , LALT(KC_F2), KC_ENT       ,
    TT(_ADJUST) , LALT(KC_H) , LALT(KC_N)  , LALT(KC_T) , C(A(S(KC_H))),
    LALT(KC_Y)  , LALT(KC_A) , LALT(KC_V)  , LALT(KC_S) , LALT(KC_F4)
    ),

    [_ADJUST] = LAYOUT_top(
    EE_CLR      , ZOOM_W     , RGB_SAI     , RGB_VAI    , RGB_MOD    ,
    ______      , ZOOM_M     , RGB_SAD     , RGB_VAD    , RGB_RMOD   ,
    QK_BOOT     , ______     , RGB_HUD     , RGB_HUI    , RGB_TOG
    ),
};
// clang-format on
