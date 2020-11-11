#include "sudoku.h"

t_bool one_in_line(t_sudoku *sudoku, char number, int nb_line)
{
    int i = nb_line;
    int j = 0;
    while (sudoku[i].point)
    {
        if (number == sudoku[i].point[j])
            return FALSE;
        j++;
    }
    return TRUE;
}