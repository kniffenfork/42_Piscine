#include <zconf.h>


int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

void ft_print_numbers(void){
    char digits[] = "0123456789";
    for (int i=0; digits[i] != '\0'; i++)
    {
        ft_putchar(digits[i]);
    }
}
,