SRC = display_file.c
FLAGS = -Wall -Wextra -Werror
CC = @gcc
OBJECTS=$(SRC:.c=.o)
EXECUTABLE = display_file
LIB = /Users/user/Desktop/Informatiks/learn_C/day06/ex00/lib/libft.a

all: $(SRC) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $@
	@echo "BUILT SUCCESFULLY COMPLETED"

clean:
	@rm -rf *.o $(EXECUTABLE)
	@echo "ALL IS CLEANED"
