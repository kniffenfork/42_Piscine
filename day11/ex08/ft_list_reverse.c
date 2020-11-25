#include "/Users/user/Desktop/Informatiks/learn_C/day11/ft_list.h"

void            ft_list_reverse(t_list **head)
{
    t_list *curr = NULL;
    t_list *next = NULL;
    t_list *prev = NULL;

    if (*head == NULL)
        return;

    else
    {
        curr = *head;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        *head = prev;
    }
}

