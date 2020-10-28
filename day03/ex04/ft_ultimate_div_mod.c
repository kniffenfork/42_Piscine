void ft_ultimate_div_mod(int *a, int *b)
{
    int div_a = *a;
    *a = div_a/ *b;
    *b = div_a % *b;
}

