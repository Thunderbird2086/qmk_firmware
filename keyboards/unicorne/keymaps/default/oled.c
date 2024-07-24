// Copyright 2021 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keycodes.h"

#include "includes/font_util.h"
#include "includes/keylogger.h"

bool is_feature_layer(void) {
    return layer_state_is(_MEDIA) || layer_state_is(_NAV);
}


static uint32_t key_timer  = 0;
static bool is_key_processed = true;
bool process_record_oled(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        key_timer = timer_read32();
        is_key_processed = true;

        set_keylog(keycode, record);
    }

    return true;
}


bool should_oled_off(void) {
    if (is_key_processed && (timer_elapsed32(key_timer) < OLED_TIMEOUT)) {
        return false;
    }

    if (is_key_processed) {
        oled_off();
        is_key_processed = false;
    }

    return true;
}


void render_prompt(void) {
    bool blink = (timer_read32() % 1000) < 500;

    if (layer_state_is(_FUNCTION)) {
        oled_write_ln_P(blink ? PSTR("> ft_") : PSTR("> ft "), false);
    } else if (layer_state_is(_CODE)) {
        oled_write_ln_P(blink ? PSTR("> co_") : PSTR("> co "), false);
    } else if (layer_state_is(_NAV)) {
        oled_write_ln_P(blink ? PSTR("> na_") : PSTR("> na "), false);
    } else if (layer_state_is(_MEDIA)) {
        oled_write_ln_P(blink ? PSTR("> me_") : PSTR("> me "), false);
    } else {
        oled_write_ln_P(blink ? PSTR("> _  ") : PSTR(">    "), false);
    }
}

void render_keylogger_status(void) {
    oled_write(read_keylogs(), false);
}
