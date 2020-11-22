cmake_minimum_required(VERSION 3.17)
project(learn_C C)


set(CMAKE_C_STANDARD 99)

add_executable(learn_C day06/ex00/include/libft.h day08/ex05/ft_stock_par.h day08/ex05/ft_param_to_tab.c day08/ex05/main.c day08/ex05/ft_stock_par.h day08/ex05/ft_param_to_tab.c day08/ex06/ft_show_tab.c rush01/ex00/sudoku.h rush01/ex00/main.c rush01/ex00/one_in_str.c rush01/ex00/one_in_square.c rush01/ex00/fill_sudoku_structure.c rush01/ex00/show_sudoku.c rush01/ex00/ft_split_all.c rush01/ex00/one_in_stolb.c rush01/ex00/is_unique.c rush01/ex00/solve_sudoku.c project01/ex00/match.c project01/proj01.h project01/ex01/nmatch.c project02/ex00/calc.h project02/ex00/main.c project02/ex00/calc.c project02/ex00/position_brackets.c project02/ex00/fill_calculator_structure.c project02/ex00/check_for_brackets.c project02/ex00/operations_with_stack.c project02/ex00/functions.c day10/ex01/ft_foreach.c day10/ex03/ft_any.c day10/ex02/ft_map.c day10/ex04/ft_count_if.c day10/ex05/ft_is_sort.c day10/ex06/do-op.c day10/ex06/do-op.h day10/ex06/ft.c day10/ex06/main.c day10/ex06/create_correct_output.c day10/ex06/make_correct_values.c day10/ex07/ft_sort_wordtab.c project01/ft_advanced_sort_wordtab.c day10/ex08/ft_advanced_sort_wordtab.c)

target_link_libraries(learn_C /Users/user/Desktop/Informatiks/learn_C/day06/ex00/lib/libft.a)