SRC = do-op.c main.c
FLAGS = -Wall -Wextra -Werror
CC = @gcc
OBJECTS=$(SRC:.c=.o)
EXECUTABLE = do-op
LIB = /Users/user/Desktop/Informatiks/learn_C/day06/ex00/lib/libft.a

.PHONY: clean all

all: $(SRC) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $@
	@echo "BUILT COMPLETED SUCCESSFULLY"

clean:
	@rm -rf *.o $(EXECUTABLE)
	@echo "ALL IS CLEANED"

