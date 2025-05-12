// Copyright 2025 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "version.h"

#if defined(SECRETS_ENABLE)
#   include "secrets.h"

bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_XXX1...M_XXX5:
            if (record->event.pressed) {
                send_string(secret[keycode - M_XXX1]);
            }
            break;
    }
    return true;
}
#endif


#if defined(QWERTY_ENABLE)
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case COLEMAK:
                set_single_persistent_default_layer(_COLEMAK);
                break;
            case QWERTY:
                set_single_persistent_default_layer(_QWERTY);
                break;
        }
    }

    return true;
}
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                send_string(
                    "# qmk " QMK_VERSION "\n" SS_DELAY(VER_NEWLINE_WAIT)
                    "# " QMK_KEYBOARD "/" QMK_KEYMAP "\n" SS_DELAY(VER_NEWLINE_WAIT)
                    "# built on: " QMK_BUILDDATE "\n");
                break;
            case RGB_TOG:
                gpio_toggle_pin(XIAO_RGB_POWER_PIN);
                break;
        }
    }

    return true;
}