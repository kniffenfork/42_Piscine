#include "ft.h"

int ft_el_in_str(char *str, char symbol_in_str)
{
    for (int i = 0; i < ft_strlen(str); i++)
    {
        if (str[i] == symbol_in_str)
            return 1;
    }
    return 0;
}

int count_of_words(char *str, char *sep)
{
    int flag = 0;
    int res = 1;
    if (ft_strlen(str) == 0)
        return 0;
    else if (str[ft_strlen(str)] == ' ')
        res = 0;
    int i = 0;
    while (str[i])
    {
        while (ft_el_in_str(sep, str[i]))
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

int *length_of_words(char *str, char *sep)
{
    int *result = (int *)malloc(sizeof(int) * (count_of_words(str, sep) + 1));
    int i = 0;
    int j = 0;
    int k = 0;
    int flag = 0;
    while (str[i] != '\0')
    {
        while (ft_el_in_str(sep, str[i]))
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

char **FT_split(char *str, char *charset)
{
    char **result = (char **)malloc(sizeof(char *) * count_of_words(str, charset) + 1);
    int *arr_of_length = length_of_words(str, charset);
    int i = 0;
    int j = 0;
    int k = 0;
    int flag = 0;

    result[j] = (char *)malloc(sizeof(char) * arr_of_length[j] + sizeof('\0'));
    while (str[i])
    {
        if (ft_el_in_str(charset, str[i]))
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
        else if (!ft_el_in_str(charset, str[i]))
        {
            result[j][k] = str[i]; // если это не пробел и не первый элемент то просто хреначим в уже готовое место букву
            k++;
            i++;
        }
    }
    return result;
}
