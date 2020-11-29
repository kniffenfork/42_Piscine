#include "./ft/ft.h"
#include "./read_data/read_data.h"


int main(int ac, char **av)
{
    t_data *data = read_data_from_cmdline(ac, av);
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