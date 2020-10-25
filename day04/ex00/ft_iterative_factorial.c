int ft_iterative_factorial(int nb)
{
    int result = 1;
    if (nb > 0)
    {
        for (int i = 1; i <= nb; i++)
            result *= i;
    }
    else if (nb == 0)
        return 1;
    else
        return 0;

    return result;
}
