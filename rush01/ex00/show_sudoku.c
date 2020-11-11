#include "sudoku.h"

void show_sudoku(t_sudoku *par)
{
    int i = 1;
    while (par[i].point)
    {
        int j = 0;
        while (par[i].point[j])
        {
            ft_putchar(par[i].point[j]);
            ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}