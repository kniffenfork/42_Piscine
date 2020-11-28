int         ascii_sum(char *str)
{
    int i = 0;
    int result = 0;
    while (str[i])
    {
        result += str[i];
        i++;
    }
    return result;
}

void         ft_sort_wordtab(char **list) // обычная сортировка вставками
{
    int     i;
    int     j;
    char    *k;

    i = 1;

    while(list[i])
    {
        j = i;
        while ((j > 0) && (ascii_sum(list[j]) < ascii_sum(list[j - 1])))
        {
            k = list[j];
            list[j] = list[j - 1];
            list[j - 1] = k;
            j = j - 1;
        }
        i++;
    }
}
