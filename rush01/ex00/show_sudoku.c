#include "sudoku.h"

void show_sudoku(t_sudoku *par)
{
    int i = 0;
    while (par[i].lines)
    {
        int j = 0;
        while (par[i].lines[j])
        {
            ft_putchar(par[i].lines[j]);
            ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}