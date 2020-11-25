#include "/Users/user/Desktop/Informatiks/learn_C/day11/ft_list.h"

void printfromhead(t_list *list)
{
    if (list)
    {
        ft_putstr(list->data);
        ft_putchar(' ');
        printfromhead(list->next);
    }
}
