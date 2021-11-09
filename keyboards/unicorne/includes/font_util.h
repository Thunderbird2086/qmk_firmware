// Copyright 2023 Allen Choi (@thunderbird2086)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

const char *read_font_qmk_logo(void);
const char *read_font_kb_split(void);
const char *read_icon_mod_ctrl(void);
const char *read_icon_mod_alt(void);
const char *read_icon_mod_shift(void);
const char *read_icon_mod_gui(void);
const char *read_icon_caps_lock(void);
const char *read_icon_rgb_status(bool on);
const char *read_layer(int layer, bool is_one_line);
