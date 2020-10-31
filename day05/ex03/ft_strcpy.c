int strlength(const char *str)
{
    int i = 0;
    //попробуй найди документ из школы, norme кажется называется, там неплохой стиль описан в целом форматирования
    while (str[i] != '\0')
        i++;
    return i;

}

char *ft_strcpy(char *dest, char *src)
{
    for (int i = 0; i < (strlength(src) + 1); i++)
    {
        dest[i] = src[i];
    }
    return dest;
}

