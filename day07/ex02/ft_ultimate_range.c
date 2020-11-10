#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
	// тоже самое
    int *result = (int *)malloc(((max - min) * sizeof(int) + sizeof(int)));

    if (min >= max)
        return 0;//утечка в ебало

    else if (result == NULL)
        return result;

    else
    {
        int i = (min);
        for (int j = 0; j < (max - min); j++)
        {
            result[j] = i;
            i++;
        }
        return result;
    }
}

int ft_ultimate_range(int **range, int min, int max)
{
    *range = ft_range(min, max);
    if (range == NULL)
        return 0;
    else
    {
        return (max - min);
    }
}

int main()
{
    int *arr;
    printf("%d", ft_ultimate_range(&arr, 0, 9));
}