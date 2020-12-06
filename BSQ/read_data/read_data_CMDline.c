#include "read_data.h"

int                  CMD_count_of_the_maps(char **av)
{
    int res = 0;
    int i = 1;
    while (av[i])
    {
        if (FT_is_digit(av[i][0]))
        {
            res++;
        }
        i++;
    }
    return res;
}

void                 CMD_deliver_obstacles_to_the_structure_with_allocating(t_data *data,
                                                                            int count_of_lines,
                                                                            char empty_cell,
                                                                            char obstacle,
                                                                            char symbol_to_solve)
{
    data->empty_cell = (char *) malloc(2);
    data->count_of_data_lines = (int *) malloc(sizeof(int) + 1);
    data->obstacles = (char *) malloc(2);
    data->symbols_to_solve = (char *) malloc(2);

    data->empty_cell[0] = empty_cell;
    data->empty_cell[1] = '\0';

    data->count_of_data_lines[0] = count_of_lines;

    data->symbols_to_solve[0] = symbol_to_solve;
    data->symbols_to_solve[1] = '\0';

    data->obstacles[0] = obstacle;
    data->obstacles[1] = '\0';
}


t_data               *CMD_get_map_description(int ac, char **av)
{
    t_data              *data_array = (t_data *) malloc(sizeof(t_data));
    char                *counting_lines = (char *) malloc(100);
    int                 count_of_lines;
    char                empty_cell;
    char                obstacle;
    char                symbol_to_solve;
    int                 i;
    char                *map_description = av[1];

    i = 0;
    while (map_description[i])
    {
        if (FT_is_digit(map_description[i]))
        {
            counting_lines[i] = map_description[i];
            i++;
        }
        else
            break;
    }

    counting_lines[i] = '\0';

    count_of_lines = ft_atoi(counting_lines);
    empty_cell = map_description[i];
    obstacle = map_description[i + 1];
    symbol_to_solve = map_description[i + 2];

    CMD_deliver_obstacles_to_the_structure_with_allocating(data_array, count_of_lines, empty_cell, obstacle, symbol_to_solve);

    free(counting_lines);

    return data_array;
}



t_data              *CMD_allocate_memory_for_DataStructure(int ac, char **av)
{
    t_data *data_array = CMD_get_map_description(ac, av);

    data_array->data_lines = (char ***)malloc(sizeof(char **));
    data_array->data_lines[0] = (char **)malloc(sizeof(char *) * data_array->count_of_data_lines[0] + 1);

    int i = 0;
    while (i < data_array->count_of_data_lines[0])
    {
        data_array->data_lines[0][i] = (char *)malloc( data_array->count_of_data_lines[0] + 1);
        i++;
    }

    return data_array;
}


t_data              *CMD_read_data(int ac, char **av)
{
    t_data *data_array = CMD_allocate_memory_for_DataStructure(ac, av);

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
