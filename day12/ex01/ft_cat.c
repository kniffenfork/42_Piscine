#include "ft_cat.h"
#include <errno.h>

t_bool           file_is_valid(char *file_name)
{
    int file = open(file_name, O_RDONLY);

    if (file < 0)
    {
        return FALSE;
    }

    return TRUE;
}

int            ft_cat(int ac, char **av)
{
    char        *flag;
    int         i = 1;

    if (av[1][0] == '-')
    {
        flag = av[1];
        i++;
    }

    while (av[i])
    {
        if (!file_is_valid(av[i]))
        {
            ft_putstr("Non valid file.\n");
            return errno;
        }

        if (flag[1] == 'b')
        {
            ft_print_numerize_lines(av[i]);
        }
        else if (flag[1] == 'n')
        {
            ft_print_numerize_all_lines(av[i]);
            ft_putchar('\n');
        }
        else if (flag[1] == 'e')
        {
            show_dollar_at_the_end_of_line(av[i]);
            ft_putchar('\n');
        }
        else if (flag[1] == 's')
        {
            delete_repeated_empty_lines(av[i]);
            ft_putchar('\n');
        }
        else if (flag[1] == 't')
        {
            view_tabulation(av[i]);
            ft_putchar('\n');
        }
        else
        {
            ft_display_file(av[i]);
        }

        i++;
    }
    return 0;
}