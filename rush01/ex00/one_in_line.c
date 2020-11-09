#include "sudoku.h"

t_bool one_in_str(char *line, char el)
{
    int i = 0;
    int count = 0;
    while (line[i])
    {
        if (el == line[i])
        {
            count++;
        }
        else if (count > 1)
            return FALSE;
        i++;
    }
    return TRUE;
}