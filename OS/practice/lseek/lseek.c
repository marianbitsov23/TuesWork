//------------------------------------------------------------------------
// NAME: Mariyan Bitsov
// CLASS: XIa
// NUMBER: 17
// PROBLEM: #1
// FILE NAME: lseek.c (unix file name)
//имплементация на абстрактен блок
// FILE PURPOSE:
// Parser за абстрактна блокова система,
// който да извежда информацията на стандартния вход
//------------------------------------------------------------------------

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char data;
    unsigned char nextElementAdress;
}block;

int parser(char*, block*);
//------------------------------------------------------------------------
// FUNCTION: parser (име на функцията)
// предназначение на функцията
// PARAMETERS:
// char  *filename - името на файла записан в масив от char елементи
// block *myblock - абстрактния блок в който записваме информацията ,собствен дефиниран тип - block(структура)
//------------------------------------------------------------------------


int main(int argc, char**argv){
    block *myblock = malloc(sizeof(char) * 2); //освобождаване на памет за абстрактен блок
    parser(argv[1], myblock); //викаме функцията, която прочита файла и извежда информацията на стандартния вход 

    return 0;
}

int parser(char *filename, block* myblock){
    int fd = open(filename, O_RDONLY); //отваряме 
    if(fd == -1){ //проверка дали е отворен файла успешно
        perror("open"); 
        return 1;
    }
    off_t lseek_value;
    ssize_t read_value, write_value;

    while(1){
        read_value = read(fd, &myblock->data, 1); //четем един байт от файла и го записваме като елемент на абстрактния блок
        if(read_value == -1){ //проверка за грешка в четенето
            perror("read");
            return 1;
        }
        read_value = read(fd, &myblock->nextElementAdress, 1); //четем един байт от файла и го записваме като следващ елемент на абстрактния блок
        if(read_value == -1){ //проверка за грешка в четенето
            perror("read");
            return 1;
        }
        
        write_value = write(STDOUT_FILENO, &myblock->data, 1); //изписваме на стандартния изход data, прочетена
        if(write_value == -1){ //проверка за грешка в писането
            perror("write");
            return 1;
        }
        if(myblock->nextElementAdress == 0){ //проверяваме дали сме стигнали края на блока 
            break;
        }
        lseek_value = lseek(fd, myblock->nextElementAdress, SEEK_SET); //слагаме оказателя за започване на четене да е от следващия елемент
        if(lseek_value == -1){ //проверка за смяна на оказателя за четене
            perror("lseek");
            return 1;
        }
    }

    int close_return_value = close(fd);
    if(close_return_value == -1){
        perror("close");
        return 1;
    }

    return 0;
}