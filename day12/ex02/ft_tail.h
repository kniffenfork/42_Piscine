#ifndef LEARN_C_FT_TAIL_H
#define LEARN_C_FT_TAIL_H

#include <unistd.h>
#include <fcntl.h>
#include "../../day06/ex00/include/libft.h"
#include <stdlib.h>
#include <errno.h>

#define TRUE    1
#define FALSE   0

typedef int t_bool;

typedef struct              s_list
{
    struct s_list           *next;
    char                    data;

}                           t_list;

// ft_tail:

int            ft_tail(int ac, char **av);

// functions for linked list:
t_list         *ft_create_elem(char data);
void            ft_list_push_back(t_list **list, char data);
void            ft_list_clear(t_list **head);
void            ft_list_reverse(t_list **head);
void            printfromhead(t_list *list);
void            printFromTail(t_list *list);

#endif //LEARN_C_FT_TAIL_H
