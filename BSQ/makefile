SRC = testing.c  ./read_data/define_type_of_input.c ./ft/ft.c
SRC_test = ./read_data/define_type_of_input.c ./ft/ft.c
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
	@rm f *.o $(TEST)
	@echo "All is cleaned!"
