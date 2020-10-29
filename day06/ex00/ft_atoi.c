int ft_atoi(char *str)
{
    int res = 0;
    if (str[0] != '-')
    {
        int i = 0;
        while (str[i] >= '0' && str[i] <= '9')
        {
            res += (str[i] - '0') * power(10, ft_strlen(str) - i - 1);
            i++;
        }
        return res;
    }
    else {
        for (int i = 1; i < (1 + strlen(str)); i++)
        {
            res += (str[i] - '0') * power(10, strlength(str) - i);
        }
        return (-1) * res;
    }
}
