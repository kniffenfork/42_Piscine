#include "calc.h"

t_bool is_digit(char *symbol);

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
    calc->expression_split = ft_split(expr, " ");

    int i = 0;
    while (calc->expression_split[i])
    {
        i++;
    }

    calc->size_of_splitted_expression = i;

    calc->polish_notation = (char **)malloc((calc->size_of_splitted_expression * sizeof(char *))+ 1);

    i = 0;
    while (i < calc->size_of_splitted_expression)
    {
        calc->polish_notation[i] = malloc(ft_strlen(expr) + 1);
        i++;
    }

    return calc;
}