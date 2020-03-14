#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 200

int main(int argc, char *argv[]){
    int pipefd[2];
    pid_t pid;
    char buf;

    if(argc < 2){
        printf("too few arguments\n");
    }

    if(pipe(pipefd) == -1){
        perror("pipe");
        return 1;
    }

    pid = fork();
    if(pid == -1){
        perror("fork");
        return 1;
    }

    if(pid == 0){
        if(close(pipefd[1]) == -1){
            perror("close");
        }        

        int read_value;
        char buffer[BUFFER_SIZE];

        read_value = read(pipefd[0], buffer, BUFFER_SIZE);
        if(read_value == -1){
            perror("read");
            return 1;
        }
        write(STDOUT_FILENO, buffer, read_value);
        write(STDOUT_FILENO, "\n", 1);
        return 1;


    }
    else{
        if(close(pipefd[0]) == -1){
            perror("close");
            return 1;
        }

        write(pipefd[1], argv[1], strlen(argv[1]));
        wait(NULL);
        return 1;

    }
    return 1;
}