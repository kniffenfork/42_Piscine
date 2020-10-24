#include <zconf.h>


int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

void str_to_chars(int c)
{
	/*
	 * такие функции типа конвертации лучше не делать с побочными эффектами - например выводом текста. лучше вернуть
	 * аргумент назад и вывести его в stdout уже там, где и вызываешь функцию
	 * т.е.
	 * char str[4];
	 * str[0] = c / 10 + '0';
	 * str[1] = c % 10 + '0';
	 * str[2] = ' ';
	 * str[3] = '\0';
	 * return str;
	 */
    int a1 = c / 10, a2 = c % 10;
    ft_putchar(a1 + '0');
    ft_putchar(a2 + '0');
    ft_putchar(' ');
}

void ft_print_comb2()
{
    for (int i=0; i <= 98; i++)
    {
        for (int j = i + 1; j <= 99; j++)
        {
        	/*
        	 * putstr(str_to_chars(i));
        	 * putstr(str_to_chars(j));
        	 */
            str_to_chars(i);
            str_to_chars(j);
            if (i == 98)
            {
                break;
            }
            /*
             * putstr(", ");
             */
            ft_putchar(',');
            ft_putchar(' ');
        }
    }
}

int main(){
    ft_print_comb2();
}