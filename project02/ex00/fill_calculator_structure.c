#include "calc.h"

t_calc *fill_calculator_structure(int ac, char **av)
{
    t_calc      *calc;

    if (ac < 2 || ft_strlen(av[1]) == 0)
    {
        ft_putstr("ERROR");
        ft_putchar('\n');
        return 0;
    }

    char        *expr = av[1];

    calc = (t_calc *)malloc(ft_strlen(expr) * sizeof(t_calc) + 1);

    calc->symbol = ft_split_whitespaces(av[1]);
    calc->size_of_expression = ft_strlen(expr);

    calc->prior_of_plus = 1;
    calc->prior_of_minus = 1;
    calc->prior_of_multiplication = 2;
    calc->prior_of_division = 2;
    calc->prior_of_remainder = 2;

    return calc;
}