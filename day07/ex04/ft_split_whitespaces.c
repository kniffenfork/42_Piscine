#include <stdlib.h>
#include "../../day06/ex00/include/libft.h"
#include <stdio.h>
// Извени за этот фильм ужасов из мира асимптотики -- учился так маллоком пользоваться ))00 (охуел чот пока писал)
int count_of_words(char *str)
{
    int flag = 0;
    if (ft_strlen(str) == 0)
        return 0;
    int res = 1;
    int i = 0;
    int len_word = 0;

    while (str[i] != '\0')
    {
        while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {

            flag = 1;
            i++;
            len_word = 0;
        }
        if (flag == 1)
        {
            res++;
            len_word++;
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
        if (flag == 1)
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
    char **result = (char **)malloc(sizeof(char *) * (count_of_words(str)) + sizeof(int));
    int *arr_of_length = length_of_words(str);
    int i = 0;
    int j = 0;
    result[j] = (char *)malloc(sizeof(char) * arr_of_length[j] + sizeof('\0'));
    int k = 0;
    int flag = 0;
    while (str[i] != '\0') {
        while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            flag = 1;
            i++;
            result[j][k] = '\0';
            k = 0;
        }
        if (flag == 1)
        {
            k = 0;
            flag = 0;
            j++;
            result[j] = (char *)malloc(sizeof(char) * arr_of_length[j] + sizeof('\0'));
            result[j][k] = str[i];
            k++;
            i++;
        }
        else
            {
            result[j][k] = str[i];
            k++;
            i++;
            }
    }
    result[j + 1] = NULL;
    return result;
}


int main()
{
    char *str = "abc def o weiogjiowejiogj iowjirti jw0i4u5yi 0uwe0igji j0iw0ie5u0yu 0u0weut0h ";
    char **res_arr = ft_split_whitespaces(str);
    int i = 0;
    printf("%c", '[');
    while (res_arr[i] != NULL)
    {
        printf("%s", res_arr[i]);
        i++;
    }
    printf("%c", ']');
}