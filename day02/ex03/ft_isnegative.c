#include <stdio.h>

void ft_is_negative(int n){
    if (n >= 0)
        putchar('P');
    else
        putchar('N');
}

int main(){
    ft_is_negative(9);
    return 0;
}