#include <zconf.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

int power(int n, int k)
{
    int j = n;
    if (k == 0)
        return 1;
    for (int i = 1; i<k; i++){
        n *= j;
    }
    return n;
}

void ft_putnbr(int c){
    int num = c;
    int length_of_int = 0, prom;// заебал на одной строке 2 переменные обьявлять, за такое пиздят, особенно
    							// с промежуточной инициализацией
    while (c != 0){
        c /= 10;
        length_of_int++;
    }
    for (int i = length_of_int - 1; i >= 0; i--)
    {
        prom = (num / (power(10, i))) % 10;
        ft_putchar(prom + '0');
    }
}

