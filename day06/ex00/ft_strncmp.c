int ft_strlen(char *str);

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int i = 0;
    int min_length;
    if (ft_strlen(s1) >= ft_strlen(s2))
        min_length = ft_strlen(s2);
    else
        min_length = ft_strlen(s1);

    while (i != min_length || i < n)
    {
        if (s1[i] != s2[i])
            return 1;
        i++;
    }
    return 0;
}
