#include "./ft/ft.h"
#include "./read_data/read_data.h"
#include "./bsq_solver/bsq_solver.h"
#include <stdio.h>

int main(int ac, char **av)
{
    t_data *data = FILES_read_data(ac, av);
    Print_Data(data);
}