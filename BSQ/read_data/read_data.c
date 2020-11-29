#include "read_data.h"


t_data              *allocate_memory_for_DataStructure_inCmdLine(int ac, char **av)
{
    int count_of_lines = ft_atoi(FT_split(av[1], ".")[0]);

    t_data          *data_array = (t_data *)malloc(sizeof(t_data));

    data_array->data_lines = (char ***)malloc(sizeof(char **));
    data_array->data_lines[0] = (char **)malloc(sizeof(char *) * count_of_lines + 1);

    data_array->count_of_data_lines = (int *)malloc(sizeof(int) + 1);
    data_array->count_of_data_lines[0] = count_of_lines;

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


