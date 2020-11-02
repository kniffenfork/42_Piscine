#include "/Users/user/Desktop/Informatiks/learn_C/day06/ex00/include/libft.h"

int ascii_sum(char *arr)
{
    int res = 0;
    for (int i = 0; i < ft_strlen(arr); i++)
    {
        res += arr[i];
    }
    return res;
}

char *swap_sort(char *list[], int arc)
{
    int i, j;
    for (i = 0; i < arc; i++)
    {
        j = i;
        while ((j > 0) && (ascii_sum(list[j]) < ascii_sum(list[j - 1])))
        {
            char *k = list[j];
            list[j] = list[j - 1];
            list[j - 1] = k;
            j = j - 1;
        }
    }
    return *list;
}


int main(int arc, char *argv[])
{
    swap_sort(argv, arc);
    for (int i = 0; i <= (arc - 2); i++)
    {
        ft_putstr(argv[i]);
        ft_putchar('\n');
    }
}

}