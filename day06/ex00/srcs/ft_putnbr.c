#include <stdlib.h>

void ft_putchar(char c);

int ft_power(int n, int k);

void ft_putnbr(int c)
{
    if (c == 0)
    {
        ft_putchar(c + '0');
        return;
    }

    int flag = 0;

    if (c < 0)
    {
        flag = 1;
        c *= -1;
    }

    int num = c;
    int length_of_int = 0;
    int prom;

    while (c != 0){
        c /= 10;
        length_of_int++;
    }

    if (flag == 1)
        ft_putchar('-');

    for (int i = length_of_int - 1; i >= 0; i--)
    {
        prom = (num/(ft_power(10, i))) % 10;
        ft_putchar(prom + '0');
    }
}
