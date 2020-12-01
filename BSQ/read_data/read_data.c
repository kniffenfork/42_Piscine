#include "read_data.h"


t_data              *allocate_memory_for_DataStructure_inCmdLine(int ac, char **av)
{
    char            *counting_of_lines = (char *)malloc(100);
    char            *map_description = av[1];

    int             i = 0;
    while (map_description[i])
    {
        if (FT_is_digit(map_description[i]))
        {
            counting_of_lines[i] = map_description[i];
            i++;
        }
        else
            break;
    }

    counting_of_lines[i] = '\0';

    int             count_of_lines = ft_atoi(counting_of_lines);
    char            empty_cell = map_description[i];
    char            obstacle   = map_description[i + 1];
    char            symbol_to_solve = map_description[i + 2];

    t_data          *data_array = (t_data *)malloc(sizeof(t_data));

    data_array->empty_cell = (char *)malloc(2);
    data_array->obstacles = (char *)malloc(2);
    data_array->symbols_to_solve = (char *)malloc(2);

    data_array->empty_cell[0] = empty_cell;
    data_array->empty_cell[1] = '\0';

    data_array->obstacles[0] = obstacle;
    data_array->obstacles[1] = '\0';

    data_array->symbols_to_solve[0] = symbol_to_solve;
    data_array->symbols_to_solve[1] = '\0';

    data_array->data_lines = (char ***)malloc(sizeof(char **));
    data_array->data_lines[0] = (char **)malloc(sizeof(char *) * count_of_lines + 1);

    data_array->count_of_data_lines = (int *)malloc(sizeof(int) + 1);
    data_array->count_of_data_lines[0] = count_of_lines;

    i = 0;
    while (i < data_array->count_of_data_lines[0])
    {
        data_array->data_lines[0][i] = malloc(5);
        i++;
    }

    free(counting_of_lines);

    return data_array;
}


t_data              *read_data_from_cmdline(int ac, char **av)
{
    t_data *data_array = allocate_memory_for_DataStructure_inCmdLine(ac, av);

    int i = 2;
    int j = 0;
    while (av[i])
    {
        data_array->data_lines[0][j] = av[i];
        i++;
        j++;
    }
    data_array->data_lines[0][i] = NULL;
    return data_array;
}


//TODO: сделать аналогично коммандной строке заполнение структуры пустых заполненных ячеек
t_data              *read_data_from_files(int ac, char **av) // я бы эту хуйню разбил -- да тогда придется по файлу 2 раза пробегаться
{
    int             count_of_files = (ac - 1);

    t_data          *data_array = (t_data *)malloc(sizeof(t_data));
    data_array->data_lines = (char ***)malloc(sizeof(char **) * count_of_files + 1);
    data_array->count_of_data_lines = (int *)malloc(sizeof(int) * count_of_files + 1);

    int current_file = 1;
    int file_pos_in_arr = 0;

    while (av[current_file])
    {
        char *file_name = av[current_file];
        int file = open(file_name, O_RDONLY);
        char buff[1];

        if (file > 0)
        {
            char *count_of_lines = (char *)malloc(100);
            int i = 0;

            while(read(file, buff, sizeof(buff)) && *buff != '.')
            {
                count_of_lines[i] = *buff;
                i++;
            }
            count_of_lines[i] = '\0';
            int num_of_lines = ft_atoi(count_of_lines);
            data_array->count_of_data_lines[file_pos_in_arr] = num_of_lines;
            data_array->data_lines[file_pos_in_arr] = (char **)malloc(sizeof(char *) * num_of_lines + 1);

            int j = 0;
            while (read(file, buff, sizeof(buff)) && j < num_of_lines)
            {
                data_array->data_lines[file_pos_in_arr][j] = malloc(5);
                j++;
            }
            free(count_of_lines);
            close(file);
        }
        else
        {
            data_array->count_of_data_lines[file_pos_in_arr] = 0;
            data_array->data_lines[file_pos_in_arr] = NULL;
        }
        current_file++;
        file_pos_in_arr++;
    }
    return data_array;
}


t_data          *create_data_array(int ac, char **av)
{
    if (define_type_of_input(ac, av) == INPUT_IS_FILES)
        return read_data_from_files(ac, av);
    else
        return read_data_from_cmdline(ac, av);
}

void           Print_Data(t_data *data)
{
    if (data)
    {
        ft_putnbr(data->count_of_data_lines[0]);
        ft_putchar('\n');
        int i = 0;
        while (data->data_lines[0][i]) {
            ft_putstr(data->data_lines[0][i]);
            ft_putchar('\n');
            i++;
        }
    }
    else
        return;

    ft_putchar('\n');
    ft_putstr("obstacle: ");
    ft_putchar(data->obstacles[0]);
    ft_putchar('\n');
    ft_putchar(data->symbols_to_solve[0]);
    ft_putchar('\n');
    ft_putchar(data->empty_cell[0]);
}

//TODO: запилить чтобы в структуре тип ячеек хранился
