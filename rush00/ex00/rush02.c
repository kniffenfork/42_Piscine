void ft_putchar(char c);

void rush(int x, int y)
{
    x--;
    y--;

    for (int i = 0; i <= y; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (i == 0 && (j == 0 || j == x)) // a[0][0] and a[0][x] equal A
                ft_putchar('A');

            else if (i == y && (j == 0 || j == x)) // a[y][0] and a[y][x] equal C
                ft_putchar('C');

            else if ((i != 0 && i != y) && (j > 0 && j < x))
                ft_putchar(' ');

            else
                ft_putchar('B');
        }
        ft_putchar('\n');
    }
    ft_putchar('\n');
}
