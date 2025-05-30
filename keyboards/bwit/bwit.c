// Copyright 2025 Allen Choi (@Thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#if defined(OS_DETECTION_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
  #include "os_detection.h"

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            rgb_matrix_set_color_all(RGB_WHITE);
            break;
        case OS_WINDOWS:
            rgb_matrix_set_color_all(RGB_BLUE);
            break;
        case OS_LINUX:
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        case OS_UNSURE:
            rgb_matrix_set_color_all(RGB_RED);
            break;
    }
    
    return true;
}
#endif
