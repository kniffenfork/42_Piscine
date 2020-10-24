#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void DownReg(char *str){ // Create the function to make a capital letters lowercase
    for (int i=0; str[i] != '\0'; i++){
        str[i] = tolower(str[i]);
    }
}

bool check(const char *arr, char const * el){ // function that checks the letter is in string
    for (int i=0; arr[i] != '\0'; i++){
        if (arr[i] == el[0]){
            return true;
        }
    }
    return false;
}

bool is_pangram(char * str_in){
    const char *arr;
    char prom[27]; //create array to put unique letters here
    arr = "abcdefghijklmnopqrstuvwxyz"; // alphabet
    int flag = 0; // counter of unique letters
    for (int i = 0; str_in[i] != '\0'; i++){
        char wer = tolower(str_in[i]); // make capital letter lowercase
        if (check(arr, &wer) == true && check(prom, &wer) == true){ // if this letter isn't unique
            continue;
        }
        else if (check(arr, &wer) == true && check(prom, &wer) == false){ // else put it in prom array
            prom[flag] = wer;
            flag = flag + 1;
        }
    }
    if (flag == 26){ // there're 26 letters in alphabet)
        return true;
    }
    return false;
}


