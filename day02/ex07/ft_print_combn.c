#include <zconf.h>


int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

int power(int n, int k)
{
    int j=n;
    if (k==0)
        return 1;
    for (int i=1; i<k; i++){
        n *= j;
    }
    return n;
}

void ft_putnbrn(int c, int n){
    int num = c;
    int prom;
    for (int i=n-1; i>=0; i--)
    {
        prom = (num/(power(10, i)))%10;
        ft_putchar(prom + '0');
    }
}

int check_nums_are_different(int c, int n)
{
    int flag =- 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((c / power(10, i)) % 10 > flag)
            flag = (c / power(10, i)) % 10;
        else
            return 0;
    }
    return 1;
}

void ft_print_combn(int n)
{
    for (int i=0; i < power(10, n); i++)
    {
        if (check_nums_are_different(i, n) == 1)
        	/*
        	 * вроде в си инт кастуется к булеану по правилу >0 = true, можно убрать
        	 * сравнение, оставив только if (check_nums_are_different());
        	*/
        {
            ft_putnbrn(i, n);
            //лапша пиздец. перед и после == тоже пробелы нужны
            if ((i==9 && n==1) || (i == 89 && n == 2) || (i== 789 && n==3)|| (i==6789 && n==4)|| (i==56789 && n==5) ||
            (i==456789 && n==6)|| (i==3456789 && n == 7) || (i==23456789 && n==8) || (i==123456789 && n==9))
                break;
            ft_putchar(',');
            ft_putchar(' ');
        }
    }
}

int main()
{
    ft_print_combn(3);
}