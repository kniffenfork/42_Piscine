#include "./read_data/read_data.h"
#include "./ft/ft.h"

int main(int ac, char **av)
{
    if (define_type_of_input(ac, av) == INPUT_IS_ARGUMENTS_IN_CMDLINE)
    {
        ft_putstr("INPUT IS ARGUMENTS IN COMMAND LINE\n");
    }
    else
        ft_putstr("INPUT IS FILES\n");
}