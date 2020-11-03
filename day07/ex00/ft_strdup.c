#include "../../day06/ex00/include/libft.h"
#include <stdlib.h>

char *ft_strdup(char *str)
{
    char *p;
    p = malloc((ft_strlen(str) + 1) * sizeof(char));
    ft_strcpy(p, str);
    return p;
}
int main()
{
    char str[] = "abcdefg";
    char *i_str;
    i_str = ft_strdup(str);
    ft_putstr(i_str);
    ft_putchar('\n');
}