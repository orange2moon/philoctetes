#include "display_img.h"

#define CAPS_START 126
#define CAPS_END 114

#define L0_START 96
#define L0_END 110

#define L1_START 78
#define L1_END 91

#define L2_START 60
#define L2_END 74

#define L3_START 41
#define L3_END 56

#define L4_START 35
#define L4_END 21

#define L5_START 3
#define L5_END 18

#define LAYERS_START 3
#define LAYERS_END 110

#define ROW_TWO 128
#define ROW_THREE 256
#define ROW_FOUR 384
#define MY_OLED_BLACK 0x00

bool my_caps_word_status = false;
bool my_caps_lock_status = false;

uint8_t my_layer_status = 100;
bool my_caps_lock_cache = false;

void write_black(uint8_t start, uint8_t end) {
    for (int i = start; i < end; i++) {
        oled_write_raw_byte(MY_OLED_BLACK, i);
        oled_write_raw_byte(MY_OLED_BLACK, i + ROW_TWO);
        oled_write_raw_byte(MY_OLED_BLACK, i + ROW_THREE);
        oled_write_raw_byte(MY_OLED_BLACK, i + ROW_FOUR);
    }
}

void write_off(uint8_t start, uint8_t end) {
    for (int i = start; i < end; i++) {
        oled_write_raw_byte(pgm_read_byte(layers_img + i), i);
        oled_write_raw_byte(pgm_read_byte(layers_img + ROW_TWO + i), i + ROW_TWO);
        oled_write_raw_byte(pgm_read_byte(layers_img + ROW_THREE + i), i + ROW_THREE);
        oled_write_raw_byte(pgm_read_byte(layers_img + ROW_FOUR + i), i + ROW_FOUR);
    }
}

void write_on(uint8_t start, uint8_t end) {
    // each value ("0xff") is one byte
    for (int i = start; i < end; i++) {
        oled_write_raw_byte(~pgm_read_byte(layers_img + i), i);
        oled_write_raw_byte(~pgm_read_byte(layers_img + ROW_TWO + i), i + ROW_TWO);
        oled_write_raw_byte(~pgm_read_byte(layers_img + ROW_THREE + i), i + ROW_THREE);
        oled_write_raw_byte(~pgm_read_byte(layers_img + ROW_FOUR + i), i + ROW_FOUR);
    }
}

void clear_display(void){
    write_off(LAYERS_START, LAYERS_END);
}

void display_my_layer_status(void) {
    uint8_t my_curr_layer = get_highest_layer(layer_state);

    if (my_layer_status != my_curr_layer) {
        switch (my_layer_status) {
            case 0:
                write_off(L0_START, L0_END);
                break;
            case 1:
                write_off(L1_START, L1_END);
                break;
            case 2:
                write_off(L2_START, L2_END);
                break;
            case 3:
                write_off(L3_START, L3_END);
                break;
            case 4:
                write_off(L4_START, L4_END);
                break;
            case 5:
                write_off(L5_START, L5_END);
                break;
            default:
                break;
        }

        switch (my_curr_layer) {
            case 0:
                write_on(L0_START, L0_END);
                break;
            case 1:
                write_on(L1_START, L1_END);
                break;
            case 2:
                write_on(L2_START, L2_END);
                break;
            case 3:
                write_on(L3_START, L3_END);
                break;
            case 4:
                write_on(L4_START, L4_END);
                break;
            case 5:
                write_on(L5_START, L5_END);
                break;
            default:
                break;
        }
        my_layer_status = my_curr_layer;
    }

    my_caps_lock_status = host_keyboard_led_state().caps_lock;

    if (is_caps_word_on() != my_caps_word_status) {
        my_caps_word_status = is_caps_word_on();
        if (my_caps_word_status ^ my_caps_lock_status) {
            write_on(CAPS_START, CAPS_END);
        } else {
            write_black(CAPS_START, CAPS_END);
        }
    } else if ( my_caps_lock_status != my_caps_lock_cache) {
        my_caps_lock_cache = my_caps_lock_status;
        if (my_caps_word_status ^ my_caps_lock_status) {
            write_on(CAPS_START, CAPS_END);
        } else {
            write_black(CAPS_START, CAPS_END);
        }
    }
}
