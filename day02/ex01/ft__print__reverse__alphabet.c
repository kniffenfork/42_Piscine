//
// Created by Алексей Фомин on 16.10.2020.
//

#include <stdio.h>

void ft__print__alphabet(void) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 26; alphabet[i] >= 0; i--) {
        putchar(alphabet[i]);
    }
}

