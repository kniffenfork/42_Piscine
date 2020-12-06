#include "./ft/ft.h"
#include "./read_data/read_data.h"
#include "./bsq_solver/bsq_solver.h"
#include <stdio.h>

int main(int ac, char **av)
{
    /*
    t_data *data = BSQ_solve(ac, av);
    Print_Data(data);
     */
    t_data *data =  BSQ_solve(ac, av);
    Print_Data(data);
    /*
    for (int i = 0; i < data->count_of_data_lines[0]; i++)
    {
        ft_putnbr(data->solve_helper[0][0][i]);
        ft_putchar(' ');
    }
     */
}