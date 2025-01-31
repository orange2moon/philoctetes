#include QMK_KEYBOARD_H
#pragma once

bool my_caps_word_status = false;
bool my_caps_lock_status = false;

uint8_t my_layer_status = 100;
bool my_caps_lock_cache = false;

void write_black(uint8_t start, uint8_t end);
void write_off(uint8_t start, uint8_t end);
void write_on(uint8_t start, uint8_t end);
void display_my_layer_status(void);
void clear_display(void);
