#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_extras/keymap_french.h"
#include "led.h"

#define BASE 0 // default layer
#define LAYER_MEDIA 1 // media keys
#define LAYER_SHIFT 2 // Shifted Layer
#define LAYER_FN 3 // Fn Layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        FR_AMP,         FR_LBRC,    FR_LCBR,    FR_RCBR,    FR_LPRN,    FR_EQL,     KC_DEL,
        FR_DLR,         FR_SCLN,    FR_COMM,    FR_DOT,     KC_P,       KC_Y,       KC_BSPC,
        KC_TAB,         FR_A,       KC_O,       KC_E,       KC_U,       KC_I,
        M(0),           FR_QUOT,    FR_Q,       KC_J,       KC_K,       KC_X,       KC_ESC,
        KC_LCTL,        FR_AMP,     KC_LALT,    KC_DOWN,    KC_UP,
                                                                                    KC_FN1,     KC_CLR,
                                                                                                KC_PSCR,
                                                                            KC_ENT, KC_BSPC,    KC_LGUI,
        // right hand
                    KC_CAPS,        FR_ASTR,    FR_RPRN,    FR_PLUS,    FR_RBRC,    FR_EXLM,    FR_HASH,
                    KC_BSPC,        KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       FR_SLSH,
                                    KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       FR_MINS,
                    KC_ENT,         KC_B,       FR_M,       FR_W,       KC_V,       FR_Z,       M(0),
                                                KC_LEFT,    KC_RIGHT,   FR_BSLS,    FR_AT,      KC_RCTL,
        KC_CLR,   KC_FN1,
        MO(LAYER_MEDIA),
        TG(LAYER_MEDIA),   KC_DEL, KC_SPC
    ),

// KEYPAD AND MOUSE
[LAYER_MEDIA] = KEYMAP(
        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_MS_U,    KC_TRNS,    KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_MS_WH_UP,
        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MS_WH_DOWN,  KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_BTN2,
                                                                                        KC_TRNS,    KC_TRNS,
                                                                                                    KC_TRNS,
                                                                            KC_BTN1,    KC_TRNS,    KC_TRNS,
    // right hand
                    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                    KC_TRNS,        KC_TRNS,    FR_1,       FR_2,       FR_3,       KC_TRNS,    KC_TRNS,
                                    KC_TRNS,    FR_4,       FR_5,       FR_6,       KC_TRNS,    KC_TRNS,
                    KC_TRNS,        KC_TRNS,    FR_7,       FR_8,       FR_9,       KC_TRNS,    KC_TRNS,
                                                FR_0,       FR_DOT,     KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,
        KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS
),

// SHIFTED LAYER
[LAYER_SHIFT] = KEYMAP(
        FR_UGRV,        KC_7,       KC_5,       KC_3,       KC_1,       KC_9,           KC_TRNS,
        M(1),           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
        KC_TRNS,        FR_UGRV,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                                        KC_TRNS,    KC_TRNS,
                                                                                                    KC_TRNS,
                                                                            KC_TRNS,    KC_TRNS,    KC_TRNS,
    // right hand
                    KC_TRNS,        KC_0,       KC_2,       KC_4,       KC_6,       KC_8,       M(1),
                    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    FR_COMM,
                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    M(1),
                    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                KC_TRNS,    KC_TRNS,    M(1),       M(1),       KC_TRNS,
        KC_TRNS,    KC_TRNS,
        KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS
),

// F1-F12 Layer
[LAYER_FN] = KEYMAP(
       // left hand
        KC_TRNS,        KC_F1,      KC_F2,      KC_F3,      KC_F4,          KC_F5,          KC_F6,
        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
        KC_LSFT,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_PGDN,    KC_PGUP,
                                                                                        KC_TRNS,    LCTL(KC_INS),
                                                                                                    LSFT(KC_DEL),
                                                                            KC_TRNS,    KC_TRNS,    LSFT(KC_INS),
       // right hand
                    KC_F7,          KC_F8,      KC_F9,      KC_F10,     KC_F11,         KC_F12,     KC_TRNS,
                    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,
                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,
                    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_RSFT,
                                                KC_HOME,    KC_END,     KC_TRNS,        KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,
        KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS
),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(LAYER_FN)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t macroId, uint8_t opt)
{
    switch (macroId)
    {
    case 0: // M(0) : Apply SHIFT and go to LAYER_SHIFT 
        {
            if (record->event.pressed)
            {
                register_code(KC_LSFT);
                layer_on(LAYER_SHIFT);
            }
            else
            {
                unregister_code(KC_LSFT);
                layer_off(LAYER_SHIFT);
            }
            break;
        }
    case 1: // M(1) : Unapply SHIFT and register keycode on press
        {
            uint16_t keycode = keymap_key_to_keycode(BASE, record->event.key);
            if (record->event.pressed)
            {
                unregister_code(KC_LSFT);
                switch (keycode)
                {
                case FR_DLR:
                    {
                        register_code(FR_TILD);
                        break;
                    }
                case FR_HASH:
                    {
                        register_code(FR_GRV);
                        break;
                    }
                case FR_MINS:
                    {
                        register_code(FR_UNDS);
                        break;
                    }
                case FR_AT:
                    {
                        register_code(FR_CIRC);
                        break;
                    }
                case FR_BSLS:
                    {
                        register_code(FR_PIPE);
                        break;
                    }
                }
            }
            else
            {
                switch (keycode)
                {
                case FR_DLR:
                    {
                        unregister_code(FR_TILD);
                        break;
                    }
                case FR_HASH:
                    {
                        unregister_code(FR_GRV);
                        break;
                    }
                case FR_MINS:
                    {
                        unregister_code(FR_UNDS);
                        break;
                    }
                case FR_AT:
                    {
                        unregister_code(FR_CIRC);
                        break;
                    }
                case FR_BSLS:
                    {
                        unregister_code(FR_PIPE);
                        break;
                    }
                }
                register_code(KC_LSFT);
            }
            break;
        }
    }
    return MACRO_NONE;
}

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {}

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void)
{
    uint8_t layer = biton32(layer_state);

    ergodox_led_all_off();
    switch (layer)
    {
    case LAYER_FN:
        ergodox_right_led_2_on();
        break;
    case LAYER_MEDIA:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
    default:
        break;
    }

    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))
    {
        ergodox_right_led_1_on();
    }
}
