int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

char *ft_strlcpy(char *dest, char *src, unsigned int nb)
{
    int len_dest = ft_strlen(dest);
    int len_src = ft_strlen(src);
    int len_all = len_dest + len_src;
    int len_for_func;

    if (nb > len_all)
        len_for_func = len_all;
    else
        len_for_func = (int)nb;

    for (int i = 0; i < len_for_func; i++)
    {
        dest[i] = src[i];
    }

    dest[len_for_func - 1] = '\0';

    return dest;
}
