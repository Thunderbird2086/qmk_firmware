// Copyright 2025 Thunderbird2086 (@Thunderbird2086)
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

#define VER_NEWLINE_WAIT 200 // in milliseconds

#if defined(MOUSE_ENABLE)
#   define MK_KINETIC_SPEED
#endif

