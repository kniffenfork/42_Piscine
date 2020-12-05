#include "../read_data/read_data.h"

t_data          *allocate_basic_tools(int ac)
{
    int count_of_files = (ac - 1);

    t_data *data = (t_data *)malloc(sizeof(t_data));

    data->data_lines = (char ***)malloc(sizeof(char **) * count_of_files + 1);
    data->solve_helper = (int ***)malloc(sizeof(int **) * count_of_files + 1);

    data->count_of_data_lines = (int *)malloc(sizeof(int) * count_of_files);

    data->obstacles = (char *)malloc(count_of_files + 1);
    data->symbols_to_solve = (char *)malloc(count_of_files + 1);
    data->empty_cell = (char *)malloc(count_of_files + 1);

    return data;
}

void          fill_solver_helper(t_data *data, int CurrentFile, int current_line, int counter, char buff)
{
    char obstacle = data->obstacles[CurrentFile];
    char empty_cell = data->empty_cell[CurrentFile];

    if (buff == obstacle)
    {
        data->solve_helper[CurrentFile][current_line][counter] = 0;
    }
    else
        data->solve_helper[CurrentFile][current_line][counter] = 1;
}

t_data          *FILES_read_data(int ac, char **av)
{
    t_data *data = allocate_basic_tools(ac);

    int Position_in_av = 1;
    int CurrentFile = 0;
    int current_line;
    int counter;

    char *file_name;
    char buff[1];


    while (av[Position_in_av])
    {
        current_line = 0;
        counter = 0;
        file_name = av[Position_in_av];
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
                        data->data_lines[CurrentFile] = (char **)malloc(sizeof(char *) * data->count_of_data_lines[CurrentFile]);
                        data->solve_helper[CurrentFile] = (int **)malloc(sizeof(int *) * data->count_of_data_lines[CurrentFile]);
                        data->data_lines[CurrentFile][current_line] = (char *)malloc(data->count_of_data_lines[CurrentFile] * sizeof(char ));
                        data->solve_helper[CurrentFile][current_line] = (int *)malloc(data->count_of_data_lines[CurrentFile] * sizeof(char ));
                        flag_to_allocate_memory = 1;
                        counter = 0;
                        continue;
                    }
                    else
                    {
                        switch (counter)
                        {
                            case 0:
                                data->count_of_data_lines[CurrentFile] = ft_atoi(buff);
                            case 1:
                                data->empty_cell[CurrentFile] = *buff;
                            case 2:
                                data->obstacles[CurrentFile] = *buff;
                            case 3:
                                data->symbols_to_solve[CurrentFile] = *buff;
                        }
                    }
                }
                else
                {
                    if (*buff == '\n')
                    {
                        current_line++;
                        counter = 0;
                        data->data_lines[CurrentFile][current_line] = (char *)malloc(data->count_of_data_lines[CurrentFile] * sizeof(char));
                        data->solve_helper[CurrentFile][current_line] = (int *)malloc(data->count_of_data_lines[CurrentFile] * sizeof(char));
                        continue;
                    }
                    else
                    {
                        data->data_lines[CurrentFile][current_line][counter] = *buff;
                        fill_solver_helper(data, CurrentFile, current_line, counter, *buff);
                    }
                }
                counter++;
            }
        }
        Position_in_av++;
        CurrentFile++;
    }
    return data;
}