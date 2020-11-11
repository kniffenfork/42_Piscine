#include "sudoku.h"

int one_in_square(t_sudoku *sudoku, char number, int coord_line, int coord_el_in_line)
{
    int         i;
    int         j;

    // define the 3*3 square

    if ((coord_line + 1) % 3 == 0 || coord_line == 0)
        i = coord_line;
    else
    {
        i = (coord_line - 1);
    }
    if ((coord_el_in_line + 1) % 3 == 0 || coord_el_in_line == 0)
        j = coord_el_in_line;
    else
        j = (coord_el_in_line - 1);

    return i;
}