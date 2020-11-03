#include <stdlib.h>
#include "../../day06/ex00/include/libft.h"

int count_of_words(char *str);

int *length_of_words(char *str);

char **ft_split_whitespaces(char *str);

void ft_print_words_tables(char **tab)
{
    int i = 0;
    while (tab[i] != NULL)
    {
        if (tab[i + 1] != NULL)
        {
            ft_putstr(tab[i]);
            ft_putchar('\n');
        }
        else
            ft_putstr(tab[i]);
        i++;
    }
}