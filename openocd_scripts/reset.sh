#!/bin/sh

set -e


openocd -c "set FLASH_SIZE 0x20000" \
        -f interface/stlink.cfg  -f target/stm32f1x.cfg  \
        -c "init; reset; exit"
