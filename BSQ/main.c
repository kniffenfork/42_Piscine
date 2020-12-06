#include "BSQ.h"

int main(int ac, char **av)
{
    t_data *data =  BSQ_solve(ac, av);
    Print_Data(data);
}