#include <unistd.h>
#include <fcntl.h>
#include "../../day06/ex00/include/libft.h" //бля, то есть ты умеешь нормально путь прописывать, но просто так издеваешься
// 												надо мной. пиздец.
int check_on_errors(int ac);
void        ft_display_file(int ac, char **av);

const int ERROR = -1;
const int OK = 1;

int main(int ac, char **av)
{
	ft_display_file(ac, av);
}
/*
 * 1. обработку ошибок желательно вынести в отдельную функцию
 * 2. нет смысла писать putstr("123"); putchar('\n'); можно просто putstr("123\n");
 */
void             ft_display_file(int ac, char **av)
{
    int		file;
    char	buff[1];
	int		check;

	check = check_on_errors(ac);
    if (check != ERROR)
	{
		char *name = av[1];

		file = open(name, O_RDONLY);
		if (file > 0)
		{
			while (read(file, buff, sizeof(buff)))
			{
				write(1, buff, sizeof(buff));
			}
			close(file);
		} else {
			ft_putstr("Cannot open file.\n");
		}
	} else {
    	return;
    }
}

int check_on_errors(int ac)
{
	if (ac > 2)
	{
		ft_putstr("Too many arguments.\n");
		return ERROR;
	}
	else if (ac < 2)
	{
		ft_putstr("File name missing\n");
		return ERROR;
	}
	return OK;
}