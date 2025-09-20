/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include "keycodes.h"

// Function to send a key combination for OS-specific actions
void send_combo(uint16_t mod1, uint16_t mod2, uint16_t key) {
    if (mod1 != KC_NO) register_code(mod1);
    if (mod2 != KC_NO) register_code(mod2);
    tap_code(key);
    if (mod2 != KC_NO) unregister_code(mod2);
    if (mod1 != KC_NO) unregister_code(mod1);
}

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#   if defined(RGB_MATREX_ENABLE)
#		define OC_HUEU  RM_HUEU
#		define OC_SATU  RM_SATU
#		define OC_VALU  RM_VALU
#		define OC_SPDU  RM_SPDU
#		define OC_PREV  RM_PREV
#		define OC_TOGG  RM_TOGG
#		define OC_NEXT  RM_NEXT
#		define OC_HUED  RM_HUED
#		define OC_SATD  RM_SATD
#		define OC_VALD  RM_VALD
#		define OC_SPDD  RM_SPDD
#   else
#		define OC_HUEU  UG_HUEU
#		define OC_SATU  UG_SATU
#		define OC_VALU  UG_VALU
#		define OC_SPDU  UG_SPDU
#		define OC_PREV  UG_PREV
#		define OC_TOGG  UG_TOGG
#		define OC_NEXT  UG_NEXT
#		define OC_HUED  UG_HUED
#		define OC_SATD  UG_SATD
#		define OC_VALD  UG_VALD
#		define OC_SPDD  UG_SPDD
#   endif
#else
#	define OC_HUEU  _______
#	define OC_SATU  _______
#	define OC_VALU  _______
#	define OC_SPDU  _______
#	define OC_PREV  _______
#	define OC_TOGG  _______
#	define OC_NEXT  _______
#	define OC_HUED  _______
#	define OC_SATD  _______
#	define OC_VALD  _______
#	define OC_SPDD  _______
#endif

