/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

enum custom_keycodes {
    OC_ZOOM_VIDEO = SAFE_RANGE,
	OC_ZOOM_AUDIO,
};

#define OC_ZV OC_ZOOM_VIDEO
#define OC_ZA OC_ZOOM_AUDIO

// Function to send a key combination for OS-specific actions
void send_combo(uint16_t mod1, uint16_t mod2, uint16_t key) {
    if (mod1 != KC_NO) register_code(mod1);
    if (mod2 != KC_NO) register_code(mod2);
    tap_code(key);
    if (mod2 != KC_NO) unregister_code(mod2);
    if (mod1 != KC_NO) unregister_code(mod1);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		KC_ESC ,          KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,     KC_PSCR, KC_BRMD, KC_BRMU,     _______, KC_MUTE, KC_VOLD, KC_VOLU,
		KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,     KC_INS , KC_HOME, KC_PGUP,     KC_NUM , KC_PSLS, KC_PAST, KC_PMNS,
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,     KC_DEL , KC_END , KC_PGDN,     KC_P7  , KC_P8  , KC_P9  , KC_PPLS,
		KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT ,                                    KC_P4  , KC_P5  , KC_P6  ,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,                   KC_RSFT,              KC_UP  ,              KC_P1  , KC_P2  , KC_P3  , KC_PENT,
		KC_LCTL, KC_LOPT, KC_LCMD,                   KC_SPC ,                            KC_RCMD, KC_ROPT, MO(2)  ,          KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT,     KC_P0  ,          KC_PDOT
	),

	[1] = LAYOUT(
		KC_ESC ,          KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,     KC_PSCR, KC_BRMD, KC_BRMU,     _______, KC_MUTE, KC_VOLD, KC_VOLU,
		KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,     KC_INS , KC_HOME, KC_PGUP,     KC_NUM , KC_PSLS, KC_PAST, KC_PMNS,
		KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,     KC_DEL , KC_END , KC_PGDN,     KC_P7  , KC_P8  , KC_P9  , KC_PPLS,
		KC_CAPS, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,          KC_ENT ,                                    KC_P4  , KC_P5  , KC_P6  ,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH,                   KC_RSFT,              KC_UP  ,              KC_P1  , KC_P2  , KC_P3  , KC_PENT,
		KC_LCTL, KC_LOPT, KC_LCMD,                   KC_SPC ,                            KC_RCMD, KC_ROPT, MO(2)  ,          KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT,     KC_P0  ,          KC_PDOT
	),

	[2] = LAYOUT(
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
		_______, KC_HOME, KC_UP  , KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
		_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                                    _______, _______, _______,
		_______, KC_END , _______, KC_PGDN, _______, _______, _______, _______, OC_ZV  , OC_ZA  , _______,                   _______,              _______,              _______, _______, _______, _______,
		_______, _______, _______,                   MO(3)  ,                            _______, _______, _______,          _______,     _______, _______, _______,     _______,          _______
	),

	[3] = LAYOUT(
		QK_BOOT,          DF(0)  , DF(1)  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                                    _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,              _______,              _______, _______, _______, _______,
		_______, _______, _______,                   _______,                            _______, _______, _______,          _______,     _______, _______, _______,     _______,          _______
	),

};

bool zoom_video(bool pressed) {
	if (!pressed) {
		return true; // Do not process on release
	}

	switch(detected_host_os()) {
		case OS_MACOS:
		case OS_IOS:
			send_combo(KC_LGUI, KC_LSFT, KC_V);
			break;
		case OS_WINDOWS:
		case OS_LINUX:
			send_combo(KC_LALT, KC_NO, KC_V);
			break;
		default:
			return true; // Do not process if the OS is not recognized
	}

	return false;
}

bool zoom_audio(bool pressed) {
	if (!pressed) {
		return true; // Do not process on release
	}

	switch(detected_host_os()) {
		case OS_MACOS:
		case OS_IOS:
			send_combo(KC_LGUI, KC_LSFT, KC_A);
			break;
		case OS_WINDOWS:
		case OS_LINUX:
			send_combo(KC_LALT, KC_NO, KC_A);
			break;
		default:
			return true; // Do not process if the OS is not recognized
	}

	return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	bool result = true;

    switch(keycode) {
		case OC_ZOOM_AUDIO:
			result = zoom_audio(record->event.pressed);
			break;
		case OC_ZOOM_VIDEO:
			result = zoom_video(record->event.pressed);
			break;
		default:
			result = true; // Allow other keycodes to be processed normally
			break;
	}

    return result;
}

uint32_t swap_cmd_opt(uint32_t trigger_time, void *cb_arg) {
  os_variant_t host = detected_host_os();
  uint16_t retry_ms = 500;

  if (host == OS_MACOS || host == OS_IOS) {
    keymap_config.swap_lalt_lgui = true;
    keymap_config.swap_ralt_rgui = true;
    retry_ms = 0;
  }

  return retry_ms;
}

void keyboard_post_init_user(void) {
  defer_exec(100, swap_cmd_opt, NULL);
}