// SPDX-License-Identifier: BSD-2-Clause
#include QMK_KEYBOARD_H

// To have a KEYMAP that sends BOTH regular keys (KC_*)
// and midi keys (MI_*) we need "MIDI_ADVANCED" mode.
// see "config.h"
#if defined(MIDI_ENABLE) && defined(MIDI_ADVANCED)
    // All good!
#else
    #error MIDI_ADVANCED is not ENABLED.
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        QK_MIDI_NOTE_C_0,           // Rotary Encoder Button (Note 0)
        QK_MIDI_NOTE_C_SHARP_0,     // Top-Right Key (Note 1)

        // 3x3 Grid (Notes 2 through 10)
        QK_MIDI_NOTE_D_0,       QK_MIDI_NOTE_D_SHARP_0, QK_MIDI_NOTE_E_0,  // Row 1
        QK_MIDI_NOTE_F_0,       QK_MIDI_NOTE_F_SHARP_0, QK_MIDI_NOTE_G_0,  // Row 2
        QK_MIDI_NOTE_G_SHARP_0, QK_MIDI_NOTE_A_0,       QK_MIDI_NOTE_A_SHARP_0 // Row 3
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(QK_MIDI_NOTE_B_0, QK_MIDI_NOTE_C_1) }
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
