#ifndef LEARN_C_SUDOKU_H
#define LEARN_C_SUDOKU_H

#include "/Users/user/Desktop/Informatiks/learn_C/day06/ex00/include/libft.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int t_bool;

typedef struct sudoku
{
    char       *lines;
    char       *columns;
    char       *count_of_parents;
    char       **parents;

}              t_sudoku;


// operations with sudoku structure
t_sudoku    *fill_sudoku_structure(int ac, char **av);
void        show_sudoku(t_sudoku *par);


// check for uniqueness
t_bool      one_in_line(t_sudoku *sudoku, char symbol_to_try, int line);
t_bool      one_in_column(t_sudoku *sudoku, char symbol_to_try, int column);
t_bool      one_in_square(t_sudoku *sudoku, char symbol_to_try, int line, int column);
int         *go_to_start_of_square(int line, int column);
t_bool      is_unique(t_sudoku *sudoku, char symbol_to_try, int line, int column);


// solve this fucking sudoku
t_bool      check_sudoku(t_sudoku *sudoku);
int         solve(t_sudoku *sudoku);


#endif //LEARN_C_SUDOKU_H
