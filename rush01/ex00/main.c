#include "sudoku.h"

int main(int arc, char **argv)
{
    t_sudoku *ans = fill_sudoku_structure(arc, argv);
    show_sudoku(ans);
}