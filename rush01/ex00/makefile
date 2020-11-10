SRC = main.c fill_sudoku_structure.c one_in_line.c show_sudoku.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJECTS=$(SRC:.c=.o)
EXECUTABLE = sudoku
LIB = /Users/user/Desktop/Informatiks/learn_C/day06/ex00/lib/libft.a

all: $(SRC) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

