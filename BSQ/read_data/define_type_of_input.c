#include "read_data.h"

int             define_type_of_input(int ac, char **av)
{
    if (FT_match(av[1], "*.ox"))
        return INPUT_IS_ARGUMENTS_IN_CMDLINE;
    else
        return INPUT_IS_FILES;
}