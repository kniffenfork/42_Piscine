#include <stdio.h>
#include <stdbool.h>
#include <zconf.h>


int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

void ft_print(char c1, char c2, char c3){
    ft_putchar(c1);
    ft_putchar(c2);
    ft_putchar(c3);
    if (c1 != '7' || c2 != '8' || c3 != '9'){
        ft_putchar(',');
        ft_putchar(' ');
    }

}


void ft_print_comb() {
    int i=0, j, k;
    while (i <= 9)
    {
        j = i+1;
        while (j <= 9)
        {
            k = j + 1;
            while (k <= 9){
                ft_print(i + '0', j + '0', k + '0');
                k++;
            }
            j++;
        }
        i++;
    }
}

int main(){
    ft_print_comb();
    return 0;
}