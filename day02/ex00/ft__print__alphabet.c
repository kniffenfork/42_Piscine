#include <zconf.h>


int ft_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}
void ft__print__alphabet(void){
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i=0; alphabet[i] != '\0'; i++){
        ft_putchar(alphabet[i]);
    }



}
int main(){
    ft__print__alphabet();
    return 0;
}