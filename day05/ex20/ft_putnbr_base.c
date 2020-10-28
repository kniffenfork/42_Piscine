#include <zconf.h>
#include <stdio.h>

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
    for (int i = 1; i < k; i++)
        n *= j;
    return n;
}

int ft_sqrt(int nb)
{
    int res = nb;
    if (nb >= 0)
    {
        if (nb == 0)
            return 1;
        else if (nb == 1)
            return nb;
        else
        {
            for (int i = 0; i < 1000; i++)
            {
                res = (res + nb / res) >> 1;
            }
        }
    }
    else
        return -1;

    return res;
}

void decimal_to_binary(int nbr)
{
    int len = 1;
    int prom = 2;
    while (prom <= nbr)
    {
        prom *= 2;
        len++;
    }

    for(int i = len - 1; i >= 0; --i)
    {
        ft_putchar(((nbr >> i) & 1) + '0');
    }
}

void binary_to_decimal(int nbr, char *chars)
{
    for (int i = 0; )
}
/*
void ft_putnbr_base(int nbr, char *base)
{

}
 */

int main()
{
    decimal_to_binary(23);
}