#include "calc.h"

void push(Stack_t *stack, T value)
{
    if (stack->size >= STACK_MAX_SIZE)
        exit(STACK_OVERFLOW);

    stack->data[stack->size] = value;
    stack->size++;
}

T pop(Stack_t *stack)
{
    if (stack->size == 0)
        exit(STACK_UNDERFLOW);

    stack->size--;

    return stack->data[stack->size];
}


T peek(const Stack_t *stack)
{
    if (stack->size <= 0)
        exit(STACK_UNDERFLOW);

    return stack->data[stack->size - 1];
}


void printStackValue(char *value)
{
    ft_putstr(value);
}

void printStack(const Stack_t *stack, void (*printStackValue)(const T)) {
    int i;
    int len = (stack->size - 1);
    ft_putnbr(stack->size);
    ft_putchar(' ');
    for (i = 0; i < len; i++) {
        printStackValue(stack->data[i]);
        ft_putstr(" | ");
    }
    if (stack->size != 0) {
        printStackValue(stack->data[i]);
    }
    ft_putchar('\n');
}