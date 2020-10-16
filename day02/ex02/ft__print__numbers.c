#include <stdio.h>

void ft_print_numbers(void){
    char digits[] = "0123456789";
    for (int i=0; digits[i] != '\0'; i++){
        putchar(digits[i]);
    }
}
,