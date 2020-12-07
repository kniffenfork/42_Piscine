#include "ft.h"

int             FT_is_digit(char symbol)
{
    if (symbol >= 48 && symbol <= 57)
        return 1;
    else
        return 0;
}