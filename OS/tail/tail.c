//------------------------------------------------------------------------
// NAME: Mariyan Bitsov
// CLASS: XIa
// NUMBER: 17
// PROBLEM: #1
// FILE NAME: tail.c (unix file name)
// FILE PURPOSE:
// Имплементация на командата tail,
// която принтира последните 10 реда от файл
//------------------------------------------------------------------------
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

#define BUFFER_SIZE 1

int tail(int, char*);
//------------------------------------------------------------------------
// FUNCTION: tail (име на функцията)
// намира и принтира последните 10 реда от файл
// PARAMETERS:
// int fd -> файловия дескриптор
// char* filename -> името на файла, записано в масив от тип (char*)
//------------------------------------------------------------------------

off_t file_read(int, char*);
//------------------------------------------------------------------------
// FUNCTION: file_read (име на функцията)
// прочита файла и намира 10-те нови реда
// PARAMETERS:
// int fd -> файловия дескриптор
// char* filename -> името на файла, записано в масив от тип (char*)
//------------------------------------------------------------------------

void file_write(int, off_t, char*);
//------------------------------------------------------------------------
// FUNCTION: file_write (име на функцията)
// записва намерените 10 нови реда
// PARAMETERS:
// int fd -> файловия дескриптор
// char* filename -> името на файла, записано в масив от тип (char*)
// off_t i -> брояч, който пази от къде трябва да започне да се записва
//------------------------------------------------------------------------

void create_file(char*);
//------------------------------------------------------------------------
// FUNCTION: create_file (име на функцията)
// четене от стандартния вход и принтиране на последните 10 елемента
// PARAMETERS:
// char* filename -> името на файла, записано в масив от тип (char*)
//------------------------------------------------------------------------

char* file_open_error(char*);
//------------------------------------------------------------------------
// FUNCTION: file_open_error (име на функцията)
// връща съобщение за грешка, ако не се е отворил успешно файл
// PARAMETERS:
// char* filename -> името на файла, записано в масив от тип (char*)
//------------------------------------------------------------------------

char* close_error(char*);
//------------------------------------------------------------------------
// FUNCTION: close_error (име на функцията)
// връща съобщение за грешка, ако не се е затворил успешно файл
// PARAMETERS:
// char* filename -> името на файла, записано в масив от тип (char*) 
//------------------------------------------------------------------------

char* write_error();
//------------------------------------------------------------------------
// FUNCTION: write_error (име на функцията)
// връща съобщение за грешка, ако не се е записало нещо успешно от файл
// PARAMETERS: няма
//------------------------------------------------------------------------

char* read_error(char*);
//------------------------------------------------------------------------
// FUNCTION: read_error (име на функцията)
// връща съобщение за грешка, ако не се е прочело нещо успешно от файл
// PARAMETERS:
// char* filename -> името на файла, записано в масив от тип (char*) 
//------------------------------------------------------------------------

int main(int argc, char** argv){
    char* str = "==> standard input <==\n";
    char* txt = ".txt";
    int check;
    if(argc == 1){ //ако има само един аргумент, влизаме в режим на стандартния вход
        create_file(argv[1]);
    }
    else if(argc > 2){ //проверка дали има повече от 2 аргумента
        for(int i = 1; i < argc; i++){
            if(strstr(argv[i], "-") && strlen(argv[i]) == 1){ //проверка за запис в стандартния вход
                write(STDOUT_FILENO, str, strlen(str));
                create_file(argv[i]);
            }
            else{
                int fd = open(argv[i], O_RDONLY);
                if(fd == -1){ //проверка за грешка в отварянето на файла
                    write(STDERR_FILENO, file_open_error(argv[i]), strlen(file_open_error(argv[i])));                       
                    continue;
                }

                write(STDOUT_FILENO, "==> ", 4);
                write(STDOUT_FILENO, argv[i], strlen(argv[i]));
                write(STDOUT_FILENO, " <==\n", 5);

                check = tail(fd, argv[i]);
                if(check == -1){ continue; } //проверка за грешка при четенето
                int close_value = close(fd);
                if(close_value == -1){ //проверка за грешка в затварянето на файла
                    write(STDERR_FILENO, close_error(argv[i]), strlen(close_error(argv[i]))); 
                    continue;
                }
            }
            if(i != argc - 1){ //запис на нов ред, ако не сме достигнали последния аргумент
                write(STDOUT_FILENO, "\n", 1);
            }
        }
    }
    else{
        if(strstr(argv[1], "-") && strlen(argv[1]) == 1){ //проверка за запис в стандартния вход
            create_file(argv[1]);
        }
        else{
            int fd = open(argv[1], O_RDONLY); //отваряме файла
            if(fd == -1){ //проверка за грешка в отварянето на файла
                write(STDERR_FILENO, file_open_error(argv[1]), strlen(file_open_error(argv[1])));
                return 1;                       
            }
            tail(fd, argv[1]); //викаме функцията, която имплементира tail
            int close_value = close(fd); //затваряме файла
            if(close_value == -1){ //проверка за грешка в затварянето на файла
                write(STDERR_FILENO, close_error(argv[1]), strlen(close_error(argv[1])));                                      
                return 1;
            }
        }
    }
}
void create_file(char* filename){
    char buffer[BUFFER_SIZE + 1];
    ssize_t read_value = 1, write_value, write_current_value;
    int fd = open("tire.txt", O_RDWR | O_TRUNC | O_CREAT, S_IRWXU); //създаваме и отваряме файл с позволения за четене и писане
    if(fd == -1){ //проверка за грешка при отваряне на файла
        write(STDERR_FILENO, file_open_error(filename), strlen(file_open_error(filename)));
        return;
    }
    while(read_value != 0){ //четене от стандартния вход и запис в създадения от мен файл
        read_value = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if(read_value == -1){ //проверка дали е прочетено успешно от файл
            perror(read_error(filename));
        }
        write_value = 0;

        while(write_value < read_value){
            do{
                write_current_value = write(fd, buffer, read_value - write_value);
                if(write_current_value == -1){
                    perror(write_error());
                    return;
                }
            }while(write_current_value == 0); //проверка за успешно записване
            write_value += write_current_value;
        }
    }
    int close_value = close(fd); //затваряме файла
    if(close_value == -1){ //проверка за грешка при затваряне на файла
        write(STDERR_FILENO, close_error(filename), strlen(close_error(filename)));                
        return;
    }
    fd = open("tire.txt", O_RDONLY); //отваряме файла само за четене
    if(fd == -1){ //проверка за грешка при отваряне на файла
        write(STDERR_FILENO, file_open_error(filename), strlen(file_open_error(filename)));
        return;
    }
    tail(fd, filename); //извикваме функцията, която имплементира tail
    close_value = close(fd); //затваряме файла
    if(close_value == -1){ //проверка за грешка при затваряне на файла
        write(STDERR_FILENO, close_error(filename), strlen(close_error(filename)));                
        return;
    }
}

