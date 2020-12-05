#include "bsq_solver.h"



t_data          solve_bsq_for_curr_file(t_data *data, int CurrentFile)
{
    char obstacle = data->obstacles[CurrentFile];
    char empty_cell = data->empty_cell[CurrentFile];
    char symbol_to_solve = data->symbols_to_solve[CurrentFile];
    int count_of_lines = data->count_of_data_lines[CurrentFile];

    int num_of_line = 0;
    int position_in_line = 0;

    while (num_of_line < count_of_lines)
    {
        while (position_in_line < count_of_lines)
        {

            position_in_line++;
        }
        num_of_line++;
    }
}