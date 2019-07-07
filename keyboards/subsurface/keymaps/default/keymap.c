// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "subsurface.h"

#include "lookup_tables/shelton_tables.h"
#include "lookup_tables/misc_tables.h"
#include "lookup_tables/user_tables.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     2
#define _SYM    3
#define _STENO  1

// Keys family
enum key_family
{
    FAMILY_UNKNOWN,
    FAMILY_SPECIAL_CONTROLS,
    FAMILY_CASE_CONTROLS,
    FAMILY_LEFT_USER_SYMBOLS,
    FAMILY_LEFT_HAND,
    FAMILY_THUMBS,
    FAMILY_RIGHT_HAND,
    FAMILY_RIGHT_PINKY,
    FAMILY_LEFT_NUMBERS,
    FAMILY_RIGHT_NUMBERS,
    FAMILY_RIGHT_USER_SYMBOLS,
    FAMILY_SPACES,
    NB_FAMILY
};

// Bit to identify a steno key
#define STENO_BIT (1L << 31) 

// 2 bits for star and the plus key
#define OFFSET_SPECIAL_CONTROLS 0
#define SC_STAR (0 | (FAMILY_SPECIAL_CONTROLS << 4) | STENO_BIT)
#define SC_PLUS (1 | (FAMILY_SPECIAL_CONTROLS << 4) | STENO_BIT)

// 8 bits for the left hand
#define OFFSET_LEFT_HAND 2
#define L_A (0 | (FAMILY_LEFT_HAND << 4) | STENO_BIT)
#define L_S (1 | (FAMILY_LEFT_HAND << 4) | STENO_BIT)
#define L_C (2 | (FAMILY_LEFT_HAND << 4) | STENO_BIT)
#define L_T (3 | (FAMILY_LEFT_HAND << 4) | STENO_BIT)
#define L_W (4 | (FAMILY_LEFT_HAND << 4) | STENO_BIT)
#define L_H (5 | (FAMILY_LEFT_HAND << 4) | STENO_BIT)
#define L_N (6 | (FAMILY_LEFT_HAND << 4) | STENO_BIT)
#define L_R (7 | (FAMILY_LEFT_HAND << 4) | STENO_BIT)

// 5 bits for thumbs
#define OFFSET_THUMBS 10
#define T_E (0 | (FAMILY_THUMBS << 4) | STENO_BIT)
#define T_O (1 | (FAMILY_THUMBS << 4) | STENO_BIT)
#define T_A (2 | (FAMILY_THUMBS << 4) | STENO_BIT)
#define T_U (3 | (FAMILY_THUMBS << 4) | STENO_BIT)
#define T_I (4 | (FAMILY_THUMBS << 4) | STENO_BIT)

// 8 bits for the right hand
#define OFFSET_RIGHT_HAND 15
#define R_R (0 | (FAMILY_RIGHT_HAND << 4) | STENO_BIT)
#define R_N (1 | (FAMILY_RIGHT_HAND << 4) | STENO_BIT)
#define R_L (2 | (FAMILY_RIGHT_HAND << 4) | STENO_BIT)
#define R_G (3 | (FAMILY_RIGHT_HAND << 4) | STENO_BIT)
#define R_C (4 | (FAMILY_RIGHT_HAND << 4) | STENO_BIT)
#define R_H (5 | (FAMILY_RIGHT_HAND << 4) | STENO_BIT)
#define R_T (6 | (FAMILY_RIGHT_HAND << 4) | STENO_BIT)
#define R_S (7 | (FAMILY_RIGHT_HAND << 4) | STENO_BIT)

// 3 bits for E and Y and S
#define OFFSET_RIGHT_PINKY 23
#define RP_E  (0 | (FAMILY_RIGHT_PINKY << 4) | STENO_BIT)
#define RP_Y  (1 | (FAMILY_RIGHT_PINKY << 4) | STENO_BIT)
#define RP_S  (2 | (FAMILY_RIGHT_PINKY << 4) | STENO_BIT)

