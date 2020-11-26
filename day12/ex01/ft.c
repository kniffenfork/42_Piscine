#include "ft_cat.h"

t_bool is_in_string(char *string, char symbol)
{
    int i = 0;
    while (string[i])
    {
        if (symbol == string[i])
            return TRUE;
        i++;
    }
    return FALSE;
}