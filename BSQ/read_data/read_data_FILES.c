#include "read_data.h"

void                 allocate_obstacles(t_data *data, int ac)
{
    data->obstacles = (char *)malloc(ac);
    data->empty_cell = (char *)malloc(ac);
    data->count_of_data_lines = (int *)malloc(sizeof(int) * (ac - 1));
    data->symbols_to_solve = (char *)malloc(ac);
}

void                 FILES_deliver_obstacles_to_the_structure_with_allocating(t_data *data, int ac, int current_file,
                                                                            int count_of_lines, char empty_cell,
                                                                            char obstacle, char symbol_to_solve)
{
    int position_in_arr = current_file - 1;

    data->empty_cell[position_in_arr] = empty_cell;

    data->count_of_data_lines[position_in_arr] = count_of_lines;

    data->symbols_to_solve[position_in_arr] = symbol_to_solve;

    data->obstacles[position_in_arr] = obstacle;
}

void                FILES_make_the_end_of_DataArrays_in_struct(t_data *data, int current_position)
{
    int position_in_arr = current_position - 1;

    data->empty_cell[position_in_arr] = '\0';

    data->symbols_to_solve[position_in_arr] = '\0';

    data->obstacles[position_in_arr] = '\0';
}

void             FILES_allocate_memory_for_DataStructure(t_data *data, int ac, char **av)
{
    //ft_putchar('1');
    int i = 1;
    int k = 0;
    int j;
    int count_of_lines_in_file;
    while (i < ac)
    {
        j = 0;
        count_of_lines_in_file = data->count_of_data_lines[k];
        data->data_lines[k] = (char **) malloc(sizeof(char *) * count_of_lines_in_file + 1);

        while (j < (count_of_lines_in_file))
        {
            data->data_lines[k][j] = (char *)malloc(count_of_lines_in_file + 1);
            j++;
        }
        k++;
        i++;
    }
}

t_data              *FILES_get_map_description(int ac, char **av)
{
    char            *map_reader = (char *)malloc(4);
    char            empty_cell;
    char            obstacle;
    char            symbol_to_solve;
    char            *counting_the_lines = (char *)malloc(100);
    int             count_of_files = (ac - 1);
    int             count_of_lines;
    int             end;
    int             i;
    int             j;

    t_data          *data_array = (t_data *)malloc(sizeof(t_data));
    data_array->data_lines = (char ***)malloc(sizeof(char **) * count_of_files + 1);
    data_array->count_of_data_lines = (int *)malloc(sizeof(int) * count_of_files + 1);

    allocate_obstacles(data_array, ac);

    int current_file = 1;

    while (av[current_file])
    {
        char *file_name = av[current_file];
        int file = open(file_name, O_RDONLY);
        char buff[1];

        if (file > 0)
        {
           while (read(file, buff, sizeof(buff)) && buff[0] != '\n')
           {
               if (FT_is_digit(buff[0]))
               {
                   counting_the_lines[i] = buff[0];
                   i++;
                   end = i;
               }
               else
               {
                   map_reader[j] = buff[0];
                   j++;
               }
               i++;
           }
           counting_the_lines[end] = '\0';
           count_of_lines = ft_atoi(counting_the_lines);
           empty_cell = map_reader[0];
           obstacle = map_reader[1];
           symbol_to_solve = map_reader[2];

           FILES_deliver_obstacles_to_the_structure_with_allocating(data_array, ac, current_file, count_of_lines,
                                                                    empty_cell, obstacle, symbol_to_solve);
           FILES_allocate_memory_for_DataStructure(data_array, ac, av);
        }
        else
        {
        FILES_deliver_obstacles_to_the_structure_with_allocating(data_array, ac, current_file, -1, '~', '~', '~');
        }
        close(file);
        current_file++;
    }
    FILES_make_the_end_of_DataArrays_in_struct(data_array, current_file);
    return data_array;
}


t_data              *FILES_read_data(int ac, char **av)
{
    char            *file_name;
    t_data *data_array = FILES_get_map_description(ac, av);
    int             current_file = 1;
    int             position_in_arr = 0;
    while (av[current_file])
    {
        file_name = av[current_file];
        int file = open(file_name, O_RDONLY);
        char buff[1];
        ft_putstr(file_name);
        if (file > 0)
        {
            int line_counting = 0;
            int flag_to_detect_the_end_of_first_line = 0;
            int k = 0;
            // сначала проскипаем первую строку
            while (read(file, buff, sizeof(buff)))
            {
                if (flag_to_detect_the_end_of_first_line == 0)
                {
                    if (*buff == '\n')
                        flag_to_detect_the_end_of_first_line = 1;
                }

                else if (*buff == '\n')
                {
                    line_counting++;
                }

                else
                {
                    data_array->data_lines[position_in_arr][line_counting][k] = *buff;
                    k++;
                }
            }
        }
        close(file);
        position_in_arr++;
        current_file++;
    }
    return data_array;
}

/*
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
*/
//TODO: запилить чтобы в структуре тип ячеек хранился
