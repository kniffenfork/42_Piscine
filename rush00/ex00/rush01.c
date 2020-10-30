void ft_putchar(char c);

void rush(int x, int y)
{
    x--;
    y--;

    for (int i = 0; i <= y; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if ((i == 0 && j == 0))
                ft_putchar('/');

            else if ((i == 0 && j == x) || ((i == y) && j == 0))
                ft_putchar('\\');

            else if ((i == y) && (j == x))
                ft_putchar('/');

            else if ((i > 0 && i < y) && (j > 0 && j < x))
                ft_putchar(' ');

            else
                ft_putchar('*');
        }
        ft_putchar('\n');
    }
    ft_putchar('\n');
}
