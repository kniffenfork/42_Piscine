EXECUTABLE = btree
SRCS = main.c ex*/
FUNCTIONS =  btree_create_node btree_apply_prefix btree_apply_infix \
			 btree_apply_suffix btree_insert_data btree_search_item \
			 btree_level_count
FLAGS = -Wall -Wextra -Werror
CC = @gcc
BINS = $(patsubst %, %.o, $(FUNCTIONS))
LIB = /Users/user/Desktop/Informatiks/learn_C/day06/ex00/lib/libft.a
OBJECTS = $(BINS) main.c

.PHONY: clean all

all: $(SRCS) $(EXECUTABLE)

$(BINS): $(SRCS)
	$(CC) $(FLAGS) -c $(patsubst %.o, $(SRCS)%.c, $@)

$(EXECUTABLE): $(BINS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $@
	@echo "BUILT SUCCESFULLY COMPLETED"

clean:
	@rm -rf *.o $(EXECUTABLE)
	@echo "ALL IS CLEANED"


