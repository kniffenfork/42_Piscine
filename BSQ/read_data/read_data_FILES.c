#include "../read_data/read_data.h"


t_data          *FILES_read_data(int ac, char **av)
{
    //сначала аллоцируем говно
    int count_of_files = (ac - 1);
    t_data *data = (t_data *)malloc(sizeof(t_data));

    data->data_lines = (char ***)malloc(sizeof(char **) * count_of_files + 1);

    data->count_of_data_lines = (int *)malloc(sizeof(int) * count_of_files + 1);

    data->obstacles = (char *)malloc(count_of_files + 1);
    data->symbols_to_solve = (char *)malloc(count_of_files + 1);
    data->empty_cell = (char *)malloc(count_of_files + 1);

    int current_file = 1;
    int positioned_file = 0;
    int current_line;
    int counter;
    char *file_name;
    char buff[1];

    while (av[current_file])
    {
        current_line = 0;
        counter = 0;
        file_name = av[current_file];
        int file = open(file_name, O_RDONLY);
        int flag_to_allocate_memory = 0;

        if (file > 0)
        {
            while (read(file, buff, sizeof(buff)))
            {
                if (flag_to_allocate_memory == 0)
                {
                    if (*buff == '\n')
                    {
                        //ft_putnbr(data->count_of_data_lines[positioned_file]);
                        data->data_lines[positioned_file] = (char **)malloc(sizeof(char *) * data->count_of_data_lines[positioned_file]);
                        data->data_lines[positioned_file][current_line] = (char *)malloc(data->count_of_data_lines[positioned_file] * sizeof(char ));
                        flag_to_allocate_memory = 1;
                        counter = 0;
                        continue;
                    }
                    else
                    {
                        switch (counter)
                        {
                            case 0:
                                data->count_of_data_lines[positioned_file] = ft_atoi(buff);
                            case 1:
                                data->empty_cell[positioned_file] = *buff;
                            case 2:
                                data->obstacles[positioned_file] = *buff;
                            case 3:
                                data->symbols_to_solve[positioned_file] = *buff;
                        }
                    }
                }
                else
                {
                    if (*buff == '\n')
                    {
                        current_line++;
                        counter = 0;
                        data->data_lines[positioned_file][current_line] = (char *)malloc(data->count_of_data_lines[positioned_file] * sizeof(char));
                        continue;
                    }
                    else
                    {
                        data->data_lines[positioned_file][current_line][counter] = *buff;
                    }
                }
                counter++;
            }
        }
        current_file++;
        positioned_file++;
    }
    return data;
}