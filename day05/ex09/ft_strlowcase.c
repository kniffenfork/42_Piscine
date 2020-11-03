char *ft_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
    }
    return str;
}

