#ifndef LEARN_C_READ_DATA_H
#define LEARN_C_READ_DATA_H

#define         ERROR_FORMAT_OF_INPUT           -101
#define         ERROR_COUNT_OF_ARGUMENTS        -102
#define         ERROR_IN_FILE_READING           -103

#define         INPUT_IS_ARGUMENTS_IN_CMDLINE   -201
#define         INPUT_IS_FILES                  -202

#define         SUCCESS                          1


#include "../ft/ft.h"

typedef struct              data_array

{
    char                    ***data_lines;
    int                     *count_of_data_lines;

}                           t_data;

// functions:
int             define_type_of_input(int ac, char **av);

t_data              *read_data_from_cmdline(int ac, char **av);


#endif //LEARN_C_READ_DATA_H
