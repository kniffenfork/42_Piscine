#include "../../day06/ex00/include/libft.h"
#include <stdlib.h>

int *ft_range(int min, int max)
{

	if (min >= max)
	{
		return 0;
	}
	int *result = (int *)malloc(((max - min + 1) * sizeof(int)));

	else if (result == NULL)
	{
		return result;
	}

	//малочим только после проверки на min >= max, иначе утечка - вызываю твою функцию много раз, а указатель, который
	//нужно очистить мне не выдается, он внутри и пропадает
	//int *result = (int *)malloc(((max - min) * sizeof(int)) + sizeof(int));
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


