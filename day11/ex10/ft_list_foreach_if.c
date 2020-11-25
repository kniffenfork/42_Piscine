#include "/Users/user/Desktop/Informatiks/learn_C/day11/ft_list.h"

void            ft_list_foreach_if(t_list *head, void (*f)(void *), void *data_ref, int (*cmp()))
{
    t_list *curr = head;

    while (curr)
    {
        if (cmp(curr->data, data_ref) == 0)
            (*f)(curr->data);

        curr = curr->next;
    }
}