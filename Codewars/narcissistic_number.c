#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool narcissistic(int num)
{
    int count=0, copy_num = num;
    double arr[100], prom_num = 0;
    while (num > 0){
        if (count==0) {
            arr[0] = num % 10;
            num = num/10;
            count++;
        }
        else{
            arr[count] = num % 10;
            num = num / 10;
            count++;
        }
    }
    for (int i=0; i<count; i++){
        prom_num = prom_num + pow(arr[i], count);
    }
    if (prom_num == copy_num)
        return true;
    else
        return false;
}
/*
int main(){
    if (narcissistic(228) == true)
        printf("%s", "TRUE");
    else
        printf("%s", "FALSE");
    return 0;
}
 */