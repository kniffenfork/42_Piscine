#include "../ft_list.h"

void            ft_list_sort(t_list **head, int (*cmp)())
{
    t_list *current;
    t_list *next;
    char *help;

    current = *head;

    while (current->next)
    {
        next = current->next;

        if (cmp(current->data, next->data) > 0)
        {
            help = current->data;
            current->data = next->data;
            next->data = help;
            return ft_list_sort(head, cmp);
        }
        current = current->next;
    }
}