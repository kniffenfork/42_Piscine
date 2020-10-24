#include <zconf.h>


int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

void str_to_chars(int c)
{
    int a1 = c/100, a2 = (c/10)%10, a3 = c%10;
    ft_putchar(a1 + '0');
    ft_putchar(a2 + '0');
    ft_putchar(a3 + '0');
    ft_putchar(' ');
}


void ft_print_comb()
{
    for (int i=0; i < 1000; i++)
    {
        int a1 = i/100, a2 = (i/10)%10, a3 = i%10;
        if ((a1 < a2) && (a2 < a3)){
            str_to_chars(i);
            if (i==789){
                break;
            }
            ft_putchar(',');
            ft_putchar(' ');
        }
    }
}

int main(){
    ft_print_comb();
}