// Copyright 2023 Thunderbird2086 (@Thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later


#include "quantum.h"
#include "includes/font_util.h"


#if defined(QWERTY_ENABLE)
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}
#endif // QWERTY_ENABLE


#if defined(SECRETS_ENABLE)
__attribute__((weak)) bool process_record_screts(uint16_t keycode, keyrecord_t *record) {
    return true;
} 
#endif // SECRETS_ENABLE


#if defined(OLED_ENABLE)
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}


__attribute__((weak)) void render_prompt(void) {
    oled_write_ln_P(PSTR("> _  "), false);
}


__attribute__((weak)) void render_keylogger_status(void) {
}


__attribute__((weak)) bool is_feature_layer(void) {
    return false;
}


__attribute__((weak)) bool should_oled_off(void) {
    return false;
}


__attribute__((weak)) bool process_record_oled(uint16_t keycode, keyrecord_t *record) {
    return true;
} 


void render_mod_status(void) {
#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
    if (is_feature_layer()) {
        oled_write_P(read_icon_rgb_status(
#                   if defined(RGBLIGHT_ENABLE)
                    rgblight_is_enabled()
#                   elif defined(RGB_MATRIX_ENABLE)
                    rgb_matrix_is_enabled()
#                   endif
                ), false);
        return;
    }
#endif

#if defined(NO_ACTION_ONESHOT)
    uint8_t modifiers = get_mods();
#else
    uint8_t modifiers = get_mods() | get_oneshot_mods();
#endif

    // 2x1 Ctrl, Alt, Shift, GUI, Caps
    oled_write_P(((modifiers & MOD_MASK_CTRL) ? read_icon_mod_ctrl() : PSTR("  ")), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(((modifiers & MOD_MASK_SHIFT) ? read_icon_mod_shift() : PSTR("  ")), false);

    oled_write_P(((modifiers & MOD_MASK_ALT) ? read_icon_mod_alt() : PSTR("  ")), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(((modifiers & MOD_MASK_GUI) ? read_icon_mod_gui() : PSTR("  ")), false);

    led_t led_state = host_keyboard_led_state();
    oled_write_P((led_state.caps_lock ? read_icon_caps_lock() : PSTR("  ")), false);
}


void render_layer(bool is_one_line) {
    uint8_t layer = 0;
    if (layer_state_is(_FUNCTION)) {
        layer = 1;
    } else if (layer_state_is(_CODE)) {
        layer = 2;
    } else if (is_feature_layer()) {
        layer = 3;
    }
    oled_write_P(read_layer(layer, is_one_line), false);
}


void render_status_secondary(void) {
    oled_write_ln("", false);
    oled_write_ln("", false);

    // 5x2 Keyboard, Controller logos
    oled_write_P(read_font_kb_split(), false);

    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);

    render_layer(true);

    oled_write_ln("", false);
    oled_write_ln("", false);
    oled_write_ln("", false);

    render_mod_status();
}


void render_status_main(void) {
    if (should_oled_off()) {
        return;
    }

    oled_write_ln("", false);
    oled_write_ln("", false);

    // 5x3 Logos
    oled_write_P(read_font_qmk_logo(), false);

    oled_write_ln("", false);
    oled_write_ln("", false);

    render_layer(false);

    oled_write_ln("", false);
    oled_write_ln("", false);

    render_prompt();

    oled_write_ln("", false);

    render_keylogger_status();
}


bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        render_status_main();
    } else {
        render_status_secondary();
    }
    return false;
}
#endif // OLED_ENABLE


bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    return process_record_user(keycode, record)
#       if defined(QWERTY_ENABLE)
        && process_record_keymap(keycode, record)
#       endif // QWERTY_ENABLE
#       if defined(SECRETS_ENABLE)
        && process_record_secrets(keycode, record)
#       endif // SECRETS_ENABLE
#       if defined(OLED_ENABLE)
        && process_record_oled(keycode, record)
#       endif // OLED_ENABLE
        ;
}
