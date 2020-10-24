#include <zconf.h>


int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

void ft_is_negative(int n)
{
    if (n >= 0)
        ft_putchar('P');
    else
        ft_putchar('N');
    /*
     * могу только предложить вариант короче ft_putchar(n >= 0 ? 'P' : 'N') - тернарный оператор, в си наверное так
     * , пишется, не помню, можешь погуглить. в джаве по крайней мере так
      */
}

