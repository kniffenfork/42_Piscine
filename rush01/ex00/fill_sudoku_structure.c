#include "sudoku.h"


t_sudoku *fill_sudoku_structure(int ac, char **av)
{
    t_sudoku 	*sudoku;
    int	        i;
    int         j;

    sudoku = (t_sudoku *)malloc(sizeof(t_sudoku) * (ac + 1));

    i = 0;
    j = 1;

    while (j <= ac)
    {
        sudoku[i].lines = malloc(10);
        sudoku[i].columns = malloc(10);
        sudoku[i].count_of_parents = malloc(10);
        sudoku[i].lines = av[i + 1];
        sudoku[i].parents = (char **)malloc(sizeof(char *) * 10);
        i++;
        j++;
    }
    sudoku[i].lines = NULL;

    for (i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            sudoku[i].parents[j] = (char *)malloc(10);
            sudoku[j].columns[i] = sudoku[i].lines[j];
            sudoku[i].count_of_parents[j] = '0';
        }
    }
    sudoku[9].parents[9] = NULL;

    return (sudoku);
}
