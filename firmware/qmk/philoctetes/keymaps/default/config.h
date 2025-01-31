#pragma once

// This is default
//#define RP2040_FLASH_W25Q080

// HANDEDNESS OPTIONS
#define SPLIT_HAND_PIN GP23
//#define MASTER_LEFT

// DEBUG OPTIONS
//#define DEBUG_MATRIX_SCAN_RATE
//#define DEBUG_SERIAL


//SERIAL OPTIONS
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
// DATA sync options
// most/all of these are not needed
#define RGBLIGHT_SPLIT
#define RBGLED_SPLIT { 27, 27 }
//#define SPLIT_LAYER_STATE_ENABLE
//#define SPLIT_LED_STATE_ENABLE
//#define SPLIT_MODS_ENABLE
//#define SPLIT_OLED_ENABLE
//#define SPLIT_ACTIVITY_ENABLE

// MY CUSTOM CONFIG KEY SECTION
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define TAPPING_TERM 190
#define TAPPING_TERM_PER_KEY
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TAP_TIMEOUT 10000

// BEGIN mousekey config
// Delay between pressing a movement key
// and cursor movement
#define MOUSEKEY_DELAY 10

// Time between cursor movements in milliseconds
#define MOUSEKEY_INTERVAL    20

// Step size
#define MOUSEKEY_MOVE_DELTA  8 	// Step size

// MAXIMUM cursor speed at which acceleration stops
#define MOUSEKEY_MAX_SPEED 	 10

// Time until maximum cursor speed is reached
#define MOUSEKEY_TIME_TO_MAX 30

// Delay between pressing a wheel key and wheel movement
#define MOUSEKEY_WHEEL_DELAY 10

// Time between wheel movements
#define MOUSEKEY_WHEEL_INTERVAL 80

// Wheel movement step size
#define MOUSEKEY_WHEEL_DELTA 1

// Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_MAX_SPEED 8

// Time until maximum scroll speed is reached
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40





// BEGIN RGB SECTION
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_RETAIN_VAL
//#define RGBLIGHT_KEYPRESSES // reacts to keypresses
//#define RGBLIGHT_KEYRELEASES // reacts to releases
//#define RGBLIGHT_TIMEOUT 300000 // in milliseconds
//#define RGBLIGHT_SLEEP // turn off effects when suspended
//#define RGBLIGHT_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // increases keyboard responsiveness
//#define RGBLIGHT_LED_FLUSH_LIMIT 16 // in ms, 16 ms ~ 60 fps
//#define RGBLIGHT_MAXIMUM_BRIGHTNESS 255 // 200 out of 255
//#define RGBLIGHT_DEFAULT_ON true
//#define RGBLIGHT_DEFAULT_HUE 0
//#define RGBLIGHT_DEFAULT_SAT 255
//#define RGBLIGHT_DEFAULT_VAL RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_DEFAULT_SPD 127
#define RGBLIGHT_DEFAULT_ON true
//#define RGBLIGHT_DEFAULT_FLAGS LED_FLAG_ALL
//#define RGBLIGHT_DISABLE_KEYCODES // disables control of rgb matrix by keycodes (must use code functions to control the feature)
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_SPD_STEP 10




//  BEGIN OLED SECTION
#ifdef OLED_ENABLE
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define OLED_TRANSPORT i2c
#define OLED_DRIVER ssd1306
#define OLED_BRIGHTNESS 185
#define OLED_UPDATE_INTERVAL 50
//#define SPLIT_OLED_ENABLE

#endif
