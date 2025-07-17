 // Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "eeconfig.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [0] = LAYOUT_ortho_3x8(
  KC_A, KC_B, KC_C, KC_D, KC_N, KC_M, KC_A, KC_B, 
  KC_E, KC_F, KC_G, KC_H, _______, _______, KC_C, KC_D,
  KC_I, KC_J, KC_K, KC_L, _______, _______, _______, _______
)

};



bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        uint16_t kc = dynamic_keymap_get_keycode(0,0, clockwise ? 6 : 7);
        tap_code16(kc);
    } else if (index == 1) {
        uint16_t kc = dynamic_keymap_get_keycode(0,1, clockwise ? 6 : 7);
        tap_code16(kc);
    }
    return false;
}


led_config_t g_led_config = {
  {
    // Key Matrix to LED Index
    { 0, 1, 2, 3 },
    { 7, 6, 5, 4 },
    { 8, 9,10,11 }
  },
  {
    // LED Index to Physical Position
    { 0, 0 },    // LED 0
    { 74, 0 },   // LED 1
    {149, 0 },   // LED 2
    {224, 0 },   // LED 3
    {224, 32 },  // LED 4
    {149,32 },   // LED 5
    { 74,32 },   // LED 6
    { 0,32 },    // LED 7
    { 0, 64 },   // LED 8
    { 74,64 },   // LED 9
    {149,64 },   // LED10
    {224,64 }    // LED11
  },
  {
    // LED Index to Flag
    4,4,4,4,4,4,4,4,4,4,4,4
  }
};


uint8_t current_theme = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_MOD:
            if (record->event.pressed) {
                current_theme++;
                if (current_theme > 9) {  // number of themes minus one
                    current_theme = 0;
                }
                eeconfig_update_user(current_theme);  // save to EEPROM
            }
            return false; // prevent further processing
    }
    return true;
}



bool rgb_matrix_indicators_kb(void) {
    switch (current_theme) {
        case 0: // Red
            for (int i = 0; i < 12; i++) rgb_matrix_set_color(i, 255, 0, 0);
            break;
        case 1: // Green
            for (int i = 0; i < 12; i++) rgb_matrix_set_color(i, 0, 255, 0);
            break;
        case 2: // Blue
            for (int i = 0; i < 12; i++) rgb_matrix_set_color(i, 0, 0, 255);
            break;
        case 3: // Yellow
            for (int i = 0; i < 12; i++) rgb_matrix_set_color(i, 255, 255, 0);
            break;
        case 4: // Cyan
            for (int i = 0; i < 12; i++) rgb_matrix_set_color(i, 0, 255, 255);
            break;
        case 5: // Magenta
            for (int i = 0; i < 12; i++) rgb_matrix_set_color(i, 255, 0, 255);
            break;
        case 6: // White
            for (int i = 0; i < 12; i++) rgb_matrix_set_color(i, 255, 255, 255);
            break;
        case 7: // Orange
            for (int i = 0; i < 12; i++) rgb_matrix_set_color(i, 255, 128, 0);
            break;
        case 8: // Purple
            for (int i = 0; i < 12; i++) rgb_matrix_set_color(i, 128, 0, 128);
            break;
        case 9: // Pink
            for (int i = 0; i < 12; i++) rgb_matrix_set_color(i, 255, 105, 180);
            break;
    }
    return rgb_matrix_indicators_user();
}

void keyboard_post_init_user(void) {
    current_theme = eeconfig_read_user();  // load saved theme
    if (current_theme > 9) current_theme = 0; // safety: if EEPROM has garbage
}

