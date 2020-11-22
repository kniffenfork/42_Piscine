#include <stdlib.h>

int             *ft_map(int *tab, int length, int(*f)(int))
{
    int *res_array = (int *)malloc(sizeof(int) * length + 1);

    for (int i = 0; i < length; i++)
    {
        res_array[i] = f(tab[i]);
    }

    return res_array;
}