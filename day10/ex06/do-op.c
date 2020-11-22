#include "do-op.h"

int         check_for_possibility(int ac, char **av)
{

    if (ac != 4)
    {
        return error_number_of_arguments;
    }
    return 1;
}

int         ft_do_op(int ac, char **av)
{
    if (check_for_possibility(ac, av) == error_number_of_arguments)
    {
        return error_number_of_arguments;
    }

    else
    {
        char operation = av[2][0];
        int num1 = ft_atoi(av[1]);
        int num2 = ft_atoi(av[3]);

        if (operation == '+')
            return (num1 + num2);

        else if (operation == '-')
            return (num1 - num2);

        else if (operation == '/')
            return (num1 / num2);

        else if (operation == '*')
            return (num1 * num2);

        else if (operation == '%')
            return (num1 % num2);
    }
    return 0;
}

