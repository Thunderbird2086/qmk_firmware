// Copyright 2021 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdio.h>
#include "quantum.h"

static char keylogs_str[5] = {"\n"};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', ' ', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', 'C', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX)
        || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)
        || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    }

    char name = '.';
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylogs
    for (uint8_t idx = sizeof(keylogs_str) - 1; idx > 0; --idx) {
        keylogs_str[idx] = keylogs_str[idx - 1];
    }

    keylogs_str[0] = name;
}

const char *read_keylogs(void) {
    return keylogs_str;
}
