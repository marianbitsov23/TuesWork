//------------------------------------------------------------------------
// NAME: Mariyan Bitsov
// CLASS: XIa
// NUMBER: 17
// PROBLEM: #1
// FILE NAME: mystrcat.c (unix file name)
// FILE PURPOSE:
// Програма, която съединява два символни низа. 
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>


char* strcat(char*,const char*); //инициализиране на функцията 

int main(){
    char str1[255] = "Hello ";
    char str2[255] = "World !";

    printf("%s \n", strcat(str1, str2)); //извикване на функцията и принтиране на резултата
    
    return 0;
}

char* strcat(char* destination, const char* source){
    int i, k;
    for(i = 0; destination[i] != '\0'; i++){} //намиране на дължината на първия стринг(destination)
   	for(k = 0; source[k] != '\0'; k++){ //конкатениране на втория(source) стринг към първия(destination)
   		destination[i] = source[k];
   		i++;
   	}

    return destination;
}

//------------------------------------------------------------------------
// FUNCTION: strcat (име на функцията)
// връща конкатенирания стринг като (char*)
// PARAMETERS:
// char* destination : указател към масив от тип (char*)
// const char* source : константен указател към масив от тип (char*) 
//------------------------------------------------------------------------