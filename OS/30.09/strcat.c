#include <stdio.h>
#include <stdlib.h>

void my_strcat(char[], char[]);

int main(){
    char str1[255] = "Hello ";
    char str2[255] = "i am biko with the big dicko";
    my_strcat(str1, str2);
    return 0;
}

void my_strcat(char str1[], char str2[]){
    char str[255];
    int k = 0;
    for(int i = 0; str1[i] != '\0'; i++){
        str[k] = str1[i];
        k++;
    }
    for(int i = 0; str2[i] != '\0'; i++){
        str[k] = str2[i];
        k++;
    }
    printf("%s\n", str);
}