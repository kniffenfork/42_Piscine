#include "/Users/user/Desktop/Informatiks/learn_C/day11/ft_list.h"

void printFromTail(t_list *list)
{
    if (list)
    {
        printFromTail(list->next);
        ft_putstr(list->data);
        ft_putchar(' ');
    }
}