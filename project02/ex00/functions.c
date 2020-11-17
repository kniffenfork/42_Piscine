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

char *ft_num_to_str(int c)
{
    char *result;
    if (c == 0)
    {
        result = "0";
        return result;
    }

    int flag = 0;

    if (c < 0)
    {
        flag = 1;
        c *= -1;
    }

    int num = c;
    int length_of_int = 0;
    int k = 0;
    int prom;

    while (c != 0)
    {
        c /= 10;
        length_of_int++;
    }

    result = (char *)malloc(length_of_int + 1);

    if (flag == 1)
    {
        result[k] = '-';
        k++;
    }

    for (int i = length_of_int - 1; i >= 0; i--)
    {
        prom = (num/(ft_power(10, i))) % 10;
        result[k] = (prom + '0');
        k++;
    }
    return result;
}