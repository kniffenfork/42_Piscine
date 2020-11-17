SRC = main.c calc.c fill_calculator_structure.c  operations_with_stack.c ft_split.c functions.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJECTS=$(SRC:.c=.o)
EXECUTABLE = calc
LIB = /Users/user/Desktop/Informatiks/learn_C/day06/ex00/lib/libft.a

all: $(SRC) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
