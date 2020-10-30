void ft_putchar(char c);

// Вы извените, но я спал 4 часа и на креатив меня не пробрало чет))0)

void rush(int x, int y)
{
    x--;
    y--;

    for (int i = 0; i <= y; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if ((i == 0 || i == y) && (j == 0 || j == x))
                ft_putchar('o');

            else if ((j > 0 && j < x) && (i == 0 || i == y))
                ft_putchar('-');

            else if (j == 0 || j == x)
                ft_putchar('|');

            else
                ft_putchar(' ');
        }
        ft_putchar('\n');
    }
    ft_putchar('\n');
}
