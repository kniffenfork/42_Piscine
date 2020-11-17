#include "calc.h"

int main(int ac, char **av)
{
    t_calc *calculate = fill_calculator_structure(ac, av);

    ft_putnbr(calculate_expression(calculate));
    ft_putchar('\n');
}