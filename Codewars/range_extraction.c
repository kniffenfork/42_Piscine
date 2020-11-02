#include <stdio.h>
#include <stdlib.h>

#include <zconf.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_power(int n, int k)
{
    int j = n;
    if (k == 0)
        return 1;
    for (int i = 1; i<k; i++){
        n *= j;
    }
    return n;
}

void ft_putnbr(int c)
{
    int flag = 0;
    if (c < 0)
    {
        flag = 1;
        c *= -1;
    }
    int num = c;
    int length_of_int = 0, prom;
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


void range_extraction(const int *args, int size)
{

}


int main()
{
    int str[] =  {0, 1, 2, 5, 3, 4, 5, 6, 7, 8, 9, 0};
    range_extraction(str, 10);
}