int power(int n, int k)
{
    int j = n;
    if (k == 0)
        return 1;
    for (int i = 1; i < k; i++)
        n *= j;
    return n;
}

int strlength(char *str)
{
    int i = 0;
    if (str[0] == '-')
    {
        i = 1;
        while (str[i] >= '0' && str[i] <= '9')
        {
            i++;
        }
        return i-1;
    }
    else
    {
        while (str[i] >= '0' && str[i] <= '9')
        {
            i++;
        }
        return i;
    }
}

int ft_atoi(char *str)
{
    int res = 0;
    if (str[0] != '-')
    {
        int i = 0;
        while (str[i] >= '0' && str[i] <= '9')
        {
            res += (str[i] - '0') * power(10, strlength(str) - i - 1);
            i++;
        }
        return res;
    }
    else {
        for (int i = 1; i < (1 + strlength(str)); i++)
        {
            res += (str[i] - '0') * power(10, strlength(str) - i);
        }
        return (-1) * res;
    }
}
