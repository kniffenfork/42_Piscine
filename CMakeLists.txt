cmake_minimum_required(VERSION 3.17)
project(learn_C C)


set(CMAKE_C_STANDARD 99)

add_executable(learn_C day06/ex00/include/libft.h day08/ex05/ft_stock_par.h day08/ex05/ft_param_to_tab.c day08/ex05/main.c day08/ex05/ft_stock_par.h day08/ex05/ft_param_to_tab.c day08/ex06/ft_show_tab.c rush01/ex00/sudoku.h rush01/ex00/main.c)

target_link_libraries(learn_C /Users/user/Desktop/Informatiks/learn_C/day06/ex00/lib/libft.a)