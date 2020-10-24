#include <stdio.h>

int ft_strlen(char *str)
{
    int res=0;
    for (int i=0; str[i] != '\0'; i++)
    {
        res++;
    }
    return res;
}

int power(int n, int k)
{
    int j=n;
    if (k==0)
        return 1;
    for (int i=1; i<k; i++){
        n *= j;
    }
    return n;
}

int ft_atoi(char *str){
    int res=0;
    int size = ft_strlen(str);
    for (int i=0; str[i] != '\0'; i++){
        if (str[i] == '1')
            res += 1 * power(10, size-i-1);
        else if (str[i] == '2')
            res += 2 * power(10, size-i-1);
        else if (str[i] == '3')
            res += 3 * power(10, size-i-1);
        else if (str[i] == '4')
            res += 4 * power(10, size-i-1);
        else if (str[i] == '5')
            res += 5 * power(10, size-i-1);
        else if (str[i] == '6')
            res += 6 * power(10, size-i-1);
        else if (str[i] == '7')
            res += 7 * power(10, size-i-1);
        else if (str[i] == '8')
            res += 8 * power(10, size-i-1);
        else if (str[i] == '9')
            res += 9 * power(10, size-i-1);
    }
    return res;
}

