void ft_putchar(char c);

int ft_power(int n, int k);

void ft_putnbr(int c){
    int num = c;
    int length_of_int = 0, prom;
    while (c != 0){
        c /= 10;
        length_of_int++;
    }
    for (int i = length_of_int - 1; i >= 0; i--)
    {
        prom = (num/(ft_power(10, i))) % 10;
        ft_putchar(prom + '0');
    }
}

