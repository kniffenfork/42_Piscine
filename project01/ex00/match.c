#include "../proj01.h"


int match(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return 1;
    else if (*s1 == '\0' && *s2 == '*')
        return match(s1, s2 + 1);
    else if (*s1 == *s2 && *s2 != '\0')
        return match(s1 + 1, s2 + 1);
    else if (*s2 == '*')
        return (match(s1 + 1, s2) || match(s1, s2 + 1));

    return 0;
}
int main()
{
    ft_putchar(match("main.c", "m*n.c") + '0');
}