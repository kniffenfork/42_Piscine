int ft_iterative_power(int nb, int power)
{
    int result = 1;
    if (power > 0)
    {
        for (int i = 0; i < power; i++)
        {
            result *= nb;
        }
    }
    else if (power == 0)
        return 1;
    else
        return 0;
    return result;
}

