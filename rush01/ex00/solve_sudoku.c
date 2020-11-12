#include "sudoku.h"


t_bool check_sudoku(t_sudoku *sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i].lines[j] == '.')
            {
                int solve = 1;
                int num_of_parent = 0;

                int propable_answer;
                while (solve != 10)
                {
                    if ((is_unique(sudoku, (solve + '0'), i, j)))
                    {
                        propable_answer = (solve + '0');
                        sudoku[i].parents[j][num_of_parent] = propable_answer;
                        sudoku[i].count_of_parents[j] += 1;
                        num_of_parent++;
                    }
                    solve++;
                }
                if (sudoku[i].count_of_parents[j] == '1')
                {
                    sudoku[i].lines[j] = propable_answer;
                    //sudoku[i].count_of_parents[j] == 0;
                }

                else if (sudoku[i].count_of_parents[j] == '0')
                {
                    ft_putstr("ERROR SUDOKU");
                    ft_putchar('\n');
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}

t_bool is_aviable(t_sudoku *sudoku, int line, int column, char num)
{
    int i;
    for (i = 0; i < 9; i++)
    {
        if (sudoku[line].lines[i] == num)
            return FALSE;
        if (sudoku[i].lines[column] == num)
            return FALSE;
        if (!one_in_square(sudoku, i, line, column))
            return FALSE;
    }
    return TRUE;
}

int solve_recursevily(t_sudoku *sudoku, int line, int column)
{
    if (line < 9 && column < 9)
    {
        if (sudoku[line].lines[column] != '.')
        {
            if ((column + 1) < 9)
                return solve_recursevily(sudoku, line, column + 1);
            else if ((line + 1) < 9)
                return solve_recursevily(sudoku, line + 1, 0);
            else
                return 1;
        }
        else
        {
            for (int i = 0; i < ft_strlen(sudoku[line].parents[column]); i++)
            {
                if (is_aviable(sudoku, line, column, sudoku[line].parents[column][i]))
                {
                    sudoku[line].lines[column] = sudoku[line].parents[column][i];

                    if (solve_recursevily(sudoku, line, column))
                        return 1;
                    else
                        sudoku[line].lines[column] = '.';
                }
            }
        }
        return 0;
    }
    else
        return 1;
}

int solve(t_sudoku *sudoku)
{
    if (check_sudoku(sudoku))
    {
        return solve_recursevily(sudoku, 0, 0);
    }
    else
        return 0;
}