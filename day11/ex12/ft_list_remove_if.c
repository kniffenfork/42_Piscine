#include "../ft_list.h"

void            ft_list_remove_if(t_list **head, void *data_ref, int (*cmp)())
{
    t_list *current;
    t_list *prev;
    t_list *next;

    current = *head;
    prev = *head;
    while (current)
    {
        next = (*current).next;
        if ((cmp)(current->data, data_ref) == 0)
        {
            if (current == *head)
            {
                *head = next;
            }
            prev->next = next;
            free(current);
        }
        prev = current;
        current = next;
    }
}