// 3 bits for space control keys
#define OFFSET_SPACE_CONTROLS 26
#define S_MSPC  (0 | (FAMILY_SPACES << 4) | STENO_BIT)
#define S_DOT   (1 | (FAMILY_SPACES << 4) | STENO_BIT)
#define S_ENT   (2 | (FAMILY_SPACES << 4) | STENO_BIT)
#define S_COMM  (3 | (FAMILY_SPACES << 4) | STENO_BIT)

// 2 bits for case control keys (upper case, initial case)
#define OFFSET_CASE_CONTROLS 30
#define C_UC   (0 | (FAMILY_CASE_CONTROLS << 4) | STENO_BIT)
#define C_IC   (1 | (FAMILY_CASE_CONTROLS << 4) | STENO_BIT)

// 6 bits for left user symbols
#define OFFSET_LEFT_USER_SYMBOLS 0
#define USRL_0  (0 | (FAMILY_LEFT_USER_SYMBOLS << 4) | STENO_BIT)
#define USRL_1  (1 | (FAMILY_LEFT_USER_SYMBOLS << 4) | STENO_BIT)
#define USRL_2  (2 | (FAMILY_LEFT_USER_SYMBOLS << 4) | STENO_BIT)
#define USRL_3  (3 | (FAMILY_LEFT_USER_SYMBOLS << 4) | STENO_BIT)
#define USRL_4  (4 | (FAMILY_LEFT_USER_SYMBOLS << 4) | STENO_BIT)
#define USRL_5  (5 | (FAMILY_LEFT_USER_SYMBOLS << 4) | STENO_BIT)

// 6 bits for right user symbols
#define OFFSET_RIGHT_USER_SYMBOLS 6
#define USRR_0  (0 | (FAMILY_RIGHT_USER_SYMBOLS << 4) | STENO_BIT)
#define USRR_1  (1 | (FAMILY_RIGHT_USER_SYMBOLS << 4) | STENO_BIT)
#define USRR_2  (2 | (FAMILY_RIGHT_USER_SYMBOLS << 4) | STENO_BIT)
#define USRR_3  (3 | (FAMILY_RIGHT_USER_SYMBOLS << 4) | STENO_BIT)
#define USRR_4  (4 | (FAMILY_RIGHT_USER_SYMBOLS << 4) | STENO_BIT)
#define USRR_5  (5 | (FAMILY_RIGHT_USER_SYMBOLS << 4) | STENO_BIT)

// 5 bits for left numbers
#define OFFSET_LEFT_NUMBERS 12
#define NL_B0  (0 | (FAMILY_LEFT_NUMBERS << 4) | STENO_BIT)
#define NL_B1  (1 | (FAMILY_LEFT_NUMBERS << 4) | STENO_BIT)
#define NL_B2  (2 | (FAMILY_LEFT_NUMBERS << 4) | STENO_BIT)
#define NL_B3  (3 | (FAMILY_LEFT_NUMBERS << 4) | STENO_BIT)
#define NL_N0  (4 | (FAMILY_LEFT_NUMBERS << 4) | STENO_BIT)

// 5 bits for right numbers
#define OFFSET_RIGHT_NUMBERS 17
#define NR_B0  (0 | (FAMILY_RIGHT_NUMBERS << 4) | STENO_BIT)
#define NR_B1  (1 | (FAMILY_RIGHT_NUMBERS << 4) | STENO_BIT)
#define NR_B2  (2 | (FAMILY_RIGHT_NUMBERS << 4) | STENO_BIT)
#define NR_B3  (3 | (FAMILY_RIGHT_NUMBERS << 4) | STENO_BIT)
#define NR_N0  (4 | (FAMILY_RIGHT_NUMBERS << 4) | STENO_BIT)

