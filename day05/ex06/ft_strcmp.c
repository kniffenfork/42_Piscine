int ft_strlen(const char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}


int ft_strcmp(char *s1, char *s2)
{
    if (ft_strlen(s1) != ft_strlen(s2))
        return 0;
    else
    {
        for (int i = 0; i < ft_strlen(s1); i++)
        {
            if (s1[i] != s2[i])
                return 0;
        }
    }
    return 1;
}

