int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

char *ft_strncat(char *dest, char *src, int nb)
{
    int len_dest = ft_strlen(dest);
    for (int i = ft_strlen(dest); i < len_dest + nb; i++)
    {
        dest[i] = src[i - len_dest];
    }
    dest[len_dest + nb] = '\0';
    return dest;
}

