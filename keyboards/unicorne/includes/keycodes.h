// Copyright 2023 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Shortcut Keys
#define K_BACK      LCMD(KC_LBRC)           // browser back
#define K_FWRD      LCMD(KC_RBRC)           // browser forward
#define K_LOCK      LCMD(LCTL(KC_Q))        // Lock screen
#define K_CSCN      LCMD(LCTL(LSFT(KC_4)))  // Copy a portion of the screen to the clipboard
#define K_MDSH      LSFT(LOPT(KC_MINS))

// Mod-Tap Keys
#define LSFT_R      MT(MOD_LSFT, KC_R)
#define LSFT_S      MT(MOD_LSFT, KC_S)
#define LSFT_Z      MT(MOD_LSFT, KC_Z)
#define RSFT_I      MT(MOD_RSFT, KC_I)
#define RSFT_L      MT(MOD_RSFT, KC_L)
#define RSFT_MINS   MT(MOD_RSFT, KC_MINS)
#define RSFT_SLSH   MT(MOD_RSFT, KC_SLSH)

#define LCTL_A      MT(MOD_LCTL, KC_A)
#define LCTL_D      MT(MOD_LCTL, KC_D)
#define LCTL_S      MT(MOD_LCTL, KC_S)
#define RCTL_E      MT(MOD_RCTL, KC_E)
#define RCTL_K      MT(MOD_RCTL, KC_K)
#define RCTL_O      MT(MOD_RCTL, KC_O)
#define RCTL_LBRC   MT(MOD_RCTL, KC_LBRC)
#define RCTL_QUOT   MT(MOD_RCTL, KC_QUOT)
#define RCTL_SCLN   MT(MOD_RCTL, KC_SCLN)

#define LOPT_A      MT(MOD_LALT, KC_A)
#define LOPT_F      MT(MOD_LALT, KC_F)
#define M_LOPT_T    MT(MOD_LALT, KC_T)
#define LOPT_GRV    MT(MOD_LALT, KC_GRV)
#define ROPT_O      MT(MOD_RALT, KC_O)
#define ROPT_SCLN   MT(MOD_RALT, KC_SCLN)
#define ROPT_EQL    MT(MOD_RALT, KC_EQL)

#define M_LCMD_F    MT(MOD_LGUI, KC_F)
#define M_LCMD_T    MT(MOD_LGUI, KC_T)
#define RCMD_N      MT(MOD_RGUI, KC_N)
#define RCMD_J      MT(MOD_RGUI, KC_J)

// zoom
#define Z_CHAT      LSFT(LCMD(KC_H)) 
#define Z_WHOS      LCMD(KC_U)
#define Z_VIEW      LSFT(LCMD(KC_W)) 
#define Z_DUAL      LSFT(LCMD(KC_D))

#define Z_AUDIO     LSFT(LCMD(KC_A)) 
#define Z_VIDEO     LSFT(LCMD(KC_V)) 
#define Z_HAND      LOPT(KC_Y) 
#define Z_SHARE     LSFT(LCMD(KC_S)) 
