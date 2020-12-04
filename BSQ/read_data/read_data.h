#ifndef LEARN_C_READ_DATA_H
#define LEARN_C_READ_DATA_H

#define         ERROR_FORMAT_OF_INPUT           -101
#define         ERROR_COUNT_OF_ARGUMENTS        -102
#define         ERROR_IN_FILE_READING           -103

#define         INPUT_IS_ARGUMENTS_IN_CMDLINE   -201
#define         INPUT_IS_FILES                  -202

#define         SUCCESS                          1


#include "../ft/ft.h"
#include <unistd.h>
#include <fcntl.h>

typedef struct              data_array

{
    char                    ***data_lines;
    int                     *count_of_data_lines;
    char                    *obstacles;
    char                    *symbols_to_solve;
    char                    *empty_cell;

}                           t_data;


// functions:
int                 define_type_of_input(int ac, char **av);
t_data              *read_data_from_files(int ac, char **av); // я бы эту хуйню разбил -- да тогда придется по файлу 2 раза пробегаться
t_data              *create_data_array(int ac, char **av);
t_data              *CMD_read_data(int ac, char **av);
void                Print_Data(t_data *data);
t_data              *CMD_get_map_description(int ac, char **av);

t_data              *FILES_get_map_description(int ac, char **av);
t_data              *FILES_read_data(int ac, char **av);

void             FILES_allocate_memory_for_DataStructure(t_data *data, int ac, char **av);

#endif //LEARN_C_READ_DATA_H
