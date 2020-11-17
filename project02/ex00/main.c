#include "calc.h"

int main(int ac, char **av)
{
    t_calc *ans = fill_calculator_structure(ac, av);
    create_polish_notation(ans);
    calculate_polish_notation(ans);
}