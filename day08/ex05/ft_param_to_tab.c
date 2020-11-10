#include "ft_stock_par.h"
#include <stdio.h>


char *ft_strdup(char *src)
{
    char *dest;
    dest = malloc(sizeof(char) * (ft_strlen(src) + 1));//о, а здесь считать умеет
    return (dest ? ft_strcpy(dest, src) : dest);
}

struct	s_stock_par	*ft_param_to_tab(int ac, char **av)
{
    t_stock_par	*tab;
    int	i = 0;
    int	j;
    tab = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1));//хуя, и тут умеет
    while (i < ac)
    {
        j = 0;
        while (av[i][j] != '\0')
            j++;
        tab[i].size_param = j;
        tab[i].str = av[i];
        tab[i].copy = ft_strdup(av[i]);
        tab[i].tab = ft_split_whitespaces(av[i]);
        ++i;
    }
    tab[i].str = NULL;
    return (tab);
}
/*
int main(int argc, char **argv)
{
    t_stock_par *answer = ft_param_to_tab(argc, argv);
    ft_putstr(*answer[1].tab); // Ура нахуй
}*/