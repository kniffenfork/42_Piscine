#include "../ft_list.h"

int             ft_list_len(t_list *head)
{
    int res = 0;
    t_list *current = head;
    while (current)
    {
        res++;
        current = current->next;
    }
    return res;
}

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

void            ft_list_reverse_fun(t_list *head)
{
    char *temp;
    int size = ft_list_len(head);
    for (int i = 0; i < (size / 2); i++)
    {
        temp = (ft_list_at(head, i))->data;
        (ft_list_at(head, i))->data = (ft_list_at(head, size - i - 1))->data;
        (ft_list_at(head, size - i - 1))->data = temp;
    }
}