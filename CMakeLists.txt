cmake_minimum_required(VERSION 3.17)
project(learn_C C)


set(CMAKE_C_STANDARD 99)

add_executable(learn_C day06/ex00/include/libft.h day07/ex05/ft_print_words_tables.c day07/ex04/ft_split_whitespaces.c)

target_link_libraries(learn_C /Users/user/Desktop/Informatiks/learn_C/day06/ex00/lib/libft.a)