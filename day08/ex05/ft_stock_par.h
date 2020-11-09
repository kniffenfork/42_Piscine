#ifndef LEARN_C_FT_STOCK_PAR_H
#define LEARN_C_FT_STOCK_PAR_H

#include <stdlib.h>

typedef struct s_stock_par
{
    int size_param;
    char *str;
    char *copy;
    char **tab;
}               t_stock_par;

#endif //LEARN_C_FT_STOCK_PAR_H
