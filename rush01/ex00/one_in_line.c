#include "sudoku.h"

t_bool one_in_line(t_sudoku *sudoko, char el, int nb_line)
{
    int i = nb_line;
    int j = 0;
    int count = 0;
    while (sudoko[i].lines[j])
    {
        if (el == *sudoko[i].lines[j])
        {
            count++;
        }
        else if (count > 1)
            return FALSE;
        j++;
    }
    return TRUE;
}