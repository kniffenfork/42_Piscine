#include "../ft_list.h"

void            ft_list_merge(t_list **head1, t_list **head2)
{
    t_list *current;
    current = *head1;

    while (current->next)
    {
        current = current->next;
    }
    current->next = *head2;
}