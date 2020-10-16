//
// Created by Алексей Фомин on 11.10.2020.
//
#include <stdio.h>

int *swap_sort(int *list, int n)
{
    int i, j, k;
    for (i=1; i<n; i++){
        j=i;
        while ((j>0) && (list[j] < list[j-1])){
            k = list[j];
            list[j] = list[j-1];
            list[j-1] = k;
            j = j-1;
        }
    }
    return list;
}

