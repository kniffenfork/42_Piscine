#include "../../day06/ex00/include/libft.h"
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int *result = (int *)malloc(((max - min) * sizeof(int)) + sizeof(int));

    if (min >= max)
        return 0;

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


