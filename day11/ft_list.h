#ifndef LEARN_C_FT_LIST_H
#define LEARN_C_FT_LIST_H

#include "/Users/user/Desktop/Informatiks/learn_C/day06/ex00/include/libft.h"
#include <stdlib.h>

typedef struct              s_list
{
    struct s_list           *next;
    void                    *data;

}                           t_list;

#endif //LEARN_C_FT_LIST_H
