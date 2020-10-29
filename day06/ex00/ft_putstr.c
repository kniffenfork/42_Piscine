#include <zconf.h>

int strlength(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
int ft_putstr(char *str)
{
    write(1, str, strlength(str));
    return 0;
}
