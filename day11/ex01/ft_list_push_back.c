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


void printfromhead(t_list *list)
{
    if (list)
    {
        ft_putstr(list->data);
        ft_putchar(' ');
        printfromhead(list->next);
    }
}

void printFromTail(t_list *list)
{
    if (list)
    {
        printFromTail(list->next);
        ft_putstr(list->data);
        ft_putchar(' ');
    }
}

int main()
{
    t_list *list = NULL;
    char *str = "HUI ZALUPA PENIS";
    char **slova = ft_split_whitespaces(str);
    int i = 0;
    while (slova[i])
    {
        ft_list_push_back(&list, slova[i]);
        i++;
    }
    printfromhead(list);
    ft_putchar('\n');
    printFromTail(list);
}