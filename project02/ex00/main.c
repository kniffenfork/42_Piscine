#include "calc.h"

int main(int ac, char **av)
{

    t_calc *ans = fill_calculator_structure(ac, av);

    Stack_t stack;
    stack.size = 0;

    push(&stack, "42");
    printStack(&stack, printStackValue);
    push(&stack, "HUI");
    printStack(&stack, printStackValue);
    push(&stack, "GOVNO");
    printStack(&stack, printStackValue);
    ft_putstr(pop(&stack));
    ft_putchar('\n');
    ft_putstr(pop(&stack));
    ft_putchar('\n');
    ft_putstr(pop(&stack));
    ft_putchar('\n');
    ft_putstr(pop(&stack));
    ft_putchar('\n');
    pop(&stack);
    pop(&stack);
    pop(&stack);


    //printStack(&stack, printStackValue);
    //ft_putstr(pop(&stack));
    //printStack(&stack, printStackValue);
    //ft_putstr(pop(&stack));
    //printStack(&stack, printStackValue);

}