#include "sudoku.h"

t_bool one_in_line(t_sudoku *sudoku, char symbol_to_try, int line)
{
    int i = line;
    int j = 0;
    while (sudoku[i].lines[j])
    {
        if (symbol_to_try == sudoku[line].lines[j])
            return FALSE;
        j++;
    }
    return TRUE;
}

t_bool one_in_column(t_sudoku *sudoku, char symbol_to_try, int column)
{
    int i = column;
    int j = 0;
    while (sudoku[i].columns[j])
    {
        if (symbol_to_try == sudoku[i].columns[j])
            return FALSE;
        j++;
    }
    return TRUE;
}

int *go_to_start_of_square(int line, int column)
{
    int *answer = (int *)malloc(8);
    int line_start = 3 * (line / 3);
    int column_start = 3 * (column / 3);
    answer[0] = line_start;
    answer[1] = column_start;
    return answer;
}

t_bool one_in_square(t_sudoku *sudoku, char symbol_to_try, int line, int column)
{
    line = (go_to_start_of_square(line, column))[0];
    column = (go_to_start_of_square(line, column))[1];


    for (int i = line; i < (line + 3); i++)
    {
        for (int j = column; j < (column + 3); j++)
        {
            if (symbol_to_try == sudoku[i].lines[j])
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

t_bool is_unique(t_sudoku *sudoku, char symbol_to_try, int line, int column)
{
    if (one_in_line(sudoku, symbol_to_try, line) && one_in_column(sudoku, symbol_to_try, column) && \
    one_in_square(sudoku, symbol_to_try, line, column))
        return TRUE;
    else
        return FALSE;
}