#include "/Users/user/Desktop/Informatiks/learn_C/day11/ft_list.h"

int             ft_list_size(t_list **head)
{
    t_list *node;

    if (*head == NULL)
        return 0;
    else
    {
        node = *head;
        int count = 0;

        while (node->next != NULL)
        {
            node = node->next;
            count++;
        }
        return count;
    }
}

