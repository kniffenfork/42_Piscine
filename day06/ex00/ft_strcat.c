int ft_strlen(char *str);

char *ft_strcat(char *dest, char *src)
{
    int length = ft_strlen(dest) + ft_strlen(src);
    int len_dest = ft_strlen(dest);
    for (int i = ft_strlen(dest); i < length; i++)
    {
        dest[i] = src[i - len_dest];
    }
    dest[length] = '\0';
    return dest;
}

