#include <stdio.h>

int rm(char arg[100]) {
    remove(arg);
    return 0;
}