#!/bin/sh

set -e

die()
{
   base=$(basename "$0")
   echo "$base: error: $*" >&2
   exit 1
}

file="$1"
test -e "$file" || die "file '$1' not found"

expr "$file" : '^[_0-9a-zA-Z.]*$' > /dev/null \
   || die "file '$1' contains disallowed characters"

openocd -c "set FLASH_SIZE 0x20000" \
        -f interface/stlink.cfg  -f target/stm32f1x.cfg  \
        -c "program $1 0x08004000 verify reset exit"
