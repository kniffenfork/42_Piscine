#ifndef LEARN_C_SUDOKU_H
#define LEARN_C_SUDOKU_H

#include "/Users/user/Desktop/Informatiks/learn_C/day06/ex00/include/libft.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int t_bool;

typedef struct sudoku
{
    char **lines;
    char **stolbs;
    char **square;
    char *point;
} t_sudoku;

t_bool one_in_line(struct sudoku *sudoko, char el, int nb_line);
struct	sudoku	*fill_sudoku_structure(int ac, char **av);
void show_sudoku(t_sudoku *par);


#endif //LEARN_C_SUDOKU_H
