#include <unistd.h>
#include <fcntl.h>
#include "../../day06/ex00/include/libft.h"

void             ft_display_file(int ac, char **av)
{
    int file;
    char buff[1];

    if (ac > 2)
    {
        ft_putstr("Too many arguments.");
        ft_putchar('\n');
        return;
    }
    else if (ac < 2)
    {
        ft_putstr("File name missing");
        ft_putchar('\n');
        return;
    }

    char *name = av[1];

    file = open(name, O_RDONLY);

    while (read(file, buff, sizeof(buff)))
    {
        write(1, buff, sizeof(buff));
    }
    close(file);
}

int main(int ac, char **av)
{
    ft_display_file(ac, av);
}