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
    calc->expression_split = ft_split(expr, " ");

    int i = 0;
    int k = 0;
    char **prom = (char **)malloc(sizeof(char *) * ft_strlen(expr) + 1); // чтобы отделить '(' от "(a", полученное в результате ft_split(str, " ")

    while (calc->expression_split[i])
    {
        char *symbol = calc->expression_split[i];
        if (is_in_string(symbol, "(") && ft_strlen(symbol) > 1)
        {
            prom[k] = "(";
            k++;
            prom[k] = ft_split(symbol, "(")[1];
            k++;
        }
        else if (is_in_string(symbol, ")") && ft_strlen(symbol) > 1)
        {
            prom[k] = ft_split(symbol, ")")[0];
            k++;
            prom[k] = ")";
            k++;
        }
        else
        {
            prom[k] = symbol;
            k++;
        }
        i++;
    }
    calc->expression_split = prom;
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