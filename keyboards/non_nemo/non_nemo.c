// Copyright 2025 Thunderbird2086 (@Thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"


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


bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    return process_record_user(keycode, record)
#       if defined(QWERTY_ENABLE)
        && process_record_keymap(keycode, record)
#       endif // QWERTY_ENABLE
#       if defined(SECRETS_ENABLE)
        && process_record_secrets(keycode, record)
#       endif // SECRETS_ENABLE
        ;
}