int tail(int fd, char* filename){
    off_t i; 

    i = file_read(fd, filename);
    if(i == -1){ return -1;} //проверка за грешка при четене

    file_write(fd, i, filename);
}

off_t file_read(int fd, char* filename){
    ssize_t read_value, lseek_value;
    size_t size = 0;

    char buffer[BUFFER_SIZE + 1];


    lseek_value = lseek(fd, 0, SEEK_END); //намираме края на файла
    if(lseek_value == -1){
        perror("lseek");
    }
    int counter = 0;
    size = lseek_value;
    off_t i = size;

    while(counter != 11){ // намираме последните 10 нови реда, като четем по един байт назад
        read_value = read(fd, buffer, BUFFER_SIZE);
        if(read_value == -1){ //проверка за грешка при четене от файла
            perror(read_error(filename));
            return -1;
        }

        if(buffer[0] == '\n'){ //проверка дали прочетенето е нов ред
            counter++;
        }
        if(i == 0){
            break;
        }
        i--;
        lseek_value = lseek(fd, i, SEEK_SET);
        if(lseek_value == -1){
            perror("lseek");
        }
    }

    if(i != 0){ i += 2; } //преместваме се на долния ред
    lseek_value = lseek(fd, i, SEEK_SET);
    if(lseek_value == -1){
        perror("lseek");
    }

    i = size - i;

    return i; //връщаме дължината на 10 реда
}

void file_write(int fd, off_t i, char* filename){
    char storage[i];
    ssize_t read_value, write_value;
    while(i > 0){ //записваме последните 10 реда
        do{
            read_value = read(fd, storage, BUFFER_SIZE);
            if(read_value == -1){ //проверка за грешка при четене от файла
                perror(read_error(filename));
                return;                
            }
        }while(read_value == 0); //проверяваме дали е прочетено успешно

        do{
            write_value = write(STDOUT_FILENO, storage, BUFFER_SIZE);
            if(write_value == -1){ //проверка за грешка при записване от файл
                perror(write_error());
                return;
            }
        }while(write_value == 0); //проверяваме дали е записано успешно

        i--;
    }
}

char* file_open_error(char* filename){
    static char error_message[255];
    strcpy(error_message, "tail: cannot open '");
    strcat(error_message, filename);
    strcat(error_message, "' for reading: No such file or directory\n");

    return error_message;
}

char* close_error(char* filename){
    static char error_message[255];
    strcpy(error_message, "tail: error reading '");
    strcat(error_message, filename);
    strcat(error_message, "': Input/output error\n");

    return error_message; 
}

char* write_error(){
    static char error_message[255];
    strcpy(error_message, "tail: error writing \'standard output\'");

    return error_message;     
}

char* read_error(char* filename){
    static char error_message[255];
    strcpy(error_message, "tail: error reading \'");
    strcat(error_message, filename);
    strcat(error_message, "\'");

    return error_message;
}