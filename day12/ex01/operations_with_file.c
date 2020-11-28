#include "ft_cat.h"

/*
-b - нумеровать только непустые строки; +
-E - показывать символ $ в конце каждой строки; +
-n - нумеровать все строки; +
-s - удалять пустые повторяющиеся строки;
-T - отображать табуляции в виде ^I;
 */

void            ft_display_file(char *file_name)
{
    int file;
    char buff[1];

    file = open(file_name, O_RDONLY);

    while (read(file, buff, sizeof(buff)))
    {
        write(1, buff, sizeof(buff));
    }
    close(file);
}


void            ft_display_several_files(int ac, char **av)// я хуй знает, проверял ты это или нет, но подозреваю
//															что эта хуйня работает долго, ибо av не закончится нулем
// 															а начнет выдавать рандомную хуйню вместо аргументов когда
//															аргументы закончатся. как леволибералы кстати
//															ну и она не используется кстати
{
    int i = 1;

    if (av[1][0] == '-') // учитываем возможность добавления флага с '-' в начале
        i = 2;

    while (av[i])
    {
        ft_display_file(av[i]);
        ft_putchar('\n');
        i++;
    }
}

void            ft_print_numerize_lines(char *file_name)
{

    int file;
    char buff[1];

    file = open(file_name, O_RDONLY);
    int num_of_line = 1;
    int flag = 0; // тречит '\n', то есть конец строки
    int flag_for_start = 0; // чтобы пронумеровать и первый элемент

    while (read(file, buff, sizeof(buff)))
    {
        // собственно вывод номера каждой __непустой__ строки
        if (flag == 1 && *buff != '\n' || flag_for_start == 0)
        {
            // увлекательный подгон пробелов для выравнивания номера строк
            ft_putstr(" ");
            if (num_of_line < 10000)
                ft_putstr(" ");
            if (num_of_line < 1000)
                ft_putstr(" ");
            if (num_of_line < 100)
                ft_putstr(" ");
            if (num_of_line < 10)
                ft_putstr(" ");

            ft_putnbr(num_of_line);
            ft_putstr("   ");
            flag = 0;
            num_of_line++;
        }

        if (*buff == '\n')
        {
            flag = 1;
        }

        else if (*buff == '\t')
        {
            ft_putchar('\t');
        }

        ft_putchar(*buff);
        flag_for_start = 1;
    }
    close(file);
}

void            ft_print_numerize_all_lines(char *file_name)
{
    int file;
    char buff[1];

    file = open(file_name, O_RDONLY);
    int num_of_line = 1;
    int flag = 0;
    int flag_for_start = 0;

    while (read(file, buff, sizeof(buff)))
    {
        // вывод собственно номера каждой строки
        if (flag == 1 || flag_for_start == 0)
        {
            // увлекательный подгон пробелов для выравнивания номера строк
            // вынеси свой подгон в отдельную функцию, раз уж используешь несколько раз
            ft_putstr(" ");
            if (num_of_line < 10000)
                ft_putstr(" ");
            if (num_of_line < 1000)
                ft_putstr(" ");
            if (num_of_line < 100)
                ft_putstr(" ");
            if (num_of_line < 10)
                ft_putstr(" ");

            ft_putnbr(num_of_line);

            ft_putstr("   ");
            flag = 0;
            num_of_line++;
        }

        if (*buff == '\n')
        {
            flag = 1;
        }

        else if (*buff == '\t')
        {
            ft_putchar('\t');
        }

        ft_putchar(*buff);
        flag_for_start = 1;
    }
    close(file);
}

void            show_dollar_at_the_end_of_line(char *file_name)
{
    int file;
    char buff[1];

    file = open(file_name, O_RDONLY);

    while (read(file, buff, sizeof(buff)))
    {
        if (*buff == '\n')
            ft_putchar('$');
        ft_putchar(*buff);
    }
    close(file);
}

void            delete_repeated_empty_lines(char *file_name)
{
    int file;
    char buff[1];

    file = open(file_name, O_RDONLY);
    int count_of_empty_lines = 0;
    int flag_for_empty_line = 1; // изначально строка пустая

    while (read(file, buff, sizeof(buff)))
    {
        if (*buff != '\n' && *buff != '\t' && *buff != ' ') // это не пустая строка
        {
            count_of_empty_lines = 0;
            flag_for_empty_line = 0;
        }

        if (*buff == '\n' && flag_for_empty_line == 1) // если достигли конца с флагом пустой строки
        {
            count_of_empty_lines++; // увеличиваем количество пустых строк
        }

        if (count_of_empty_lines > 1 && *buff == '\n') // если дошли до конца строки с флагом пустой и пустых много
        {
            continue; // просто идем дальше
        }

        if (*buff == '\n')
            flag_for_empty_line = 1;

        ft_putchar(*buff);
    }
    close(file);
}

void            view_tabulation(char *file_name)
{
    int file;
    char buff[1];

    file = open(file_name, O_RDONLY);

    while (read(file, buff, sizeof(buff)))
    {
        if (*buff == '\t')
        {
            ft_putstr("^I");
            continue;
        }
        ft_putchar(*buff);
    }
    close(file);
}