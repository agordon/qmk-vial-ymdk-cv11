// SPDX-License-Identifier: BSD-2-Clause
#include QMK_KEYBOARD_H
#include <ch.h>
#include "print.h"
#include "timer.h"

#if defined(MIDI_ENABLE) && defined(MIDI_ADVANCED)
    // All good!
#else
    #error MIDI_ADVANCED is still not reaching the C code.
#endif

/*
 * DAPBoot enters DFU mode when *0x20004000 == 0x544F4F42 ("BOOT").
 * Any other value causes DAPBoot to boot the app. SRAM survives NVIC_SystemReset.
 * DAPBoot drives D+ low itself, so no need to do it here.
 */
void bootloader_jump(void) {
    *((volatile uint32_t *)0x20004000) = 0x544F4F42;  /* "BOOT" — DAPBoot DFU magic */
    NVIC_SystemReset();
}

void housekeeping_task_user(void) {
    static uint32_t last_hb = 0;

    if (timer_elapsed32(last_hb) >= 5000) {
        last_hb = timer_read32();
        uprintf("CV11 alive, v40 uptime=%lums\n", last_hb);
    }
}
