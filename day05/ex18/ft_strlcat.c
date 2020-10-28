int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

char *ft_strlcat(char *dest, char *src, unsigned int nb)
{
    int length_dest = ft_strlen(dest);
    int length_of_all;

    if (nb > (ft_strlen(dest) + ft_strlen(src)))
        length_of_all = ft_strlen(dest) + ft_strlen(src);
    else
        length_of_all = (int)nb;

    for (int i = length_dest; i < length_of_all; i++)
    {
        dest[i] = src[i - length_dest];
    }
    dest[length_of_all] = '\0';
    return dest;
}
