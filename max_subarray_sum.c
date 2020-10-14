//
// Created by Алексей Фомин on 13.10.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool check_for_similarity(const int *arr){ // create function to check array in task for similar elements
    int flag = 0;
    for (int i=0; i<sizeof(arr); i++) {
        if (((flag == 1) && arr[i] < 0) || ((flag == -1) && arr[i] > 0)){
            return false;
        }
        else if (flag == 0) {
            if (arr[i] > 0)
                flag = 1;
            else if (arr[i] < 0)
                flag = -1;
        }
    }
    return true;
}

int summ_of_array(const int *spis, int start, int end){ // function to get amount of elements in the part of array
    int summ = 0;
    for (int i = start; i < end; i++){
        summ = summ + spis[i];
    }
    return summ;
}

int maxSequence(const int * array, int n) {
    int res = -100000000;
    if (check_for_similarity(array)) {
        if (array[0] > 0) {
            return summ_of_array(array, 0, n);
        } else {
            return 0;
        }

    }else {
        for (int z = 0; z <= n; z++) {
            for (int j=0; j<=n; j++){
                if (summ_of_array(array, z, j) > res)
                    res = summ_of_array(array, z, j);
            }
        }
    }
    return res;
}

int main() {
    int k[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d", maxSequence(k, 9));
    return 0;
}