#include "./ft/ft.h"
#include "./read_data/read_data.h"

int main(int ac, char **av)
{
    t_data *data = create_data_array(ac, av);
    Print_Data(data);
    /*
    int i = 0;
    int j = 0;
    while (i < data->count_of_data_lines[0])
    {
        while (j < data->count_of_data_lines[0])
        {
            ft_putnbr(data->solve_helper[0][i][j]);
            j++;
        }
        ft_putchar('\n');
        i++;
    }
     */
}