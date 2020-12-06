#include "read_data.h"

int             Count_of_FILES(t_data *data)
{
    int res = 0;
    while (data->data_lines[res])
    {
        res++;
    }
    return res;
}

t_data          *create_data_array(int ac, char **av)
{
    if (define_type_of_input(ac, av) == INPUT_IS_FILES)
        return FILES_read_data(ac, av);
    else
        return CMD_read_data(ac, av);
}

void           Print_Data(t_data *data)
{
    int CountOfFiles = Count_of_FILES(data);

    for (int i = 0; i < CountOfFiles; i++)
    {
        for (int j = 0; j < data->count_of_data_lines[i]; j++)
        {
            ft_putstr(data->data_lines[i][j]);
            ft_putchar('\n');
        }
        ft_putstr("The next File:");
        ft_putchar('\n');
    }
}
