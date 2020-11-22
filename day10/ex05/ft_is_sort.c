int          ft_is_sort(int *tab, int length, int(*f)(int , int))
{
    int i = 1;
    while (i < length && (*f)(tab[i - 1], tab[i - 1]) <= 0)
    {
        i++;
    }
    return (i >= length);
}