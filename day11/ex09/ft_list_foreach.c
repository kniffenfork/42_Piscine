#include "/Users/user/Desktop/Informatiks/learn_C/day11/ft_list.h"


void            ft_list_foreach(t_list *head, void(*f)(void *))
{
    t_list *curr = NULL;

    if (head == NULL)
        return;

    curr = head;
    while (curr)
    {
        (*f)(curr->data);
        curr = curr->next;
    }
}