#include "BSQ.h"
#include <time.h>
#include <stdio.h>

int main(int ac, char **av)
{
    clock_t begin = clock();
    BSQ_solve(ac, av);
    clock_t end = clock();
    ft_putchar('\n');
    ft_putstr("Time spent: ");
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f %s", time_spent, "sec\n");
}