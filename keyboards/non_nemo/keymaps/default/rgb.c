// Copyright 2025 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(0, RGB_RED);
    }
    return false;
}