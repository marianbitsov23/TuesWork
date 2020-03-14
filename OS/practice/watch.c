//------------------------------------------------------------------------
// NAME: Mariyan Bitsov
// CLASS: XIa
// NUMBER: 17
// PROBLEM: #1
// FILE NAME: watch.c (unix file name)
// FILE PURPOSE:
// имплементация на командата date, с помощта на процеси
//------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char** argv){
    char *filename[255];

    int j = 0;
    for(int i = 1; i < argc; i++){
        filename[j] = argv[i]; //записваме в двумерен масив конзолните аргументи
        j++;
    }
    filename[argc - 1] = NULL;

    int status;
    while(1){
        pid_t pid = fork();
        if(pid < 0){ //проверка за fork
            perror("fork");
            status = -1;
        }
        else if(pid == 0){
            if(execvp(argv[1], filename) == -1){ //проверка и изпълняване на процес
                perror(*filename);
                status = -1;
                return -1;
            }
        }
        else{
            if(waitpid(pid, &status, 0) != pid){ //проверка и изпълняване на детския процес
                status = -1;
            }
        }
        sleep(2); //изчакване 2 секунди предии продължаване
    }

}
//------------------------------------------------------------------------
// FUNCTION: main (име на функцията)
// проверява конзолните аргументи и изпълнява командата date като процес
// PARAMETERS:
// int argc -> броя на конзлоните аргументи
// char **argv -> конзолните аргументи
//------------------------------------------------------------------------