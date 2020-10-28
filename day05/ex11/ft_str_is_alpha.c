int ft_str_is_alpha(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
            return 0;
    }
    return 1;
}

