#include "read_data.h"

t_data          *create_data_array(int ac, char **av)
{
    if (define_type_of_input(ac, av) == INPUT_IS_FILES)
        return FILES_read_data(ac, av);
    else
        return CMD_read_data(ac, av);
}

void           Print_Data(t_data *data)
{
    ft_putnbr(data->count_of_data_lines[0]);
    ft_putchar('\n');
    int i = 0;
    while (data->data_lines[0][i])
    {
        ft_putstr(data->data_lines[0][i]);
        ft_putchar('\n');
        i++;
    }
}
