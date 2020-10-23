#include <zconf.h>

int ft_putchar(char c);
int ft_putstr(char *str);

int main() {
    ft_putchar('c');

}

int ft_putchar(char c)
{
    return write(1, &c, 1);
}

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int ft_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        ft_putchar(str[i]);//n
    }
    return 1;
}

int ft_putstr2(char *str)
{
    int len = ft_strlen(str);//n

    write(1, str, len);//n + 1
    return 1;
}