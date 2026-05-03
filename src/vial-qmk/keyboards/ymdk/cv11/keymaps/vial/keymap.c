// SPDX-License-Identifier: BSD-2-Clause
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE,           // Rotary Encoder Button
        KC_ESC,            // Top-Right Key (right of encoder)

        // 3x3 Grid
        KC_1, KC_2,  KC_3,  // Top Row: 1, 2, 3
        KC_4, KC_5,  KC_6,  // Middle Row: 4, 5, 6
        KC_7, KC_8,  KC_9   // Bottom Row: 7, 8, 9
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

led_config_t g_led_config = { {
    // Key Matrix to LED Index Mapping — 1x11 direct matrix
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
}, {
    // Physical positions: X 0-224, Y 0-64
    {0, 0},            {60, 0},       // Encoder btn (0), standalone key (1)
    {0, 21}, {30, 21}, {60, 21},      // Top row    (2-4)
    {0, 42}, {30, 42}, {60, 42},      // Middle row (5-7)
    {0, 64}, {30, 64}, {60, 64}       // Bottom row (8-10)
}, {
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
} };
