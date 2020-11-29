#include "ft.h"

int             match(char *s1, char *s2)
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

int             str_comparison(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] == s2[i] && (s1[i] && s2[i]))
    {
        i++;
    }

    if (s1[i] > s2[i])
        return 1;

    if (s1[i] < s2[i])
        return -1;

    return 0;
}