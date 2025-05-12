// Copyright 2025 Thunderbird2086 (@Thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#define XIAO_RGB_POWER_PIN  GP11

static inline void led_num(const bool on) {
#ifdef LED_NUM_LOCK_PIN
    gpio_set_pin_output(LED_NUM_LOCK_PIN);
    gpio_write_pin(LED_NUM_LOCK_PIN, !on);
#endif
}

static inline void led_scroll(const bool on) {
#ifdef LED_SCROLL_LOCK_PIN
    gpio_set_pin_output(LED_SCROLL_LOCK_PIN);
    gpio_write_pin(LED_SCROLL_LOCK_PIN, !on);
#endif
}

static inline void led_caps(const bool on) {
#ifdef LED_CAPS_LOCK_PIN
    gpio_set_pin_output(LED_CAPS_LOCK_PIN);
    gpio_write_pin(LED_CAPS_LOCK_PIN, !on);
#endif
}
