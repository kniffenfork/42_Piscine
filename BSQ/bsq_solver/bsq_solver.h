#ifndef LEARN_C_BSQ_SOLVER_H
#define LEARN_C_BSQ_SOLVER_H

#include "../ft/ft.h"
#include "../read_data/read_data.h"
#include "../../day06/ex00/include/libft.h"

void           BSQ_solve(int ac, char **av);
void           replace_to_solve(t_data *data, int CurrentFile);// place square on map(t_map map, t_square)
/*
 * struct s_square {
 *      int size;
 *      int x;
 *      int y;
 * }
 *
 */
int            minimum(int num1, int num2, int num3);// нахуй уезжает
int            find_minimum_plus_one(t_data *data, int CurrentFile, int current_line, int position_in_line);//
int            solve_bsq_for_curr_file(t_data *data, int CurrentFile);

#endif //LEARN_C_BSQ_SOLVER_H
