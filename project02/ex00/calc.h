#ifndef LEARN_C_CALC_H
#define LEARN_C_CALC_H

#include "/Users/user/Desktop/Informatiks/learn_C/day06/ex00/include/libft.h"
#include <stdlib.h>

// bool
#define TRUE    1
#define FALSE   0

// for dinamic stack
#define INIT_SIZE   10
#define MULTIPLIER  2

// for error tracking
#define STACK_OVERFLOW      -100
#define STACK_UNDERFLOW     -101
#define OUT_OF_MEMORY       -102

// priority of operations

#define bracket     1
#define plus        2
#define minus       2
#define multiply    3
#define division    3
#define reminder    3

typedef int t_bool;

// structure of stack
typedef char *T;

typedef struct  Stack_tag // stack_of_chars;
{
    T           *data;
    size_t      size;
    size_t      top;
}               Stack_t;


// structure of calculator
typedef struct calc
{
    char       **expression_split;
    char       **polish_notation;
    char       **prom;
    int        size_of_splitted_expression;
    int        size_of_polish;

}              t_calc;

// useful functions
t_calc          *fill_calculator_structure(int ac, char **av);
char            **ft_split_whitespaces(char *str);
char            **ft_split(char *str, char *charset);
t_bool          is_digit(char *symbol);
t_bool          is_operation(char *symbol);
t_bool          is_in_string(char *string, char *symbol);
int             ft_atoi(char *str);
void            print_polish_notation(t_calc *expression);
char            *ft_num_to_str(int c);

// operations with stack
Stack_t*        createStack();
void            deleteStack(Stack_t **stack);
void            resize(Stack_t *stack);
void            push(Stack_t *stack, T value);
T               pop(Stack_t *stack);
T               peek(const Stack_t *stack);
void            implode(Stack_t *stack);
void            printStack(const Stack_t *stack);

// calculation
int             get_priority_of_operation(char *operation);
void            create_polish_notation(t_calc *expression);
int             calculate_expression(t_calc *expression);

#endif //LEARN_C_CALC_H
