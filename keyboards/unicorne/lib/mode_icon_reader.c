// Copyright 2021 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdio.h>
#include "quantum.h"

// 2x1 Ctrl, Alt, Shift, GUI, Caps

const char *read_icon_mod_ctrl(void) {
    static const char PROGMEM icon_ctrl[3] = {0x91, 0x92, 0};
    return icon_ctrl;
};

const char *read_icon_mod_alt(void) {
    static const char PROGMEM icon_alt[3] = {0xb1, 0xb2, 0};
    return icon_alt;
};

const char *read_icon_mod_shift(void) {
    static const char PROGMEM icon_shift[3] = {0xb3, 0xb4, 0};
    return icon_shift;
};

const char *read_icon_mod_gui(void) {
    static const char PROGMEM icon_gui[3] = {0x93, 0x94, 0};
    return icon_gui;
};

const char *read_icon_caps_lock(void) {
    static const char PROGMEM icon_caps[3] = {0x9f, 0xbf, 0};
    return icon_caps;
};

#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
const char *read_icon_rgb_status(bool on) {
    static const char PROGMEM icon_rgb_off[3] = {0xd1, 0xd2, 0};
    static const char PROGMEM icon_rgb_on[3]  = {0xd3, 0xd4, 0};

    return (on ? icon_rgb_on : icon_rgb_off);
};
#endif
