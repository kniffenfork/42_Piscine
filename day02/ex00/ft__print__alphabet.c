#include <stdio.h>

void ft__print__alphabet(void){
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i=0; alphabet[i] != '\0'; i++){
        putchar(alphabet[i]);
    }



}
int main(){
    ft__print__alphabet();
    return 0;
}