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
        return read_Data_From_CMDLine(av);
}

void           Print_Data(t_data *data, int CurrentFile)
{
    for (int j = 0; j < data->count_of_data_lines[CurrentFile]; j++)
    {
        ft_putstr(data->data_lines[CurrentFile][j]);
        ft_putchar('\n');
    }
}

