//------------------------------------------------------------------------
// NAME: Mariyan Bitsov
// CLASS: XIa
// NUMBER: 17
// PROBLEM: #1
// FILE NAME: shell.c (unix file name)
// FILE PURPOSE:
// имплементация на командата shell, с помощта на процеси
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char** parse_cmdline(const char* cmdline);
void proccessing(char**);

int main(){
    int status;
    while(1){
        printf("$ ");
        char *buffer = malloc(200 * sizeof(char));
        if(fgets(buffer, 200, stdin) == NULL){
            free(buffer);
            return 0;        
        }

        int counter = 0;
        for(int i = 0; buffer[i] != '\0'; i++){
            if(buffer[i] == ' '){
                counter++;
            }
        } 
        counter++;        

        char** filename = parse_cmdline(buffer);

        filename[counter] = NULL;

        proccessing(filename);
        
        free(buffer);
    }

}

char** parse_cmdline(const char* cmdline){
    int counter = 0;
    for(int i = 0; cmdline[i] != '\0'; i++){
        if(cmdline[i] == ' '){
            counter++;
        }
    } 
    counter++;

    char **penka = (char**)malloc(counter * sizeof(char*));
    for(int i = 0; i < counter; i++){
        penka[i] = (char*)malloc(200 * sizeof(char*));
    }

    int i, j = 0, c = 0;

    for(i = 0; i < counter; i++){
        while(cmdline[j] != ' ' && cmdline[j] != '\0'){
            penka[i][c] = cmdline[j];
            j++;
            c++;
        }
        if(cmdline[j] == '\0'){c--;}
        penka[i][c] = '\0';
        j++;
        c = 0;
    }

    return penka;    
}

void proccessing(char** filename){
    int status;
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        status = -1;
    }
    else if(pid == 0){
        if(execvp(filename[0], filename) == -1){
            perror(*filename);
            status = -1;
            exit(0);
            return;
        }
        exit(0);
    }
    else{
        if(waitpid(pid, &status, 0) != pid){
            status = -1;
        }
    }
}