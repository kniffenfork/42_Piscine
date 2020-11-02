#include <zconf.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
    return 0;
}

char *ft_strrev(char *str)
{
    for (int i = 0; i < ft_strlen(str) / 2; i++)
    {
        char temp;
        temp = str[i];
        str[i] = str[ft_strlen(str) - i - 1];
        str[ft_strlen(str) - i - 1] = temp;
    }
    return str;
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

void ft_putnbr_base(int nb, const char *base)
{//короче длинная очень функция, разбить хорошо бы
	int i = 0;
	int flag = 0;
	int sys = 0;
	char answer[100];

	while (base[sys])
    {
		if (base[sys] == '-' || base[sys] == '+' || ft_count_in_str(base, base[sys]) > 1)
		{
			_exit(0);
		}
		sys++;
	}
	if (sys <= 1)
	{
		_exit(0);
	}

	if (nb < 0)
    {
        nb *= -1;
        flag = 1;
    }
    while (nb > sys)
    {
        answer[i] = base[nb % sys];
        nb /= sys;
        i++;
    }
    answer[i] = base[nb];
    if (flag == 1)
    {
        answer[i + 1] = '-';
        i++;
    }
    answer[i + 1] = '\0';
    ft_strrev(answer);
    ft_putstr(answer);
}
