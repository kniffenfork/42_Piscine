#include <stdio.h>

int zeros(int n){
    int result = 0;
    while (n > 0){
        result = result + (n/5);
        n /= 5;
    }
    return result;
}

int main(){
    printf("%d", zeros(12));
    return 0;
}