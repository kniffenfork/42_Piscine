#include "./ft/ft.h"
#include "./read_data/read_data.h"


int main(int ac, char **av)
{

    t_data *data = create_data_array(ac, av);
    Print_Data(data);
    ft_putchar('\n');

}