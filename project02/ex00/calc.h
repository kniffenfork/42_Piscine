#ifndef LEARN_C_CALC_H
#define LEARN_C_CALC_H

#include "/Users/user/Desktop/Informatiks/learn_C/day06/ex00/include/libft.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define STACK_MAX_SIZE 20

// for error tracking
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

typedef int t_bool;

// structure of stack
typedef char *T;

typedef struct Stack_tag
{
    T data[STACK_MAX_SIZE];
    size_t size;
} Stack_t;
//

// structure of calculator
typedef struct calc
{
    char       **symbol; // symbol[i] -- строка элемента, например "42", symbol[i][0] == '4'
    int        size_of_expression;
    int        prior_of_plus;
    int        prior_of_minus;
    int        prior_of_multiplication;
    int        prior_of_division;
    int        prior_of_remainder;


}              t_calc;
//

t_calc      *fill_calculator_structure(int ac, char **av);
char        **ft_split_whitespaces(char *str);

// operations with stack
void push(Stack_t *stack, char *value);
T pop(Stack_t *stack);
T peek(const Stack_t *stack);
void printStackValue(char *value);
void printStack(const Stack_t *stack, void (*printStackValue)(const T));
#endif //LEARN_C_CALC_H
