#include "sudoku.h"

void show_sudoku(t_sudoku *par)
{
    int i = 1;
    while (par[i].point)
    {
        if (par[i + 1].point)
        {
            ft_putstr(par[i].point);
            ft_putchar('\n');
        }
        else
            ft_putstr(par[i].point);
        i++;
    }
    ft_putchar('\n');
}