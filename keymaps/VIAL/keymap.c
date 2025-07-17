 // Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "eeconfig.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [0] = LAYOUT(
  KC_A, KC_B, KC_C, KC_D, KC_A, KC_B,
  KC_E, KC_F, KC_G, KC_H, _______, _______,
  KC_I, KC_J, KC_K, KC_L, _______, _______
)

};



#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }
    //                  Encoder 1                                     Encoder 2
};
#endif


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

