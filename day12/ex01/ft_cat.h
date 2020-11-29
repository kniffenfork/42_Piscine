#ifndef LEARN_C_FT_CAT_H
#define LEARN_C_FT_CAT_H

#include <unistd.h>
#include <fcntl.h>
#include "../../day06/ex00/include/libft.h"

#define TRUE    1
#define FALSE   0

typedef int t_bool;

// operations with file
void            ft_display_file(char *file_name);
void            ft_display_several_files(int ac, char **av);
void            ft_print_numerize_lines(char *file_name);
void            ft_print_numerize_all_lines(char *file_name);
void            show_dollar_at_the_end_of_line(char *file_name);
void            delete_repeated_empty_lines(char *file_name);
void            view_tabulation(char *file_name);
int             ft_cat(int ac, char **av);

#endif //LEARN_C_FT_CAT_H
