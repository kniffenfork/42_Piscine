#include "ft_tail.h"



int            ft_tail(int ac, char **av)
{
    if (ac != 4)
    {
        ft_putstr("ERROR NUMBER OF ARGUMENTS.\n");
        return errno;
    }

    char buff[1];

    int count_of_bytes = ft_atoi(av[2]);

    if (count_of_bytes == 0)
        return 0;

    int file = open(av[3], O_RDONLY);
    t_list **head = malloc(sizeof(t_list *));
    t_list **answer = malloc(sizeof(t_list *));

    while (read(file, buff, sizeof(buff)))
    {
        ft_list_push_back(head, *buff);
    }

    int i = 0;
    char symbol;
    t_list *current = *head;

    while (i < count_of_bytes && current)
    {
        symbol = current->data;
        ft_list_push_back(answer, symbol);
        current = current->next;
        i++;
    }
    ft_list_reverse(answer);
    printFromTail(*answer);
    ft_list_clear(head);
    ft_list_clear(answer);
    close(file);
    return 0;
}
