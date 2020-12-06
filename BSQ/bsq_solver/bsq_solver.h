#ifndef LEARN_C_BSQ_SOLVER_H
#define LEARN_C_BSQ_SOLVER_H

#include "../ft/ft.h"
#include "../read_data/read_data.h"
#include "../../day06/ex00/include/libft.h"

int             minimum(int num1, int num2, int num3);
int             find_minimum_plus_one(t_data *data, int CurrentFile, int current_line, int position_in_line);
int            solve_bsq_for_curr_file(t_data *data, int CurrentFile);
void            replace_to_solve(t_data *data, int CurrentFile);
void           BSQ_solve(int ac, char **av);

#endif //LEARN_C_BSQ_SOLVER_H
