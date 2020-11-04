#include <stdlib.h>
#include "../../day06/ex00/include/libft.h"

int ft_atoi(char *str)
{
    int res = 0;
    if (str[0] != '-')
    {
        int i = 0;
        while (str[i] >= '0' && str[i] <= '9')
        {
            res += (str[i] - '0') * ft_power(10, ft_strlen(str) - i - 1);
            i++;
        }
        return res;
    }
    else {
        int i = 1;
        while (str[i] >= '0' && str[i] <= '9')
        {
            res += (str[i] - '0') * ft_power(10, ft_strlen(str) - i - 1);
            i++;
        }
        return (-1) * res;
    }
}


int ft_count_in_str(char *str, char el)
{
    int count = 0;
    for (int i = 0; i < ft_strlen(str); i++)
    {
        if (str[i] == el)
            count++;
    }
    return count;
}

int base_sys(char *base)
{
    int sys = 0;
    while (base[sys])
    {
        if (base[sys] == '+' || base[sys] == '-' || ft_count_in_str(base, base[sys]) > 1)
            return 0;
        sys++;
    }
    return sys;
}

int check_base(char *base)
{
    int sys = base_sys(base);
    if (sys <= 1)
        return 0;
    else
        return 1;
}

int ft_len_of_num(int num)
{
    int res = 0;
    while (num >= 1)
    {
        num /= 10;
        res += 1;
    }
    return res;
}

char *ft_num_to_str(int c)
{
    char *res_arr = malloc(sizeof(char) * ft_len_of_num(c));
    int flag = 0;
    if (c < 0)
    {
        flag = 1;
        c *= -1;
    }
    int num = c;
    int length_of_int = ft_len_of_num(c);
    int prom;
    int j = 0;

    if (flag == 1)
    {
        res_arr[0] = '-';
        j++;
    }

    for (int i = length_of_int - 1; i >= 0; i--)
    {
        prom = (num/(ft_power(10, i))) % 10;
        res_arr[j] = prom + '0';
        j++;
    }
    return res_arr;
}

char *ft_from_decimal(char *nbr, char *base_to)
{
    int num = ft_atoi(nbr);
    int is_negative = 0;
    int sys_to = base_sys(base_to);

    if (num < 0)
    {
        num *= -1;
        is_negative = 1;
    }
    int j = 2;

    char *answer = malloc(sizeof(char) * j);

    int i = 0;
    while (num >= 1)
    {
        answer = realloc(answer, (sizeof(char) * j));
        answer[i] = base_to[num % sys_to];
        num /= sys_to;
        i++;
        j++;
    }
    answer = realloc(answer, (sizeof(char) * j));
    // я могу безусловно переписать на маллок с доп функцией (не уверен что реаллок
    // юзать можно) -- но будет больно коряво по асимптотике
    // или же вовсе сделать буфер огромный, хуле))00
    answer[i] = base_to[num];
    if (is_negative)
    {
        answer[i++] = '-';
    }
    answer[i] = '\0';
    ft_strrev(answer);

    return answer;
}

char *ft_to_decimal(char *nbr, char *base_from)
{
    int num = ft_atoi(nbr);
    int is_negative = 0;
    int sys_from = base_sys(base_from);

    if (num < 0)
    {
        num *= -1;
        nbr = ft_num_to_str(num);
        is_negative = 1;
    }
    int j = 2;

    char *answer = malloc(sizeof(char) * j);

    int i = 0;
    int power = ft_strlen(nbr) - 1;
    int res_num = 0;
    while (nbr[i])
    {
        res_num += ((nbr[i] - '0') * ft_power(sys_from, power - i));
        i++;
    }
    char *res_num_str = ft_num_to_str(res_num);
    if (is_negative)
        answer[0] = '-';
    ft_strcat(answer, res_num_str);

    return answer;
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int sys_to = base_sys(base_to);
    int sys_from = base_sys(base_from);

    if (!check_base(base_from) || !check_base(base_to))
        return "ERROR BASE\n";

    char *ans = NULL;
    char *ans_dec = NULL;
    if (sys_from == 10)
    {
        ans = ft_from_decimal(nbr, base_to);
        return ans;
    }
    else if (sys_to == 10)
    {
        ans = ft_to_decimal(nbr, base_from);
        return ans;
    }
    else
    {
        ans_dec = ft_to_decimal(nbr, base_from);
        ans = ft_from_decimal(ans_dec, base_to);
        return ans;
    }
}

int main()
{
    char *ans = ft_convert_base("144", "01234567", "01");
    int i = 0;
    while (ans[i] != '\0')
    {
        ft_putchar(ans[i]);
        i++;
    }
}