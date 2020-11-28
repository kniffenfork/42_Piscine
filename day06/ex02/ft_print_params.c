#include "../../day06/ex00/include/libft.h"

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        ft_putstr(argv[i]);
        ft_putchar('\n');
    }

}