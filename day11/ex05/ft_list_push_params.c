#include "/Users/user/Desktop/Informatiks/learn_C/day11/ft_list.h"

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

int main(int ac, char **av)
{
    t_list *list = ft_list_push_params(ac, av);
    printfromhead(list);
    t_list *check = ft_list_at(list, 20);
    ft_putchar('\n');
    ft_putstr(check->data);
}