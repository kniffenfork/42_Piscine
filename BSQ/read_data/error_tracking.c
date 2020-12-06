#include "read_data.h"

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

void            CMD_check_that_symbols_in_line_are_correct(t_data *data, int CurrentFile, int CurrentLine)
{
    char empty_cell = data->empty_cell[CurrentFile];
    char obstacle = data->obstacles[CurrentFile];

    int Current_Symbol;
    int length_of_current_line = ft_strlen(data->data_lines[CurrentFile][CurrentLine]);
    char symbol;

    for (Current_Symbol = 0; Current_Symbol < length_of_current_line; Current_Symbol++)
    {
        symbol = data->data_lines[CurrentFile][CurrentLine][Current_Symbol];
        if ((symbol == obstacle || symbol == empty_cell) && (data->ERROR_TRACKING[CurrentFile] >= 0))
        {
            data->ERROR_TRACKING[CurrentFile] = SUCCESS;
        }
        else
        {
            data->ERROR_TRACKING[CurrentFile] = DIFFERENCE_BETWEEN_MAP_AND_DATA;
            break;
        }
    }
}


void            CMD_check_for_errors(t_data *data, int ac, char **av)
{
    int CurrentFile;
    int CurrentLine = 0;
    int CountOfFILES = CountOfFiles(ac, av);
    int num1;
    int num2;


    for (CurrentFile = 0; CurrentFile < CountOfFILES; CurrentFile++)
    {
        num1 = ft_strlen(data->data_lines[CurrentFile][CurrentLine]);
        CMD_check_that_symbols_in_line_are_correct(data, CurrentFile, 0);

        for (CurrentLine = 1; CurrentLine < data->count_of_data_lines[CurrentFile]; CurrentLine++)
        {
            num2 = ft_strlen(data->data_lines[CurrentFile][CurrentLine]);
            if (num1 != num2)
            {
                data->ERROR_TRACKING[CurrentFile] = NOT_ALL_LINES_WITH_SAME_LEN;
                break;
            }
            CMD_check_that_symbols_in_line_are_correct(data, CurrentFile, CurrentLine);
        }
        CurrentLine = 0;
    }
}