#define QWERTY_LAYER 0
#define COLMAK_LAYER 1

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
		KC_CAPS, LOPT_A , LSFT_R , LCTL_S , MLCMD_T, KC_G   , KC_M   , RCMD_N , RCTL_E , RSFT_I , ROPT_O , KC_QUOT,          KC_ENT ,                                    KC_P4  , KC_P5  , KC_P6  ,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH,                   KC_RSFT,              KC_UP  ,              KC_P1  , KC_P2  , KC_P3  , KC_PENT,
		KC_LCTL, KC_LOPT, KC_LCMD,                   KC_SPC ,                            KC_RCMD, KC_ROPT, MO(2)  ,          KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT,     KC_P0  ,          KC_PDOT
	),

	[2] = LAYOUT(
		OC_ZL  ,          OC_ZR  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL ,     _______, _______, _______,     _______, _______, _______, _______,
		OC_ZU  , _______, KC_HOME, KC_UP  , KC_END , KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
		OC_ZC  , _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, _______, _______, _______, _______,          _______,                                    _______, _______, _______,
		OC_ZH  , _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, _______, _______, _______, _______, _______,                   _______,              _______,              _______, _______, _______, _______,
		OC_ZA  , OC_ZV  , OC_ZS  ,                   MO(3)  ,                            _______, _______, _______,          _______,     _______, _______, _______,     _______,          _______
	),

	[3] = LAYOUT(
		QK_BOOT,          QWERTY , COLEMAK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, OC_HUEU, OC_SATU, OC_VALU, OC_SPDU, _______, _______, _______,     _______, _______, _______,     _______, _______, _______, _______,
		QK_RBT , _______, _______, _______, _______, _______, _______, OC_PREV, OC_TOGG, OC_NEXT, _______, _______,          _______,                                    _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, OC_HUED, OC_SATD, OC_VALD, OC_SPDD,                   _______,              _______,              _______, _______, _______, _______,
		EE_CLR , _______, _______,                   _______,                            _______, _______, _______,          _______,     _______, _______, _______,     _______,          _______
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

bool zoom_share(bool pressed) {
	if (!pressed) return true;
	
	switch(detected_host_os()) {
		case OS_MACOS:
		case OS_IOS:
			send_combo(KC_LGUI, KC_LSFT, KC_S);
			break;
		case OS_WINDOWS:
		case OS_LINUX:
			send_combo(KC_LALT, KC_NO, KC_S);
			break;
		default:
			return true;
	}
	return false;
}

bool zoom_chat(bool pressed) {
	if (!pressed) return true;
	
	switch(detected_host_os()) {
		case OS_MACOS:
		case OS_IOS:
			send_combo(KC_LGUI, KC_LSFT, KC_H);
			break;
		case OS_WINDOWS:
		case OS_LINUX:
			send_combo(KC_LALT, KC_NO, KC_H);
			break;
		default:
			return true;
	}
	return false;
}

bool zoom_participants(bool pressed) {
	if (!pressed) return true;
	
	switch(detected_host_os()) {
		case OS_MACOS:
		case OS_IOS:
			send_combo(KC_LGUI, KC_NO, KC_U);
			break;
		case OS_WINDOWS:
		case OS_LINUX:
			send_combo(KC_LALT, KC_NO, KC_U);
			break;
		default:
			return true;
	}
	return false;
}

bool zoom_leave(bool pressed) {
	if (!pressed) return true;
	
	switch(detected_host_os()) {
		case OS_MACOS:
		case OS_IOS:
			send_combo(KC_LGUI, KC_NO, KC_W);
			break;
		case OS_WINDOWS:
		case OS_LINUX:
			send_combo(KC_LALT, KC_NO, KC_Q);
			break;
		default:
			return true;
	}
	return false;
}

bool zoom_raise_hand(bool pressed) {
	if (!pressed) return true;
	
	switch(detected_host_os()) {
		case OS_MACOS:
		case OS_IOS:
			send_combo(KC_LALT, KC_NO, KC_Y);
			break;
		case OS_WINDOWS:
		case OS_LINUX:
			send_combo(KC_LALT, KC_NO, KC_Y);
			break;
		default:
			return true;
	}
	return false;
}

bool zoom_record(bool pressed) {
	if (!pressed) return true;
	
	switch(detected_host_os()) {
		case OS_MACOS:
		case OS_IOS:
			send_combo(KC_LGUI, KC_LSFT, KC_R);
			break;
		case OS_WINDOWS:
		case OS_LINUX:
			send_combo(KC_LALT, KC_NO, KC_R);
			break;
		default:
			return true;
	}
	return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
		case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(QWERTY_LAYER);
            }
            return false;
		case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(COLMAK_LAYER);
            }
            return false;
		case OC_ZV:
			return zoom_video(record->event.pressed);
		case OC_ZA:
			return zoom_audio(record->event.pressed);
		case OC_ZS:
			return zoom_share(record->event.pressed);
		case OC_ZC:
			return zoom_chat(record->event.pressed);
		case OC_ZU:
			return zoom_participants(record->event.pressed);
		case OC_ZL:
			return zoom_leave(record->event.pressed);
		case OC_ZH:
			return zoom_raise_hand(record->event.pressed);
		case OC_ZR:
			return zoom_record(record->event.pressed);
	}

    return true; // Allow other keycodes to be processed normally
}

uint32_t swap_cmd_opt(uint32_t trigger_time, void *cb_arg) {
  uint16_t retry_ms = 500;

  if (detected_host_os() == OS_WINDOWS) {
    keymap_config.swap_lalt_lgui = true;
    keymap_config.swap_ralt_rgui = true;
    retry_ms = 0;
  }

  return retry_ms;
}

void keyboard_post_init_user(void) {
  defer_exec(100, swap_cmd_opt, NULL);
}

const uint8_t func_row_leds[] = { 3, 12, 21, 22, 31, 32, 41,  42, 51, 52, 60, 61, 68 };

bool rgb_matrix_indicators_user(void) {
    rgb_matrix_set_color(func_row_leds[0], 255, 0, 0);
    rgb_matrix_set_color(func_row_leds[1], 0, 255, 0);
    for(uint8_t a_led = 2; a_led < sizeof(func_row_leds); ++a_led) {
        rgb_matrix_set_color(func_row_leds[a_led], 255, 255, 0);
    }

    return true;
}
