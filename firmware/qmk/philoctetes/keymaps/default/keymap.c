// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#ifdef OLED_ENABLE
#include "display_status.c"
#endif
// BEGIN LAYOUG
enum layer_names {
    _COLMAK,
    _NAV,
    _SYMBOL_QA,
    _NUM,
    _SYMBOL,
    _FUNCTION,
    _NUMPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLMAK] = LAYOUT_split_3x6_3(

KC_ESC,  KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,      KC_J, KC_L,         KC_U,         KC_Y,         KC_SCLN,      KC_BSPC,
KC_QUOT, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, 		KC_M, RSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), RGUI_T(KC_O), KC_ENT,
KC_LSFT, KC_X,         KC_C,         KC_D,         KC_V,         KC_Z, 		KC_K, KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_RSFT,
                       LT(_NAV , KC_BSPC), LT(_SYMBOL_QA, KC_SPC),  LT(_NUMPAD, KC_DEL),		LT(_FUNCTION,KC_ESC),  LT(_NUM,KC_SPC), LT(_SYMBOL,KC_TAB)
),

[_NAV] = LAYOUT_split_3x6_3(

KC_ESC, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  KC_PSCR, 		KC_CAPS, KC_PSCR, KC_VOLD, KC_VOLU, KC_MUTE, KC_BSPC,
KC_QUOT, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BRIU, 		KC_PGUP, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS,
KC_LSFT, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, KC_BRID, 		KC_PGDN, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_RSFT,
                        KC_BSPC,   KC_NO,  KC_DEL,		   KC_ESC,  KC_SPC, KC_TAB
 ),

[_SYMBOL_QA] = LAYOUT_split_3x6_3(

KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 		KC_PLUS, KC_LPRN, KC_LCBR, KC_LBRC, KC_PIPE, KC_BSPC,
KC_QUOT, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, 	    KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS, KC_TRNS,
KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 		KC_MINS, KC_UNDS, KC_LT,   KC_GT,   KC_SLSH, KC_TRNS,
                        KC_NO, KC_0, KC_TRNS, 		 KC_TRNS, KC_TRNS, KC_TRNS
 ),

[_NUM] = LAYOUT_split_3x6_3(

KC_ESC,  KC_LBRC, KC_7, KC_8, KC_9, KC_PLUS, 		KC_PLUS, KC_LPRN, KC_LCBR, KC_LBRC, KC_PIPE, KC_BSPC,
KC_QUOT, KC_QUOT, KC_4, KC_5, KC_6, KC_EQL, 		KC_ENT,  KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI, KC_TRNS,
KC_LSFT, KC_GRV,  KC_1, KC_2, KC_3, KC_MINS, 		KC_MINS, KC_UNDS, KC_COMM,   KC_DOT,   KC_SLSH, KC_TRNS,
                         KC_BSPC, KC_0, KC_TRNS, 		 KC_TRNS, KC_NO, KC_TRNS
 ),

[_SYMBOL] = LAYOUT_split_3x6_3(

KC_ESC, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, 		KC_CAPS, KC_PSCR, KC_VOLD, KC_VOLU, KC_MUTE, KC_BSPC,
KC_QUOT, KC_QUOT, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, 		KC_PGUP, KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI, KC_TRNS,
KC_LSFT, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, 		KC_PGDN, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS,
                         KC_BSPC, KC_0, KC_TRNS, 		KC_TRNS, KC_SPC, KC_NO
 ),

[_FUNCTION] = LAYOUT_split_3x6_3(

KC_ESC, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, 		UG_SPDD, UG_NEXT, UG_VALU, UG_HUEU, UG_SATU, QK_BOOT,
KC_LNG2, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL, 		UG_TOGG, KC_RSFT, KC_LCTL, KC_LALT, KC_LGUI, EE_CLR,
KC_LNG1, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS, 		UG_SPDU, UG_PREV, UG_VALD, UG_HUED, UG_SATD, KC_TRNS,
                        KC_BSPC, KC_DEL, KC_TRNS, 		 KC_NO, KC_SPC, KC_TAB
 ),

