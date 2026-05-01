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
        KC_Z,             // Rotary Encoder Button
        QK_BOOT,          // Top-Right Key (right of the Rotary Encoder)
        KC_1, KC_2, KC_3, // Top Row
        KC_D, KC_5, KC_6, // Middle Row
        MI_C, KC_8, QK_UNDERGLOW_MODE_NEXT // Bottom Row
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif
