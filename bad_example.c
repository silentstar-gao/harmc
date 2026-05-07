#include <stdio.h>

int bad_func(int flag) {
    int value;         
    if (flag > 0) {
        value = 123;
    }
    return value;       
}