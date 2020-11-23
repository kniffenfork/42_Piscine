#include "/Users/user/Desktop/Informatiks/learn_C/day11/ft_list.h"


t_list          *ft_list_at(t_list *head, unsigned int nbr)
{
    t_list *tmp = NULL;
    tmp = head;
    int i = 0;
    while (tmp->next && i < nbr)
    {
        tmp = tmp->next;
        i++;
    }
    if (i == nbr)
        return tmp;
    else
        return NULL;
}
