#include <stdio.h>
#include <stdlib.h>
#include "../../day06/ex00/include/libft.h"

char *ft_concat_params(int argc, char **argv)
{
    char *result = (char *)malloc(sizeof(argv));

    if (result == NULL)
        return result;

    int count = 0;

    for (int i = 1; i < argc; i++)
    {
        if (i != 1)
        {
            result[count] = '\n';
            count++;
        }
        for (int j = 0; j < ft_strlen(argv[i]); j++)
        {
            result[count] = argv[i][j];
            count++;
        }
    }

    result[count] = '\0';

    return result;
}

int main(int argc, char **argv)
{
    printf("%s", ft_concat_params(argc, argv));
}