/*
 * бля, смотри что тебе компилятор говорит, когда компилишь:
 *ft_strncpy.c:10:12: warning: incompatible pointer types returning 'char *' from a function with result type 'int *' [-Wincompatible-pointer-types]
 * ft_strstr.c:14:17: warning: incompatible integer to pointer conversion assigning to 'char *' from 'char'; take the address with & [-Wint-conversion]
	ворнинги опаснее error`ов даже, ибо ебнут не знаешь когда, еррор хотя бы не скомпилится даже
 и сделай на мейкфайле вместо bash, там суть такая же будет, но запускать через make в консоль. заодно еще сделай make clean && make fclean && make re
 */
int* ft_strncpy(char *dest, char *src, unsigned int n)
{
    int i = 0;
    while (i != n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

