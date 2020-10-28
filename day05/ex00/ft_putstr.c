#include <zconf.h>

int strlength(char *str)
{
    int i = 0;//TODO: переписать на while
    while (str[i] != '\0')
        i++;
    return i;

}
int ft_putstr(char *str)
{
    write(1, str, strlength(str));
    return 0;
}
