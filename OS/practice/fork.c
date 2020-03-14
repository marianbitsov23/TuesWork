#include <stdio.h>
#include <unistd.h>

int main(){
    int num = 5;
    int status;
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        status = -1;
    }
    else if(pid == 0){
        printf("Hello from child process\n");
        if(execl("/bin/ls", "bin/ls", "-l", NULL) == -1){
            perror("execl");
            return 1;
        }
        return 0;
    }
}