// Table to convert family id to bit offset
const uint8_t g_family_to_bit_offset[NB_FAMILY] =
{
    0,
    OFFSET_SPECIAL_CONTROLS,
    OFFSET_CASE_CONTROLS,
    OFFSET_LEFT_USER_SYMBOLS,
    OFFSET_LEFT_HAND,
    OFFSET_THUMBS,
    OFFSET_RIGHT_HAND,
    OFFSET_RIGHT_PINKY,
    OFFSET_LEFT_NUMBERS,
    OFFSET_RIGHT_NUMBERS,
    OFFSET_RIGHT_USER_SYMBOLS,
    OFFSET_SPACE_CONTROLS
};

// A lookup table can stores letters (8 bits) or symbols (16 bits)
enum kind_table
{
    KIND_UNKNOWN,
    KIND_LETTERS,
    KIND_SYMBOLS
};

const uint8_t g_family_to_kind_table[NB_FAMILY] =
{
    KIND_UNKNOWN,
    KIND_UNKNOWN,
    KIND_UNKNOWN,
    KIND_SYMBOLS,
    KIND_LETTERS,
    KIND_LETTERS,
    KIND_LETTERS,
    KIND_LETTERS,
    KIND_SYMBOLS,
    KIND_SYMBOLS,
    KIND_SYMBOLS,
    KIND_SYMBOLS
};

// Global vars for the steno layer
uint32_t g_bits_keys_pressed_part1 = 0;
uint32_t g_bits_keys_pressed_part2 = 0;

uint32_t* g_family_to_keys_pressed[NB_FAMILY] = 
{
    &g_bits_keys_pressed_part1,
    &g_bits_keys_pressed_part1,
    &g_bits_keys_pressed_part1,
    &g_bits_keys_pressed_part2,
    &g_bits_keys_pressed_part1,
    &g_bits_keys_pressed_part1,
    &g_bits_keys_pressed_part1,
    &g_bits_keys_pressed_part1,
    &g_bits_keys_pressed_part2,
    &g_bits_keys_pressed_part2,
    &g_bits_keys_pressed_part2,
    &g_bits_keys_pressed_part1
};

uint8_t g_family_bits[NB_FAMILY] = {0};
typedef const uint8_t letters_table_t[MAX_LETTERS];
typedef const uint16_t symbols_table_t[MAX_SYMBOLS];
void* g_all_tables[NB_FAMILY] = 
{
    0,
    0,
    0,
    g_left_user_symbols_table,
    g_left_hand_table,
    g_thumbs_table,
    g_right_hand_table,
    g_right_pinky_table,
    g_left_numbers,
    g_right_numbers,
    g_right_user_symbols_table,
    g_spaces_ctl_table
};

#define SPECIAL_SHIFT_TABLE_SIZE 20

// This table was computed externally
const uint16_t g_special_shift_table[SPECIAL_SHIFT_TABLE_SIZE] =
{
    KC_3,       // [0] KC_RCBR
    0,          // [1]
    KC_8,       // [2] KC_EXLM
    LSFT(KC_6), // [3] KC_AT
    0,          // [4]
    0,          // [5]
    KC_9,       // [6] KC_EQL
    KC_7,       // [7] KC_LBRC
    KC_6,       // [8] KC_RBRC
    KC_0,       // [9] KC_ASTR
    KC_1,       // [10] KC_LPRN
    KC_2,       // [11] KC_RPRN
    0,          // [12]
    0,          // [13]
    0,          // [14]
    0,          // [15]
    0,          // [16]
    0,          // [17]
    KC_4,       // [18] KC_PLUS
    KC_5        // [19] KC_LCBR
};

#define MAX_UNDO 100
uint8_t g_undo_stack[MAX_UNDO] = {0};
int8_t g_undo_stack_index = 0;
bool space_mode = true;

