#ifndef LEARN_C_DO_OP_H
#define LEARN_C_DO_OP_H

#define error_number_of_arguments 101

#include "../../day06/ex00/include/libft.h"

// main do-op tools

int         check_for_possibility(int ac, char **av);
int         ft_do_op(int ac, char **av);
int         make_correct_values(int ac, char **av);

// functions
int             ft_is_in_string(char *string, char symbol);
int             ft_is_digit(char symbol);
int             ft_is_operation(char symbol);

#endif //LEARN_C_DO_OP_H
