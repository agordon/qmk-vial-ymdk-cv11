#!/bin/sh

date=$(date +%F-%H%M%S)
file="firmware-dump-$date.bin"

openocd -c "set FLASH_SIZE 0x20000" \
        -f interface/stlink.cfg  -f target/stm32f1x.cfg  \
        -c "dump_image $file 0x08000000 0x20000; shutdown"
