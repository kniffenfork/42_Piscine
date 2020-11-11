#include "sudoku.h"

t_sudoku *fill_sudoku_structure(int ac, char **av)
{
    t_sudoku 	*sudoku;
    int	        i;

    sudoku = (t_sudoku *)malloc(sizeof(t_sudoku) * (ac + 1));

    i = 0;

    while (i < ac)
    {
        sudoku[i].point = av[i];
        i++;
    }
    sudoku[i].point = NULL;

    return (sudoku);
}
