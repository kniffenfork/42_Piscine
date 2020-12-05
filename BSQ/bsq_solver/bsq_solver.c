#include "bsq_solver.h"

int             minimum(int num1, int num2, int num3)
{
    if (num1 <= num2 && num1 <= num3)
        return num1;
    else if (num2 <= num1 && num2 <= num3)
        return num2;
    else
        return num3;
}

int             find_minimum_plus_one(t_data *data, int CurrentFile, int current_line, int position_in_line)
{
    int ans;
    if (position_in_line == 0)
        return 1;
    else
    {
        int num1 = data->solve_helper[CurrentFile][current_line - 1][position_in_line];
        int num2 = data->solve_helper[CurrentFile][current_line - 1][position_in_line - 1];
        int num3 = data->solve_helper[CurrentFile][current_line][position_in_line - 1];

        ans = (minimum(num1, num2, num3) + 1);
        return ans;
    }
}

int          solve_bsq_for_curr_file(t_data *data, int CurrentFile)
{
    int count_of_lines = data->count_of_data_lines[CurrentFile];
    char current_symbol;

    int num_of_line;
    int position_in_line;

    int maximum = 1;

    for (num_of_line = 1; num_of_line < count_of_lines; num_of_line++)
    {
        for (position_in_line = 0; position_in_line < count_of_lines; position_in_line++)
        {
            current_symbol = data->solve_helper[CurrentFile][num_of_line][position_in_line];

            if (current_symbol != 0)
            {
                data->solve_helper[CurrentFile][num_of_line][position_in_line] = find_minimum_plus_one(data, CurrentFile, num_of_line, position_in_line);

                if (data->solve_helper[CurrentFile][num_of_line][position_in_line] > maximum)
                    maximum = data->solve_helper[CurrentFile][num_of_line][position_in_line];
            }
        }
    }
    return maximum;
}

void            fill_solution(t_data *data, int CurrentFile, int current_line, int position_in_line, int maximum)
{
    int i;
    int j;
    char symbol_to_solve = data->symbols_to_solve[CurrentFile];

    for (i = current_line; i > (current_line - maximum); i--)
    {
        for (j = position_in_line; j > (position_in_line - maximum); j--)
        {
            data->data_lines[CurrentFile][i][j] = symbol_to_solve;
        }
    }
}

void            replace_to_solve(t_data *data, int CurrentFile)
{
    solve_bsq_for_curr_file(data, CurrentFile);
    int maximum = solve_bsq_for_curr_file(data, CurrentFile);

    char current_symbol;
    int num_of_line;
    int position_in_line;
    int count_of_lines = data->count_of_data_lines[CurrentFile];

    for (num_of_line = 1; num_of_line < count_of_lines; num_of_line++)
    {
        for (position_in_line = 0; position_in_line < count_of_lines; position_in_line++)
        {
            current_symbol = data->solve_helper[CurrentFile][num_of_line][position_in_line];

            if (current_symbol == maximum)
            {
                fill_solution(data, CurrentFile, num_of_line, position_in_line, maximum);
                return;
            }
        }
    }
}

t_data          *BSQ_solve(int ac, char **av)
{
    t_data *data = create_data_array(ac, av);

    int CurrentFile = 0;
    int current_line = 0;
    int position_in_line = 0;

    while (data->data_lines[CurrentFile])
    {
        replace_to_solve(data, CurrentFile);
        CurrentFile++;
    }
    return data;
}