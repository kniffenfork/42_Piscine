void ft_sort_integer_table(int *tab, int size)
{
    int i, j, k;
    for (i=1; i<size; i++){
        j=i;
        while ((j>0) && (tab[j] < tab[j-1])){
            k = tab[j];
            tab[j] = tab[j-1];
            tab[j-1] = k;
            j = j-1;
        }
    }
}

