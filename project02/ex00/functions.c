#include "calc.h"

t_bool is_in_string(char *string, char *symbol)
{
    int i = 0;
    while (string[i])
    {
        if (symbol[0] == string[i])
            return TRUE;
        i++;
    }
    return FALSE;
}

t_bool is_digit(char *symbol)
{
    char *nums = "0123456789";

    if (is_in_string(nums, symbol))
        return TRUE;

    return FALSE;
}

t_bool is_operation(char *symbol)
{
    char *operators = "+-*/%";

    if (is_in_string(operators, symbol))
        return TRUE;

    return FALSE;
}

int ft_atoi(char *str)
{
    int res = 0;
    if (str[0] != '-')
    {
        int i = 0;
        while (str[i] >= '0' && str[i] <= '9')
        {
            res += (str[i] - '0') * ft_power(10, ft_strlen(str) - i - 1);
            i++;
        }
        return res;
    }
    else
        {
        for (int i = 1; i < (1 + ft_strlen(str)); i++)
        {
            res += (str[i] - '0') * ft_power(10, ft_strlen(str) - i);
        }
        return (-1) * res;
    }
}