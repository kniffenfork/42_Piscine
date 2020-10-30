int ft_str_is_uppercase(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] > 64 && str[i] < 91)
            continue;
        else
            return 0;
    }
    return 1;
}
