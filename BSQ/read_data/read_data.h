#ifndef LEARN_C_READ_DATA_H
#define LEARN_C_READ_DATA_H

#define         ERROR_FORMAT_OF_INPUT           -101
#define         ERROR_IN_FILE_READING           -102

#define         INPUT_IS_ARGUMENTS_IN_CMDLINE   -201
#define         INPUT_IS_FILES                  -202


#include <unistd.h>
#include <fcntl.h>
#include "../ft/ft.h"

// functions:
int             define_type_of_input(int ac, char **av);


#endif //LEARN_C_READ_DATA_H