// Steno keymap
const uint32_t PROGMEM g_steno_keymap[2][MATRIX_ROWS][MATRIX_COLS] = {
// BASE STENO MAP
KEYMAP(
  KC_TRNS, USRL_3, S_COMM, S_DOT, SC_PLUS,   USRR_1, USRR_0, RP_E, RP_Y, RP_S,
  L_A,     L_C, L_W, L_N, SC_PLUS,           USRR_5, R_R, R_L, R_C, R_T,
  L_S,     L_T, L_H, L_R, SC_PLUS,           USRR_4, R_N, R_G, R_H, R_S,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, T_E, SC_STAR, 
  T_O, SC_STAR, T_A, T_U,
  SC_STAR, T_I, KC_TRNS, KC_TRNS, RP_E, S_ENT, 
  C_IC, S_MSPC, KC_TRNS),
// SHIFT STENO MAP
KEYMAP(
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0, 0, 0,
  0, 0, 0)
};

#define STENO 0
#define ST_ON M(STENO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP(
  KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,   KC_P,
  KC_A, KC_S, KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,   KC_QUOT,
  KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
  KC_GRV,  DF(_STENO), GUI_T(KC_TAB), OSL(_FN), KC_LSFT, CTL_T(KC_ESC), 
  KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, 
  KC_LALT, KC_SPC, KC_BSPC, KC_SCLN, KC_MINS, KC_ENT,
  OSL(_SYM), OSL(_SYM), KC_BTN1),
[_SYM] = KEYMAP(
  KC_PIPE, KC_EXLM, KC_LCBR, KC_RCBR, KC_AT,   KC_PLUS,  KC_7, KC_8, KC_9, KC_CIRC,
  KC_AMPR, KC_HASH, KC_LPRN, KC_RPRN, KC_DLR,  KC_EQL,   KC_4, KC_5, KC_6, KC_ASTR,
  KC_SCLN, KC_PERC, KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS,  KC_1, KC_2, KC_3, KC_SLSH,
  KC_GRV,  KC_TRNS, GUI_T(KC_TAB), OSL(_FN), KC_LSFT, CTL_T(KC_ESC), 
  KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, 
  KC_LALT, KC_SPC, KC_BSPC, KC_DOT, KC_0, KC_ENT,
  OSL(_SYM), OSL(_SYM), KC_BTN2),
[_FN] = KEYMAP(
  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_WH_U,
  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_WH_D,
  KC_F9,  KC_F10, KC_F11, KC_F12, KC_BTN1, KC_WH_L, KC_WH_R, KC_DEL, KC_TRNS,  RESET,
  KC_GRV, KC_TRNS, GUI_T(KC_TAB), OSL(_FN), KC_LSFT, CTL_T(KC_ESC), 
  KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, 
  KC_LALT, KC_SPC, KC_BSPC, KC_TRNS, KC_TRNS, KC_ENT,
  OSL(_SYM), OSL(_SYM), KC_BTN3),
[_STENO] = KEYMAP(
  ST_ON, ST_ON, ST_ON, ST_ON, ST_ON,   ST_ON, ST_ON, ST_ON, ST_ON, ST_ON,
  ST_ON, ST_ON, ST_ON, ST_ON, ST_ON,   ST_ON, ST_ON, ST_ON, ST_ON, ST_ON,
  ST_ON, ST_ON, ST_ON, ST_ON, ST_ON,   ST_ON, ST_ON, ST_ON, ST_ON, ST_ON,
  KC_CAPS, DF(_QWERTY), OSL(_FN), OSL(_SYM), ST_ON, ST_ON, 
  ST_ON, ST_ON, ST_ON, ST_ON, 
  ST_ON, ST_ON, KC_SPC, KC_BSPC, ST_ON, ST_ON, 
  ST_ON, ST_ON, KC_BTN1)
};

// void dance_eql_steno (qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 3) {
//     // ACTION_LAYER_DEFAULT_LAYER_SET(_STENO);
//   } else {
//     register_code (KC_EQL);
//   }
// }
// 
// const qk_tap_dance_action_t tap_dance_actions[] = {
//     [0] = ACTION_TAP_DANCE_FN(dance_eql_steno)   
// };

