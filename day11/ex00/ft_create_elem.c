#include "/Users/user/Desktop/Informatiks/learn_C/day11/ft_list.h"

t_list          *ft_create_elem(void *data)
{
    t_list *list = (t_list *)malloc(sizeof(t_list));

    list->data = data;
    list->next = NULL;

    return list;
}