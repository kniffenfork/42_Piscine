#include "ft_tail.h"

t_list         *ft_create_elem(char data)
{
    t_list *list = malloc(sizeof(t_list));

    list->data = data;
    list->next = NULL;

    return list;
}

void            ft_list_push_back(t_list **list, char data)
{
    t_list *node = malloc(sizeof(t_list));
    node->data = data;
    node->next = *list;
    *list = node;
}

void            ft_list_clear(t_list **head)
{
    t_list *prev = NULL;
    while ((*head)->next)
    {
        prev = *head;
        *head = (*head)->next;
        free(prev);
    }
    free(*head);
}


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

void            printfromhead(t_list *list)
{
    if (list)
    {
        ft_putchar(list->data);
        printfromhead(list->next);
    }
}

void            printFromTail(t_list *list)
{
    if (list)
    {
        printFromTail(list->next);
        ft_putchar(list->data);
    }
}