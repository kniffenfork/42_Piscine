NAME = libft.a
SRCS = srcs/
INCLUDES = include/
FUNCTIONS = ft_atoi ft_power ft_putchar ft_putnbr ft_putstr ft_split_whitespaces ft_sqrt ft_str_is_alpha \
			ft_str_is_lowercase ft_str_is_numeric ft_str_is_printable ft_str_is_uppercase ft_strcapitalize \
			ft_strcat ft_strcmp ft_strcpy ft_strlen ft_strlowcase ft_strncat ft_strncpy ft_strrev \
			ft_strstr ft_strupcase ft_swap
BINS = $(patsubst %, %.o, $(FUNCTIONS))

.PHONY: clean fclean re all

all: $(NAME)

$(BINS):
	@gcc -Wall -Werror -Wextra -c $(patsubst %.o, $(SRCS)%.c, $@) -I $(INCLUDES)

$(NAME): $(BINS)
	@ar rc $(NAME) $(BINS);
	@ranlib $(NAME);

clean:
	@rm -f $(BINS)

fclean: clean
	@rm -f $(NAME)

re: fclean all