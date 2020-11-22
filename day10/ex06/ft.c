#include "do-op.h"


int             length_of_ints_int_str(char *str)
{
    int i;
    if (str[0] == '-')
        i = 1;
    else
        i = 0;

    while (is_digit(str[i]))
    {
        i++;
    }

    return i;
}
int             ft_atoi(char *str)
{
    int res = 0;
    int len_of_ints = length_of_ints_int_str(str);
    if (str[0] != '-')
    {
        int i = 0;
        while (is_digit(str[i]))
        {
            res += (str[i] - '0') * ft_power(10, len_of_ints - i - 1);
            i++;
        }
        return res;
    }
    else
    {
        int i = 1;
        while (is_digit(str[i]))
        {
            res += (str[i] - '0') * ft_power(10, len_of_ints - i - 1);
            i++;
        }
        return (-1) * res;
    }
}

int             is_in_string(char *string, char symbol)
{
    int i = 0;
    while (string[i])
    {
        if (symbol == string[i])
            return 1;
        i++;
    }
    return 0;
}

int             is_digit(char symbol)
{
    char *nums = "0123456789";

    if (is_in_string(nums, symbol))
        return 1;

    return 0;
}

int             is_operation(char symbol)
{
    char *operators = "+-*/%";

    if (is_in_string(operators, symbol))
        return error_number_of_arguments;

    return 0;
}