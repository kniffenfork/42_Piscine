#include "../../day06/ex00/include/libft.h"

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
    int		i;
    int		j;
    char	*temp;

    i = 1;
    while (tab[i] != 0)
    {
        j = i;
        while (tab[j] != 0)
        {
            if ((*cmp)(tab[i], tab[j]) > 0)
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int main()
{
    ft_putnbr(ft_atoi("250tomato"));
}