#include "/Users/user/Desktop/Informatiks/learn_C/day11/ft_list.h"

t_list         *ft_create_elem(void *data)
{
    t_list *list = malloc(sizeof(t_list));

    list->data = data;
    list->next = NULL;

    return list;
}

void ft_list_push_back(t_list **list, void *data)
{
    t_list *node = malloc(sizeof(t_list));
    node->data = data;
    node->next = *list;
    *list = node;
}

