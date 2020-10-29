int ft_strlen(char *str)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        res++;
    }
    return res;
}

char *ft_strrev(char *str)
{
    char temp;
    int size = ft_strlen(str);
    for (int i = 0; i < (size / 2); i++)
    {
        temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
    }
    return str;
}

