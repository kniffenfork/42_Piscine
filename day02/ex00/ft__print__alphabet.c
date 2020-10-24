#include <zconf.h>
#include <string.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}


int ft_putstr(char *str)
{
    write(1, str, strlen(str));
    return 0;
}

void ft__print__alphabet(void)
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    ft_putstr(alphabet);
}


int main()
{
    ft__print__alphabet();
    return 0;
}