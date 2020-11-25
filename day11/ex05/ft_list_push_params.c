#include "/Users/user/Desktop/Informatiks/learn_C/day11/ft_list.h"
#include <string.h>
t_list         *ft_create_elem(void *data)
{
    t_list *list = malloc(sizeof(t_list));

    list->data = data;
    list->next = NULL;

    return list;
}

void ft_list_push_back(t_list **list, void *data)
{
    t_list *node = malloc(sizeof(t_list));
    node->data = data;
    node->next = *list;
    *list = node;
}

t_list          *ft_list_push_params(int ac, char **av)
{
    if (ac == 1)
        return 0;

    else
    {
        t_list **list = (t_list **)malloc(sizeof(t_list *));
        int i = 1;
        while (av[i])
        {
            ft_list_push_back(list, av[i]);
            i++;
        }
        return *list;
    }
}

void printfromhead(t_list *list)
{
    if (list)
    {
        ft_putstr(list->data);
        ft_putchar(' ');
        printfromhead(list->next);
    }
}


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
            printfromhead(*head);
            ft_putchar('\n');
            return ft_list_sort(head, cmp);
        }
        current = current->next;
    }
}

int main(int ac, char **av)
{
    t_list *list = ft_list_push_params(ac, av);
    ft_list_sort(&list, strcmp);
    printfromhead(list);
}