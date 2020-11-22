void        ft_foreach(int *tab, int length, void(*f)(int)) // уф бля как сложно
{
    for (int i = 0; i < length; i++)
    {
        f(tab[i]);
    }
}

