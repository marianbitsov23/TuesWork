#include <stdio.h>
#include <stdlib.h>

int my_strlen(char []);

int main(){
    char str[255] = "Batman";
    printf("%d\n", my_strlen(str));
    return 0;
}

int my_strlen(char str[]){
    int len = 0;
    for(int i = 0; str[i] != '\0'; i++){
        len++;
    }
    return len;    
}