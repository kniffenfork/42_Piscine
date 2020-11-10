#include "sudoku.h"

t_sudoku *fill_sudoku_structure(int ac, char **av)
{
    t_sudoku 	*tab;
    int	i = 0;
    int	j;
    tab = (t_sudoku *)malloc(sizeof(t_sudoku) * (ac + 1));
    while (i < ac)
    {
        j = 0;
        while (av[i][j] != '\0')
            j++;
        tab[i].lines = ft_split_whitespaces(av[i]);
        tab[i].point = av[i];
        ++i;
    }
    tab[i].point = NULL;
    return (tab);
}