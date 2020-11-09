#include "ft_stock_par.h"



void ft_show_tab(struct s_stock_par *par)
{
    int i = 0;
    while (par[i].str)
    {
        int j = 0;
        ft_putnbr(par[i].size_param);
        ft_putchar('\n');
        ft_putstr(par[i].str);
        ft_putchar('\n');
        while (par[i].tab[j])
        {
            ft_putstr(par[i].tab[j]);
            ft_putchar('\n'); // могу ифом убрать лишний пробел но так нагляднее
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

int main(int arc, char **argv)
{
    t_stock_par *ans = ft_param_to_tab(arc, argv);
    ft_show_tab(ans);
}