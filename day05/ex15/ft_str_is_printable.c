int ft_str_is_printable(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] > 32 && str[i] < 127)
            continue;
        else
            return 0;
    }
    return 1;
}