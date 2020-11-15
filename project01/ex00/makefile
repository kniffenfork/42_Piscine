SRC = match.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJECTS=$(SRC:.c=.o)
EXECUTABLE = match
LIB = /Users/user/Desktop/Informatiks/learn_C/day06/ex00/lib/libft.a

all: $(SRC) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
