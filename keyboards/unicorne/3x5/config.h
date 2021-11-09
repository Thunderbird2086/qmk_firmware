// Copyright 2021 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_LED_COUNT 48
#    define RGB_MATRIX_SPLIT \
        { 24, 24 }
#    define SPLIT_TRANSPORT_MIRROR
#endif
