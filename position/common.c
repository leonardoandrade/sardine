#include "common.h"
#include <stdio.h>
#include <stdlib.h>

void panic(char * message) {
    printf("PANIC: %s\n", message);
    exit(1);
}