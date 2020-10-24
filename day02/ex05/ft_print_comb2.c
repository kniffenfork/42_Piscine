#include <zconf.h>


int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

void str_to_chars(int c)
{
    int a1 = c/10, a2 = c%10;
    ft_putchar(a1 + '0');
    ft_putchar(a2 + '0');
    ft_putchar(' ');
}

void ft_print_comb2()
{
    for (int i=0; i <= 98; i++){
        for (int j=i+1; j <= 99; j++){
            str_to_chars(i);
            str_to_chars(j);
            if (i == 98){
                break;
            }
            ft_putchar(',');
            ft_putchar(' ');
        }
    }
}

int main(){
    ft_print_comb2();
}