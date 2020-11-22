int         ft_count_if(char **tab, int(*f)(char *))
{
    int         i = 0;
    int         count = 0;

    while (tab[i])
    {
        if (f(tab[i]))
            count++;

        i++;
    }
    return count;
}