int ft_sqrt(int nb)
{
    int res = nb;
    if (nb >= 0)
    {
        if (nb == 0)
            return 1;
        else if (nb == 1)
            return nb;
        else
        {
            for (int i = 0; i < 1000; i++)
            {
                res = (res + nb / res) >> 1;
            }
        }
    }
    else
        return -1;

    return res;
}

