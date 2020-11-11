#include "sudoku.h"

t_bool one_in_stolb(t_sudoku *sudoku, char number, int nb_stolb)
{
    int i = nb_stolb;
    int j = 0;
    while (j != 10)
    {
        if (number == sudoku[j].point[i])
            return FALSE;
        j++;
    }
    return TRUE;
}