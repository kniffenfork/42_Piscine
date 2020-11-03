#include <stdlib.h>
#include "../../day06/ex00/include/libft.h"
// Извени за этот фильм ужасов из мира асимптотики -- учился так маллоком пользоваться ))00 (охуел чот пока писал)
#include <stdio.h>

int count_of_words(char *str)
{
    int flag = 0;
    int res = 1;
    if (ft_strlen(str) == 0)
        return 0;
    else if (str[ft_strlen(str)] == ' ')
        res = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            flag = 1;
            i++;
        }
        if (flag == 1)
        {
            res++;
            flag = 0;
            i++;
            continue;
        }
        i++;
    }
    return res;
}

int *length_of_words(char *str)
{
    int *result = malloc(sizeof(int) * count_of_words(str));
    int i = 0;
    int j = 0;
    int k = 0;
    int flag = 0;
    while (str[i] != '\0')
    {
        while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            flag = 1;
            i++;
        }
        if (flag == 1) // как только входим в другое слово после пробела -- добавляем число букв в прошлом в массив
        {
            result[j] = k;
            k = 0;
            j++;
            i++;
            k++;
            flag = 0;
            continue;
        }
        i++;
        k++;
    }
    result[j] = k;
    return result;
}

char **ft_split_whitespaces(char *str)
{
    char **result = (char **)malloc(sizeof(char *) * (count_of_words(str)) + sizeof(char *));
    int *arr_of_length = length_of_words(str);
    int i = 0;
    int j = 0;
    result[j] = (char *)malloc(sizeof(char) * arr_of_length[j] + sizeof('\0'));
    int k = 0;
    int flag = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            flag = 1;
            i++;
            k = 0;
        }
        else if (flag == 1) // опять же первое вхождение в следующее слово
        {
            k = 0;
            flag = 0;
            j++;
            result[j] = (char *)malloc(sizeof(char) * arr_of_length[j] + sizeof('\0')); // определяем место в массиве для следующего слова
            result[j][k] = str[i]; // добавляем первый элемент следующего слова
            k++;
            i++;
        }
        else if (str[i] != ' ')
            {
            result[j][k] = str[i]; // если это не пробел и не первый элемент то просто хреначим в уже готовое место букву
            k++;
            i++;
            }
    }
    return result;
}


