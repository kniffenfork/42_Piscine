#include "do-op.h"

int main(int ac, char **av)
{
    int result = ft_do_op(ac, av);

    if (check_for_possibility(ac, av) != error_number_of_arguments)
    {
        ft_putnbr(result);
        ft_putchar('\n');
    }
}