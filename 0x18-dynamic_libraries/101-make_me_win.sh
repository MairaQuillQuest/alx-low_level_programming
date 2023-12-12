#!/bin/bash
echo -e '#include <stdio.h>\n#include <stdlib.h>\nint rand(void) { return 9; }' > /tmp/libhack.c
gcc -shared -o /tmp/libhack.so /tmp/libhack.c
LD_PRELOAD=/tmp/libhack.so
