// Copyright 2021 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

// 5x3 Logos
const char *read_font_qmk_logo(void) {
    static const char PROGMEM font_qmk_logo[16] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4,
        0
    };

    return font_qmk_logo;
}

// 5x2 Keyboard, Controller logos
const char *read_font_kb_split(void) {
    static const char PROGMEM font_kb_split[11] = {
        0xb5, 0xb6, 0xb7, 0xb8, 0xb9,
        0xd5, 0xd6, 0xd7, 0xd8, 0xd9,
        0
    };

    return font_kb_split;
};
