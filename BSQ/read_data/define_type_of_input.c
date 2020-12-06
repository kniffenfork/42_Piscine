#include "read_data.h"

int             define_type_of_input(int ac, char **av)
{
    if (FT_is_digit(av[1][0]))
        return INPUT_IS_ARGUMENTS_IN_CMDLINE;
    else
        return INPUT_IS_FILES;
}

int           CountOfFiles(int ac, char **av)
{
    int result = 0;
    if (define_type_of_input(ac, av) == INPUT_IS_ARGUMENTS_IN_CMDLINE)
    {
        int i = 1;
        while (av[i])
        {
            if (FT_is_digit(av[i][0]))
                result++;
            i++;
        }
        return result;
    }
    else
        return (ac - 1);
}