#include <stdio.h>

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
                res = (res + nb / res) / 2;
            }
        }
    }
    return res;
}


int ft_is_prime(int nb)
{
    if (nb == 0 || nb == 1)
        return 0;
    for (int i = 2; i < (ft_sqrt(nb) + 1); i++)
    {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}


int main()
{
    printf("%i", ft_sqrt(4));
}
