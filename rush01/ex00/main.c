#include "sudoku.h"

int main(int arc, char **argv)
{
    t_sudoku *ans = fill_sudoku_structure(arc, argv);
    show_sudoku(ans);
    ft_putchar('\n');

    if (one_in_stolb(ans, '6', 3) == TRUE)
    {
        ft_putstr("TRUE");
    }
    else
        ft_putstr("FALSE");

    ft_putchar('\n');
    ft_putnbr(one_in_square(ans, '1', 5, 5));
}

// ./sudoku "..3.92..." "4...3..1." "27......." ".1.3....8" ".5.167.3." "3....8.6." ".......53" ".3..8...9" "...62.1.."

