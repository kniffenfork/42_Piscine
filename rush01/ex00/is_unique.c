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

int *return_start_of_square(int line, int column)
{
    int *answer = (int *)malloc(sizeof(int) * 2);
    int line_start = 3 * (line / 3);
    int column_start = 3 * (column / 3);
    answer[0] = line_start;
    answer[1] = column_start;
    return answer;
}

t_bool one_in_square(t_sudoku *sudoku, char symbol_to_try, int line, int column)
{
    line = (return_start_of_square(line, column))[0];
    column = (return_start_of_square(line, column))[1];


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
    t_bool check1, check2, check3;

    check1 = FALSE;
    check2 = FALSE;
    check3 = FALSE;

    check1 = one_in_line(sudoku, symbol_to_try, line);
    check2 = one_in_column(sudoku, symbol_to_try, column);
    check3 = one_in_square(sudoku, symbol_to_try, line, column);
    if (check1 && check2 && check3)
        return TRUE;
    else
        return FALSE;
}