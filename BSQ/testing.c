#include "./ft/ft.h"
#include "./read_data/read_data.h"
#include <stdio.h>

int main(int ac, char **av)
{
    t_data *data = create_data_array(ac, av);
    //Print_Data(data);
    int i = 0;
    int j = 0;
    int count_of_lines = data->count_of_data_lines[0];
    while (i < count_of_lines)
    {
        ft_putchar(data->solve_helper[0][0][i] + '0');
        ft_putchar(' ');
        i++;
    }
    ft_putnbr(data->solve_helper[0][0][5]);
}