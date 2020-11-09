#ifndef LEARN_C_SUDOKU_H
#define LEARN_C_SUDOKU_H

#include "/Users/user/Desktop/Informatiks/learn_C/day06/ex00/include/libft.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int t_bool;

t_bool one_in_str(char *line, char el);

struct sudoku
{
    char **lines;
    char **stolbs;
    char **square;
};

#endif //LEARN_C_SUDOKU_H
