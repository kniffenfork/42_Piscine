#include "../ft_list.h"

t_list          *ft_list_find(t_list *head, void *data_ref, int (*cmp)())
{
    t_list *curr = head;

    while (curr)
    {
        if (cmp(curr->data, data_ref) == 0)
            return curr;
        curr = curr->next;
    }
    return 0;
}