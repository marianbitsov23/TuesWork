#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

int main(){
    int fd = open("example.hidden", O_RDONLY);
    if(fd == -1){
        perror("open");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    if(lseek_value == -1){
        perror("lseek");
        return -1;
    }
    ssize_t read_value = 1, write_value, write_current_value;
    while(read_value != 0){
        if(read_value == -1){
            perror("read");
            return 1;   
        }
        write_value = 0;
        while(write_value < read_value){;
            write_current_value = write(STDOUT_FILENO, buffer, read_value);
            read_value = read(fd, buffer, BUFFER_SIZE);
            write_value += write_current_value;           
        }
    }
    int close_return_value = close(fd);
    if(close_return_value == -1){
        perror("close");
        return 1;
    }
}