[_NUMPAD] = LAYOUT_split_3x6_3(

KC_ESC,  KC_LBRC, KC_7, KC_8, KC_9, KC_PLUS, 		KC_KP_PLUS, KC_P7, KC_P8, KC_P9, KC_KP_ASTERISK, KC_BSPC,
KC_QUOT, KC_QUOT, KC_4, KC_5, KC_6, KC_EQL, 		KC_KP_EQUAL, KC_P4, KC_P5, KC_P6, KC_KP_SLASH, KC_PENT,
KC_LSFT, KC_GRV,  KC_1, KC_2, KC_3, KC_MINS, 		KC_KP_MINUS, KC_P1, KC_P2,   KC_P3,   KC_PDOT, KC_PCMM,
                         KC_BSPC, KC_0, KC_TRNS, 		 KC_TRNS, KC_KP_0, KC_TRNS
 )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3, KC_SPC):
            return TAPPING_TERM - 30;
        case LCTL(KC_E):
            return TAPPING_TERM - 35;
        case LCTL(KC_N):
            return TAPPING_TERM - 40;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
            //      case LGUI_T(KC_A):
            //         return true;
            // case LALT_T(KC_R):
            //   return true;
            //        case LCTL_T(KC_S):
            //           return true;
        case LSFT_T(KC_T):
            return true;
        // case LSFT_T(KC_N):
        //    return true;
        case LCTL_T(KC_N):
            return true;
        // case LALT_T(KC_I):
        //    return true;
        // case LGUI_T(KC_O):
        //   return true;
        // case LT(2, KC_TAB):
        //   return true;
        // case LT(3, KC_SPC):
        //    return true;
        default:
            return false;
    }
}


// END LAYOUT


// HSV_AZURE      #99F5FF
// HSV_BLACK        #000000
// HSV_BLUE         #0000FF
// HSV_CHARTREUSE   #80FF00
// HSV_CORAL        #FF7C4D
// HSV_CYAN         #00FFFF
// HSV_GOLD         #FFD900
// HSV_GOLDENROD    #D9A521
// HSV_GREEN        #00FF00
// HSV_MAGENTA      #FF00FF
// HSV_ORANGE       #FF8000
// HSV_PINK         #FF80BF
// HSV_PURPLE       #7A00FF
// HSV_RED          #FF0000
// HSV_SPRINGGREEN  #00FF80
// HSV_TEAL         #008080
// HSV_TURQUOISE    #476E6A
// HSV_WHITE        #FFFFFF
// HSV_YELLOW       #FFFF00
// HSV_OFF

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM rgb_capslock[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {33, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);

const rgblight_segment_t PROGMEM rgb_1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 0, HSV_OFF}

);

// _NAV
const rgblight_segment_t PROGMEM rgb_2[] = RGBLIGHT_LAYER_SEGMENTS(
    // LEFT
    {6, 1, HSV_BLUE}, // thumb
    {7, 6, HSV_TEAL}, // col1 to 2

    {13, 1, HSV_BLUE}, // thumb
    {14, 1, HSV_BLUE}, // thumb
    {15, 9, HSV_TEAL}, // col3 to col5

    {24, 3, HSV_BLUE}, // col6

    // RIGHT
   {33, 1, HSV_BLUE}, //thumb
   {34, 9, HSV_TEAL}, //col1 to 2

   {40, 1, HSV_BLUE}, //thumb
   {41, 1, HSV_BLUE}, //thumb
   {42, 9, HSV_TEAL}, // col3 to 5

   {51, 3, HSV_BLUE} // col6
);


// _SYMBOL_QA
const rgblight_segment_t PROGMEM rgb_3[] = RGBLIGHT_LAYER_SEGMENTS(
    // LEFT
    {6, 1, HSV_GOLDENROD}, // thumb
    {7, 6, HSV_PURPLE}, // col1 to 2

    {13, 1, HSV_GOLDENROD}, // thumb
    {14, 1, HSV_GOLDENROD}, // thumb
    {15, 9, HSV_PURPLE}, // col3 to col5

    {24, 3, HSV_GOLDENROD}, // col6

    // RIGHT
   {33, 1, HSV_GOLDENROD}, //thumb
   {34, 9, HSV_PURPLE}, //col1 to 2

   {40, 1, HSV_GOLDENROD}, //thumb
   {41, 1, HSV_GOLDENROD}, //thumb
   {42, 9, HSV_PURPLE}, // col3 to 5

   {51, 3, HSV_PURPLE} // col6
);

