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

int main(){
    int s[5] = {5, 4, 3, 2, 1};
    swap_sort(s, 5);
    for (int i=0; i<5; i++){
        printf("%d ", s[i]);
    }

    return 0;
}