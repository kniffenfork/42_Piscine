#include <zconf.h>


int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

void ft_putstr(char *str)
{
    for (int i=0; str[i] != '\0'; i++)
        ft_putchar(str[i]);
}