// _NUM
const rgblight_segment_t PROGMEM rgb_4[] = RGBLIGHT_LAYER_SEGMENTS(
    // LEFT
    {6, 1, HSV_GOLDENROD}, // thumb
    {7, 6, HSV_BLUE}, // col1 to 2

    {13, 1, HSV_GOLDENROD}, // thumb
    {14, 1, HSV_GOLDENROD}, // thumb
    {15, 9, HSV_BLUE}, // col3 to col5

    {24, 3, HSV_GOLDENROD}, // col6

    // RIGHT
   {33, 1, HSV_GOLDENROD}, //thumb
   {34, 9, HSV_BLUE}, //col1 to 2

   {40, 1, HSV_GOLDENROD}, //thumb
   {41, 1, HSV_GOLDENROD}, //thumb
   {42, 9, HSV_BLUE}, // col3 to 5

   {51, 3, HSV_BLUE} // col6
);

// _SYMBOL
const rgblight_segment_t PROGMEM rgb_5[] = RGBLIGHT_LAYER_SEGMENTS(
    // LEFT
    {6, 1, HSV_GOLDENROD}, // thumb
    {7, 6, HSV_AZURE}, // col1 to 2

    {13, 1, HSV_GOLDENROD}, // thumb
    {14, 1, HSV_GOLDENROD}, // thumb
    {15, 9, HSV_AZURE}, // col3 to col5

    {24, 3, HSV_GOLDENROD}, // col6

    // RIGHT
   {33, 1, HSV_GOLDENROD}, //thumb
   {34, 9, HSV_AZURE}, //col1 to 2

   {40, 1, HSV_GOLDENROD}, //thumb
   {41, 1, HSV_GOLDENROD}, //thumb
   {42, 9, HSV_AZURE}, // col3 to 5

   {51, 3, HSV_AZURE} // col6
);

// _FUNCTION
const rgblight_segment_t PROGMEM rgb_6[] = RGBLIGHT_LAYER_SEGMENTS(
    // LEFT
    {6, 1, HSV_RED}, // thumb
    //{7, 6, HSV_TEAL}, // col1 to 2

    {13, 1, HSV_RED}, // thumb
    {14, 1, HSV_RED}, // thumb
    //{15, 9, HSV_TEAL}, // col3 to col5

    //{24, 3, HSV_RED}, // col6

    // RIGHT
   {33, 1, HSV_RED}, //thumb
   //{34, 9, HSV_TEAL}, //col1 to 2

   {40, 1, HSV_RED}, //thumb
   {41, 1, HSV_RED} //thumb
   //{42, 9, HSV_TEAL}, // col3 to 5

   //{51, 3, HSV_TEAL} // col6
);

// _NUMPAD
const rgblight_segment_t PROGMEM rgb_7[] = RGBLIGHT_LAYER_SEGMENTS(
    // LEFT
    {6, 1, HSV_PINK}, // thumb
    {7, 6, HSV_SPRINGGREEN}, // col1 to 2

    {13, 1, HSV_PINK}, // thumb
    {14, 1, HSV_PINK}, // thumb
    {15, 9, HSV_SPRINGGREEN}, // col3 to col5

    {24, 3, HSV_PINK}, // col6

    // RIGHT
   {33, 1, HSV_PINK}, //thumb
   {34, 9, HSV_SPRINGGREEN}, //col1 to 2

   {40, 1, HSV_PINK}, //thumb
   {41, 1, HSV_PINK}, //thumb
   {42, 9, HSV_SPRINGGREEN}, // col3 to 5

   {51, 3, HSV_SPRINGGREEN} // col6
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_capslock, // layer 0
    rgb_1, // layer 1
    rgb_2,
    rgb_3,
    rgb_4,
    rgb_5,
    rgb_6,
    rgb_7
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _COLMAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
   // rgblight_set_layer_state(1, layer_state_cmp(state, _COLMAK));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYMBOL_QA));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(5, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(6, layer_state_cmp(state, _FUNCTION));
    rgblight_set_layer_state(7, layer_state_cmp(state, _NUMPAD));
    // doesn't work
    //rgblight_set_layer_state(0, my_led_state.caps_lock);
    return state;
}

void keyboard_post_init_user(void) {

    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
  // Customise these values to desired behaviour
  //debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

bool display_finished_my_init = false;

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (!display_finished_my_init) {
            // my own init section
            display_finished_my_init = true;
            clear_display();
        }
        display_my_layer_status();
    }
    return false;
}

#endif
