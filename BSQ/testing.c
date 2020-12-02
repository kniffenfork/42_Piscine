#include "./ft/ft.h"
#include "./read_data/read_data.h"

void test_data_filling(t_data *data, int num_of_files)
{
    int i = 0;
    while (i < num_of_files)
    {
        ft_putstr("Obstacle ");
        ft_putchar(i + 1 + '0');
        ft_putstr(": ");
        ft_putchar(data->obstacles[i]);
        ft_putchar('\n');
        ft_putstr("Empty cell ");
        ft_putchar(i + 1 + '0');
        ft_putstr(": ");
        ft_putchar(data->empty_cell[i]);
        ft_putchar('\n');
        ft_putstr("Symbol to solve ");
        ft_putchar(i + 1 + '0');
        ft_putstr(": ");
        ft_putchar(data->symbols_to_solve[i]);
        ft_putchar('\n');
        ft_putstr("Count of data lines ");
        ft_putchar(i + 1 + '0');
        ft_putstr(": ");
        ft_putnbr(data->count_of_data_lines[i]);
        ft_putchar('\n');
        i++;
    }
}
int main(int ac, char **av)
{

    t_data *data = FILES_get_map_description(ac, av);
    test_data_filling(data, 3);
/*
t_data *data = create_data_array(ac, av);
Print_Data(data);
 */
}