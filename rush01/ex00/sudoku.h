#ifndef LEARN_C_SUDOKU_H
#define LEARN_C_SUDOKU_H

#include "/Users/user/Desktop/Informatiks/learn_C/day06/ex00/include/libft.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int t_bool;

typedef struct sudoku
{
    char *point;
    char **squares;

} t_sudoku;

t_bool one_in_line(struct sudoku *sudoko, char el, int nb_line);
struct	sudoku	*fill_sudoku_structure(int ac, char **av);
void show_sudoku(t_sudoku *par);
char **ft_split_all(char *str);
t_bool one_in_stolb(t_sudoku *sudoko, char el, int nb_stolb);
t_bool one_in_square(t_sudoku *sudoku, char number, int coord_line, int coord_el_in_line);

#endif //LEARN_C_SUDOKU_H