// const uint16_t PROGMEM fn_actions[] = {
//     [0] = ACTION_LAYER_DEFAULT_LAYER_SET(_STENO),   
//     [1] = ACTION_LAYER_DEFAULT_LAYER_SET(_QWERTY)   
// };

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
// {
//   // MACRODOWN only works in this function
//       switch(id) {
//         case 0:
//           if (record->event.pressed) {
//             register_code(KC_RSFT);
//           } else {
//             unregister_code(KC_RSFT);
//           }
//         break;
//       }
//     return MACRO_NONE;
// };

bool can_stroke(void) { return (g_bits_keys_pressed_part1 == 0) && (g_bits_keys_pressed_part2 == 0); }

void send_mods_and_code(uint8_t mods, uint8_t code)
{
    const uint8_t original_mods = get_mods();
    set_mods(mods);
    register_code(code);
    set_mods(original_mods);
}

bool is_letter(uint8_t code)
{
#ifdef AZERTY
    return (code != FR_COMM) && (((code >= KC_A) && (code <= KC_Z)) || (code == FR_M));
#else
    return (code >= KC_A) && (code <= KC_Z);
#endif
}

void stroke(void)
{
    // Send characters for each key family
    const uint8_t original_mods = get_mods();
    del_mods(MOD_LSFT|MOD_RSFT);
    bool initial_case_1 = false;
    bool initial_case_2 = false;
    uint8_t sent_count = 0;

    // Get *, + and case controls info
    const uint8_t special_controls_bits = g_family_bits[FAMILY_SPECIAL_CONTROLS];
    const uint8_t thumbs_bits = g_family_bits[FAMILY_THUMBS];
    const bool has_star = special_controls_bits & (1 << (SC_STAR & 0xF));
    const bool has_plus = special_controls_bits & (1 << (SC_PLUS & 0xF));
    const bool has_metaspace = g_family_bits[FAMILY_SPACES] & (1 << (S_MSPC & 0xF));
    const bool has_enter = g_family_bits[FAMILY_SPACES] & (1 << (S_ENT & 0xF));
    const uint8_t case_controls_bits = g_family_bits[FAMILY_CASE_CONTROLS];
    if (case_controls_bits)
    {
        initial_case_1 = case_controls_bits == 2;
        initial_case_2 = case_controls_bits == 3;
        add_mods(MOD_LSFT);
    }

    // Evaluate stroke
    bool undo_allowed = true;
    for (int family_id = 0; family_id < NB_FAMILY; ++family_id)
    {
        uint8_t family_bits = g_family_bits[family_id];
        if (family_bits == 0)
        {
            continue;
        }

        // Get the lookup table
        undo_allowed = family_id == FAMILY_SPECIAL_CONTROLS;
        void* any_table = 0;
        uint8_t kind = g_family_to_kind_table[family_id];
        if (family_id == FAMILY_THUMBS && has_star)
        {
            any_table = g_thumbs_bigrams_table;
        }
        else if (family_id == FAMILY_LEFT_HAND && has_star && !thumbs_bits)
        {
            any_table = g_left_punctuations_table;
            family_bits = family_bits >> 2;
            kind = KIND_SYMBOLS;
        }
        else if (family_id == FAMILY_RIGHT_HAND && has_star && !thumbs_bits)
        {
            any_table = g_right_punctuations_table;
            kind = KIND_SYMBOLS;
        }
        else
        {
            any_table = g_all_tables[family_id];
        }

        if (any_table)
        {
            if (kind == KIND_LETTERS)
            {
                uint8_t register_count = 0;
                uint8_t last_byte = 0;
                letters_table_t* letters_table = (letters_table_t*)any_table;
                for (int code_pos = 0; code_pos < MAX_LETTERS; ++code_pos)
                {
                    const uint8_t byte = pgm_read_byte(&(letters_table[family_bits][code_pos]));
                    if (byte)
                    {
                        register_code(byte);
                        unregister_code(byte);
                        last_byte = byte;
                        register_count++;
                        sent_count++;

                        if ((initial_case_1 && sent_count == 1) || (initial_case_2 && sent_count == 2))
                        {
                            del_mods(MOD_LSFT);
                        }
                    }
                    else
                    {
                        // Double the consonnant for the right hand only
                        if (    has_plus && (register_count == 1)
                                && (family_id == FAMILY_RIGHT_HAND)
                                && (last_byte != 0))
                        {
                            register_code(last_byte);
                            unregister_code(last_byte);
                            sent_count++;
                        }
                        break;
                    }
                }
            }
            else
            {
                symbols_table_t* symbols_table = (symbols_table_t*)any_table;
                for (int code_pos = 0; code_pos < MAX_SYMBOLS; ++code_pos)
                {
                    const uint16_t word = pgm_read_word(&(symbols_table[family_bits][code_pos]));
                    if (word)
                    {
                        const uint8_t code = (uint8_t)word;
                        if (is_letter(code))
                        {
                            // By doing this the shift mod can be applied on letter code
                            register_code(code);
                        }
                        else
                        {
                            send_mods_and_code(word >> 8, code);
                        }

                        unregister_code(code);
                        sent_count++;

                        if ((initial_case_1 && sent_count == 1) || (initial_case_2 && sent_count == 2))
                        {
                            del_mods(MOD_LSFT);
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    int8_t previous_index = g_undo_stack_index - 1;
    if (sent_count > 0 && space_mode != has_metaspace && !has_enter)   // insert a trailing space in space mode
    {
        register_code(KC_SPC);
        unregister_code(KC_SPC);
        sent_count++;
    }
    else if (sent_count == 0 && has_metaspace && !has_star)   // single "no space" toggles space mode
    {
        space_mode = !space_mode;
        if (space_mode) // insert a space after entering space mode
        {
            register_code(KC_SPC);
            unregister_code(KC_SPC);
            sent_count++;
        }
    }
    else if (sent_count == 0 && has_metaspace && has_star)  
    {
        // nothing for now
    } 
    else if (sent_count == 0 && has_star && undo_allowed)
    {
        // Compute the previous index
        if (previous_index < 0)
        {
            previous_index = MAX_UNDO - 1;
        }

        // Check if we have data to undo at previous_index
        const uint8_t chars_to_delete = g_undo_stack[previous_index];
        if (chars_to_delete)
        {
            // We have data to undo
            for (uint8_t i = 0; i < chars_to_delete; ++i)
            {
                register_code(KC_BSPC);
                unregister_code(KC_BSPC);
            }

            // Reset data and update the undo stack index
            g_undo_stack[previous_index] = 0;
            g_undo_stack_index = previous_index;
        }
    }
    if (sent_count > 0)
    {
        // Undo history
        if (g_undo_stack_index == MAX_UNDO)
        {
            g_undo_stack_index = 0;
        }

        g_undo_stack[g_undo_stack_index++] = sent_count;
    }

    // Restore original mods
    set_mods(original_mods);

    // Clear bits
    for (int i = 0; i < NB_FAMILY; ++i)
    {
        g_family_bits[i] = 0;
    }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t macroId, uint8_t opt)
{
    switch (macroId)
    {
    case STENO:
        {
            const uint32_t dword = pgm_read_dword(&(g_steno_keymap[0][record->event.key.row][record->event.key.col]));
            if (dword)
            {
                if (dword & STENO_BIT)
                {
                    const uint32_t bit_key = 1L << (dword & 0x0F);
                    const uint8_t family = (dword >> 4) & 0x0F;
                    const uint8_t family_offset = g_family_to_bit_offset[family];
                    uint32_t* keys_pressed_p = g_family_to_keys_pressed[family];
                    if (record->event.pressed)
                    {
                        if (family == FAMILY_CASE_CONTROLS)
                        {
                            register_code(KC_LSFT);
                        }

                        (*keys_pressed_p) |= (bit_key << family_offset);
                        g_family_bits[family] |= bit_key;
                    }
                    else
                    {
                        (*keys_pressed_p) &= ~(bit_key << family_offset);

                        // Stroke if all steno keys are released
                        if (can_stroke())
                        {
                            stroke();
                        }

                        if (family == FAMILY_CASE_CONTROLS)
                        {
                            unregister_code(KC_LSFT);
                        }
                    }
                }
                else
                {
                    const uint16_t base_word = (uint16_t)dword;
                    const uint8_t base_code = (uint8_t)dword;
                    const uint32_t dword_shift = pgm_read_dword(&(g_steno_keymap[1][record->event.key.row][record->event.key.col]));
                    const uint16_t word_shift = (uint16_t)dword_shift;
                    bool send_shift_code = false;
                    uint8_t shift_code = 0;
                    if (dword_shift)
                    {
                        shift_code = (uint8_t)word_shift;
                        uint32_t* keys_pressed_p = g_family_to_keys_pressed[FAMILY_CASE_CONTROLS];
                        if ((*keys_pressed_p) & ((uint32_t)(3) << OFFSET_CASE_CONTROLS))
                        {
                            send_shift_code = true;
                        }
                    }

                    if (send_shift_code)
                    {
                        if (record->event.pressed)
                        {
                            send_mods_and_code(word_shift >> 8, shift_code);
                        }
                        else
                        {
                            unregister_code(base_code);
                            unregister_code(shift_code);
                        }
                    }
                    else
                    {
                        // Send mods and key code
                        if (record->event.pressed)
                        {
                            send_mods_and_code(base_word >> 8, base_code);
                        }
                        else
                        {
                            unregister_code(base_code);
                            if (shift_code)
                            {
                                unregister_code(shift_code);
                            }
                        }
                    }
                }
            }
            break;
        }
#ifdef BASE_LAYER_COLEMAK
    case GO_SFT: // Apply SHIFT and go to LAYER_SHIFT_COLEMAK
        {
			const uint8_t shift_key = record->event.key.row == 0 ? KC_LSFT : KC_RSFT;
            if (record->event.pressed)
            {
				register_code(shift_key);
                layer_on(LAYER_SHIFT_COLEMAK);
            }
            else
            {
				unregister_code(shift_key);
                layer_off(LAYER_SHIFT_COLEMAK);
            }
            break;
        }
    case SP_SFT: // Handle special shift codes for the Programmer Colemak layout
        {
            const uint16_t keycode = keymap_key_to_keycode(LAYER_BASE , record->event.key);
            const uint16_t special_shift_code = g_special_shift_table[keycode % SPECIAL_SHIFT_TABLE_SIZE];
            const uint8_t code = (uint8_t)special_shift_code;
            if (record->event.pressed)
            {
                send_mods_and_code(special_shift_code >> 8, code);
            }
            else
            {
                unregister_code(code);
            }
            break;
        }
#ifdef AZERTY
    case CIRC:
        {
            if (record->event.pressed)
            {
				const uint16_t keycode = keymap_key_to_keycode(LAYER_BASE , record->event.key);
                register_code(KC_LBRC);
                unregister_code(KC_LBRC);
                register_code(keycode);
                unregister_code(keycode);
            }
            break;
        }
#endif
#endif
    }
    return MACRO_NONE;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{
    // uint8_t layer = biton32(layer_state);

    // ergodox_board_led_on();
    // ergodox_right_led_1_off();
    // ergodox_right_led_2_off();
    // ergodox_right_led_3_off();

    // switch (layer)
    // {
    // case LAYER_STENO:
    //     ergodox_right_led_1_on();
    //     break;
    // case LAYER_FN:
    //     ergodox_right_led_2_on();
    //     break;
    // default:
    //     break;
    // }
    // 
    // if (!can_stroke())
    // {
    //     ergodox_right_led_3_on();
    // }
}