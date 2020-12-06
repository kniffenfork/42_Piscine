SRC = main.c  ./read_data/define_type_of_input.c ./ft/usable_functions.c ./ft/split.c ./bsq_solver/bsq_solver.c \
	  ./read_data/read_data_CMDline.c ./read_data/create_data_array.c ./read_data/read_data_FILES.c ./read_data/error_tracking.c
SRC_test = ./read_data/define_type_of_input.c ./ft/usable_functions.c ./ft/split.c ./bsq_solver/bsq_solver.c\
		   ./read_data/read_data_CMDline.c ./read_data/create_data_array.c ./read_data/read_data_FILES.c ./read_data/error_tracking.c
FLAGS = -Wall -Wextra -Werror
CC = @gcc
OBJECTS=$(SRC:.c=.o)
TEST=$(SRC_test:.c=.o)
EXECUTABLE = BSQ
LIB = ../day06/ex00/lib/libft.a

all: $(SRC) $(EXECUTABLE)

.PHONY: clean all

$(EXECUTABLE): $(OBJECTS)
	@echo "Buiding communism..."
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $@
	@echo "Buit successfully completed!"

clean:
	@echo "Cleaning..."
	@rm -rf *.o $(EXECUTABLE)
	@rm -f *.o $(TEST)
	@echo "All is cleaned!"
