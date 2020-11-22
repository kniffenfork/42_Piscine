#include <zconf.h>

int ft_strlen(char *str);

int ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
    return 0;
}
