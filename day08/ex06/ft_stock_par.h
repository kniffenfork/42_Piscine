#ifndef LEARN_C_FT_STOCK_PAR_H
#define LEARN_C_FT_STOCK_PAR_H

#include <stdlib.h>
#include "/Users/user/Desktop/Informatiks/learn_C/day06/ex00/include/libft.h"

typedef struct s_stock_par
{
    int size_param;
    char *str;
    char *copy;
    char **tab;
}               t_stock_par;

t_stock_par *ft_param_to_tab(int ac, char **argv);

#endif //LEARN_C_FT_STOCK_PAR_H

