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
#define SPLIT_USB_DETECT

#if defined(APPLE_FN_ENABLE)
/* USB Device descriptor parameter */
#   if defined(VENDOR_ID)
#      undef   VENDOR_ID
#      define  VENDOR_ID    0x05ac
#   endif

#   if defined(PRODUCT_ID)
#      undef   PRODUCT_ID
#      define  PRODUCT_ID   0x021E
#   endif

#   if defined(DEVICE_VER)
#      undef   DEVICE_VER
#      define  DEVICE_VER   0x0931
#   endif

#   if defined(MANUFACTURER)
#      undef   MANUFACTURER
#      define  MANUFACTURER "Apple Inc."
#   endif

#   if defined(PRODUCT)
#      undef   PRODUCT
#      define PRODUCT "Aluminum Mini Keyboard (ISO)"
#   endif
#endif

// #define RGB_LAYER_ENABLE

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

#if defined(RGB_MATRIX_ENABLE)
#    undef RGB_DISABLE_WHEN_USB_SUSPENDED       // turn off effects when suspended
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
        // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
//#   define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#   define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_ALPHAS_MODS
#   define RGB_MATRIX_HUE_STEP 32
#   define RGB_MATRIX_SAT_STEP 64
#   define RGB_MATRIX_VAL_STEP 64
#   define RGB_MATRIX_SPD_STEP 20
//#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_ALPHAS_MODS

    //  Disable the animations you don't want/need.  You will need to disable a good number of these
    //  because they take up a lot of space.  Disable until you can successfully compile your firmware.
#   define ENABLE_RGB_MATRIX_ALPHAS_MODS 	
#    undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN 	
#    undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT 	
#    undef ENABLE_RGB_MATRIX_BREATHING 	
#    undef ENABLE_RGB_MATRIX_BAND_SAT 	
#    undef ENABLE_RGB_MATRIX_BAND_VAL 	
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT 	
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL 	
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT 	
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL 	
#    undef ENABLE_RGB_MATRIX_CYCLE_ALL 	
#    undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT 	
#    undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN 	
#   define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON 	
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN 	
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL 	
#    undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL 	
#    undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL 	
#    undef ENABLE_RGB_MATRIX_DUAL_BEACON 	
#   define ENABLE_RGB_MATRIX_RAINBOW_BEACON 	
#    undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS 	
#    undef ENABLE_RGB_MATRIX_RAINDROPS 	
#    undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS 	
#   define ENABLE_RGB_MATRIX_HUE_BREATHING 	
#    undef ENABLE_RGB_MATRIX_HUE_PENDULUM 	
#    undef ENABLE_RGB_MATRIX_HUE_WAVE 	
#    undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL 	
#   define ENABLE_RGB_MATRIX_PIXEL_FLOW 	
#    undef ENABLE_RGB_MATRIX_PIXEL_RAIN 	

#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   if !defined(OLED_ENABLE)
#       define ENABLE_RGB_MATRIX_TYPING_HEATMAP 	
#   endif
#   define ENABLE_RGB_MATRIX_DIGITAL_RAIN 	

    //  These modes introduce additional logic that can increase firmware size.
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE 	
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE 	
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE 	
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE 	
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS 	
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS 	
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS 	
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS 	
#    undef ENABLE_RGB_MATRIX_SPLASH 	
#   define ENABLE_RGB_MATRIX_MULTISPLASH 	
#    undef ENABLE_RGB_MATRIX_SOLID_SPLASH 	
#    undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH 	
#endif
