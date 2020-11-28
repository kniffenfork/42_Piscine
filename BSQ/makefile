SRCS = main.c read_data/ ft/ bsq_solver/
EXECUTABLE = BSQ
FUNCTIONS =
CC = @gcc 
FLAGS = -Wall -Wextra -Werror
BINS = $(patsubst %, %.o, $(FUNCTIONS))
OBJECTS = $(BINS) main.c

.PHONY clean all

all: $(SRCS) $(EXECUTABLE)

$(BINS): $(SRCS)
	$(CC) $(FLAGS) -c $(patsubst %.o, $(SRCS)%.c, $@)

$(EXECUTABLE): $(BINS)
	@echo "Building communism..."
	$(CC) $(FLAGS) $(OBJECTS) -o $@
	@echo "Built completed successfully"

clean:
	@echo "Processing cleaning..."
	@rm -rf *.o $(EXECUTABLE)
	@echo "Cleaning successfully completed!"
