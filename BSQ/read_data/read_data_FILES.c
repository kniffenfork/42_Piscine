#include "../read_data/read_data.h"

t_data          *allocate_basic_tools(int ac)
{
    int count_of_files = (ac - 1);

    t_data *data = (t_data *)malloc(sizeof(t_data));

    data->data_lines = (char ***)malloc(sizeof(char **) * count_of_files + 1);

    data->solve_helper = (int ***)malloc(sizeof(int **) * count_of_files + 1);

    data->count_of_data_lines = (int *)malloc(sizeof(int) * count_of_files);

    data->ERROR_TRACKING = (int *)malloc(sizeof(int) * count_of_files + 1);

    data->length_of_the_lines = (int **)malloc(sizeof(int *) * count_of_files + 1);

    data->obstacles = (char *)malloc(count_of_files + 1);
    data->symbols_to_solve = (char *)malloc(count_of_files + 1);
    data->empty_cell = (char *)malloc(count_of_files + 1);

    return data;
}

void          fill_solver_helper(t_data *data, int CurrentFile, int current_line, int counter, char buff)
{
    char obstacle = data->obstacles[CurrentFile];

    if (buff == obstacle)
    {
        data->solve_helper[CurrentFile][current_line][counter] = 0;
    }
    else
        data->solve_helper[CurrentFile][current_line][counter] = 1;
}

void            check_for_difference_between_symbol_and_map_definition(t_data *data, int CurrentFile, char *buff)
{
    char empty_cell = data->empty_cell[CurrentFile];
    char obstacle = data->obstacles[CurrentFile];

    if ((*buff == empty_cell || *buff == obstacle) && (data->ERROR_TRACKING[CurrentFile] >= 0))
    {
        data->ERROR_TRACKING[CurrentFile] = SUCCESS;
    }
    else
        data->ERROR_TRACKING[CurrentFile] = DIFFERENCE_BETWEEN_MAP_AND_DATA;
}

void            check_that_all_lines_have_the_same_length(t_data *data, int ac, char **av)
{
    int CountOfFILES = CountOfFiles(ac, av);
    int CurrentFile;
    int CurrentLine;
    int num1;
    int num2;
    for (CurrentFile = 0; CurrentFile < CountOfFILES; CurrentFile++)
    {
        if (data->length_of_the_lines[CurrentFile])
        {
            num1 = data->length_of_the_lines[CurrentFile][0];
            for (CurrentLine = 1; CurrentLine < data->count_of_data_lines[CurrentFile]; CurrentLine++)
            {
                num2 = data->length_of_the_lines[CurrentFile][CurrentLine];
                if (num1 != num2)
                {
                    data->ERROR_TRACKING[CurrentFile] = NOT_ALL_LINES_WITH_SAME_LEN;
                    break;
                }
            }
        }
    }
}

t_data          *FILES_read_data(int ac, char **av)
{
    t_data *data = allocate_basic_tools(ac);

    int Position_in_av = 1;
    int CurrentFile = 0;
    int current_line;
    int counter;
    int length_of_current_line;

    char *file_name;
    char buff[1];


    while (av[Position_in_av])
    {
        char *counting_lines = malloc(100);
        current_line = 0;
        counter = 0;
        file_name = av[Position_in_av];
        int file = open(file_name, O_RDONLY);
        int flag_to_allocate_memory = 0;
        int flag_to_counting_lines = 0;

        if (file > 0)
        {
            while (read(file, buff, sizeof(buff)))
            {
                if (flag_to_allocate_memory == 0)
                {
                    if (*buff == '\n')
                    {
                        data->data_lines[CurrentFile] = (char **)malloc(sizeof(char *) * data->count_of_data_lines[CurrentFile] + 1);
                        data->solve_helper[CurrentFile] = (int **)malloc(sizeof(int *) * data->count_of_data_lines[CurrentFile] + 1);

                        data->data_lines[CurrentFile][current_line] = (char *)malloc(5000 * sizeof(char)); // ну больше 5000 строк там вряд ли будет
                        data->solve_helper[CurrentFile][current_line] = (int *)malloc(5000 * sizeof(int));
                        data->length_of_the_lines[CurrentFile] = (int *)malloc(data->count_of_data_lines[CurrentFile] * sizeof(int) + 1);

                        flag_to_allocate_memory = 1;
                        counter = 0;
                        continue;
                    }
                    else
                    {
                        if (FT_is_digit(*buff))
                        {
                            counting_lines[counter] = *buff;
                            flag_to_counting_lines = 0;
                        }
                        else if (flag_to_counting_lines == 1)
                        {
                            counting_lines[counter] = '\0';
                            data->count_of_data_lines[CurrentFile] = ft_atoi(counting_lines);
                            data->empty_cell[CurrentFile] = *buff;
                        }
                        else
                        {
                            switch (flag_to_counting_lines)
                            {
                                case 2: data->obstacles[CurrentFile] = *buff;
                                case 3: data->symbols_to_solve[CurrentFile] = *buff;
                            }
                        }
                        flag_to_counting_lines++;
                    }
                }
                else
                {
                    if (*buff == '\n')
                    {
                        data->length_of_the_lines[CurrentFile][current_line] = counter;
                        current_line++;
                        counter = 0;
                        data->data_lines[CurrentFile][current_line] = (char *)malloc(data->count_of_data_lines[CurrentFile] * sizeof(char) + 1);
                        data->solve_helper[CurrentFile][current_line] = (int *)malloc(data->count_of_data_lines[CurrentFile] * sizeof(int) + 1);
                        continue;
                    }
                    else
                    {
                        check_for_difference_between_symbol_and_map_definition(data, CurrentFile, buff);
                        data->data_lines[CurrentFile][current_line][counter] = *buff;
                        fill_solver_helper(data, CurrentFile, current_line, counter, *buff);
                    }
                }
                counter++;
            }
            data->data_lines[CurrentFile][current_line] = NULL;
            data->solve_helper[CurrentFile][current_line] = NULL;
            data->data_lines[CurrentFile][current_line] = (char *)realloc(data->data_lines[CurrentFile][current_line], length_of_current_line * sizeof(char) + 1);
            data->solve_helper[CurrentFile][current_line] = (int *)realloc(data->data_lines[CurrentFile][current_line], length_of_current_line * sizeof(int) + 1);
            close(file);
        }
        CurrentFile++;
        Position_in_av++;
    }
    data->data_lines[CurrentFile] = NULL;
    check_that_all_lines_have_the_same_length(data, ac, av);
    return data;
}