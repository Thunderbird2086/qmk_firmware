// Copyright 2023 Thunderbird2086 (@Thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
#define EE_HANDS


#define VER_NEWLINE_WAIT 200 // in milliseconds

#if defined(OLED_ENABLE)
#   define SPLIT_LAYER_STATE_ENABLE
#   define SPLIT_LED_STATE_ENABLE
#   define SPLIT_MODS_ENABLE
#   define SPLIT_OLED_ENABLE
#endif

#if defined(MOUSE_ENABLE)
#   define MK_KINETIC_SPEED
#endif

#if defined(RGB_MATRIX_ENABLE) && !defined(QMK_MCU_RP2040)
#   undef RGB_DISABLE_WHEN_USB_SUSPENDED       // turn off effects when suspended

    //  Disable the animations you don't want/need.  You will need to disable a good number of these
    //  because they take up a lot of space.  Disable until you can successfully compile your firmware.
//#   undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#   undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#   undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#   undef ENABLE_RGB_MATRIX_BREATHING
#   undef ENABLE_RGB_MATRIX_BAND_SAT
#   undef ENABLE_RGB_MATRIX_BAND_VAL
#   undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#   undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#   undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#   undef ENABLE_RGB_MATRIX_CYCLE_ALL
#   undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#   undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
//#   undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#   undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#   undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#   undef ENABLE_RGB_MATRIX_DUAL_BEACON
//#   undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#   undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#   undef ENABLE_RGB_MATRIX_FLOWER_BLOOMING
#   undef ENABLE_RGB_MATRIX_RAINDROPS
#   undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
//#   undef ENABLE_RGB_MATRIX_HUE_BREATHING
#   undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#   undef ENABLE_RGB_MATRIX_HUE_WAVE
#   undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
//#   undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#   undef ENABLE_RGB_MATRIX_PIXEL_RAIN
//#   undef ENABLE_RGB_MATRIX_STARLIGHT
#   if defined(OLED_ENABLE)
#       undef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
#       undef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
#   endif
//#   undef ENABLE_RGB_MATRIX_RIVERFLOW

    //  These modes introduce additional logic that can increase firmware size.
#   if defined(OLED_ENABLE)
#       undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#       undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#   endif

    //  These modes introduce additional logic that can increase firmware size.
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#   if defined(OLED_ENABLE)
#       undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
//#      undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#       undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   endif
#   undef ENABLE_RGB_MATRIX_SPLASH
//#   undef ENABLE_RGB_MATRIX_MULTISPLASH
#   undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#   undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
