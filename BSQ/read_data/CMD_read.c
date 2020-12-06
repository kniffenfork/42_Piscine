#include "./read_data.h"

int                  count_of_the_maps(char **av)
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

int                 av_i_is_map_description(int CurrentLine, char **av)
{
    if (FT_is_digit(av[CurrentLine][0]))
        return 1;

    return 0;
}

void                 deliver_obstacles_to_the_structure_with_allocating(t_data *data,
                                                                            int CurrentMap,
                                                                            char **av,
                                                                            int count_of_lines,
                                                                            char empty_cell,
                                                                            char obstacle,
                                                                            char symbol_to_solve)
{
    int CountOfTheMaps = CMD_count_of_the_maps(av);

    data->empty_cell = (char *) malloc(CountOfTheMaps + 1);
    data->count_of_data_lines = (int *) malloc(sizeof(int) * CountOfTheMaps + 1);
    data->obstacles = (char *) malloc(CountOfTheMaps + 1);
    data->symbols_to_solve = (char *) malloc(CountOfTheMaps + 1);

    data->empty_cell[CurrentMap] = empty_cell;

    data->count_of_data_lines[CurrentMap] = count_of_lines;

    data->symbols_to_solve[CurrentMap] = symbol_to_solve;

    data->obstacles[CurrentMap] = obstacle;
}

t_data              *allocating_basic_tools(char **av)
{
    int CountOfFiles = count_of_the_maps(av);

    t_data *data = (t_data *)malloc(sizeof(t_data));

    data->data_lines = (char ***)malloc(sizeof(char **) * CountOfFiles + 1);

    data->solve_helper = (int ***)malloc(sizeof(int **) * CountOfFiles + 1);

    data->count_of_data_lines = (int *)malloc(sizeof(int) * CountOfFiles + 1);

    data->obstacles = (char *)malloc(CountOfFiles + 1);

    data->empty_cell = (char *)malloc(CountOfFiles + 1);

    data->symbols_to_solve = (char *)malloc(CountOfFiles + 1);

    data->solve_helper = (int ***)malloc(sizeof(int **) * CountOfFiles + 1);

    return data;
}


void              get_map_description(t_data *data, int CurrentFile, int PositionInAv, char **av)
{
    char counting_the_lines_in_map[100];
    int i = 0;
    while (FT_is_digit(av[PositionInAv][i]))
    {
        counting_the_lines_in_map[i] = av[PositionInAv][i];
        i++;
    }
    counting_the_lines_in_map[i] = '\0';

    int CountOfLinesInMAP = ft_atoi(counting_the_lines_in_map);

    data->count_of_data_lines[CurrentFile] = CountOfLinesInMAP;

    data->empty_cell[CurrentFile] = av[PositionInAv][i];
    data->obstacles[CurrentFile] = av[PositionInAv][i + 1];
    data->symbols_to_solve[CurrentFile] = av[PositionInAv][i + 2];
}

void             fill_solve_helper(t_data *data, int CurrentFile, int CurrentLine, int Position_in_av, char **av)
{
    int CountOfLines = data->count_of_data_lines[CurrentFile];
    int *solve_helper = (int *)malloc(sizeof(int) * 5000 + 1);
    int i = 0;
    while (av[Position_in_av][i])
    {
        if (av[Position_in_av][i] == data->empty_cell[CurrentFile])
            solve_helper[i] = 1;
        else
            solve_helper[i] = 0;
        i++;
    }
    solve_helper = (int *)realloc(solve_helper, sizeof(int) * i + 1);
    data->solve_helper[CurrentFile][CurrentLine] = solve_helper;
}

t_data          *read_Data_From_CMDLine(char **av)
{
    t_data *data = allocating_basic_tools(av);

    int Position_in_av_I;
    int Position_in_av = 1;
    int CurrentFile = -1;
    int CurrentLine = 0;

    while (av[Position_in_av])
    {
        if (av_i_is_map_description(Position_in_av, av))
        {
            CurrentFile++;
            CurrentLine = 0;
            get_map_description(data, CurrentFile, Position_in_av, av);
            data->data_lines[CurrentFile] = (char **)malloc(sizeof(char *) * data->count_of_data_lines[CurrentFile] + 1);
            data->solve_helper[CurrentFile] = (int **)malloc(sizeof(int *) * data->count_of_data_lines[CurrentFile] + 1);
        }
        else
        {
            data->data_lines[CurrentFile][CurrentLine] = av[Position_in_av];
            fill_solve_helper(data, CurrentFile, CurrentLine, Position_in_av, av);
            CurrentLine++;

        }
        Position_in_av++;
    }
    data->data_lines[CurrentFile + 1] = NULL;
    data->solve_helper[CurrentFile + 1] = NULL;
    return data;
}

