#include <zconf.h>

/* скобочки расставить по другому стоит, у кернигана вроде где-то было про оформление, которым он пользовался - оно в си
  юзается почти всеми
 */
int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

void ft__print__alphabet(void)
{
	/*
	 * хорошим тоном бывает неизменяемые вещи писать как const char. тут на это похуй, а в больших проектах желательно
	 */
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i=0; alphabet[i] != '\0'; i++)
    {
    	//можно использовать putstr, а в putstr write (1, str, strlen(str));
        ft_putchar(alphabet[i]);
    }
}

int main()
{
    ft__print__alphabet();
    return 0;
}