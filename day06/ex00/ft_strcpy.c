int ft_strlen(char *str);

char *ft_strcpy(char *dest, char *src)
{
    for (int i = 0; i < (ft_strlen(src) + 1); i++)
    {
        dest[i] = src[i];
    }
    return dest;
}

