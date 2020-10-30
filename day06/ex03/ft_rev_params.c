#include "/Users/user/Desktop/Informatiks/learn_C/day06/ex00/include/libft.h"

int main(int argc, char *argv[])
{
    for (int i = argc - 1; i >= 1; i--)
    {
        ft_putstr(argv[i]);
        ft_putchar('\n');
    }
}