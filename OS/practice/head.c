#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

int main(){

    int fd = open("a.txt", O_RDONLY);
    if(fd == -1){
        perror("open a.txt");
        return 1;
    }
    char buffer[BUFFER_SIZE];
    ssize_t read_value, write_value;
    read_value = read(fd, buffer, BUFFER_SIZE);
    if(read_value == -1){
        perror("read");
        return 1;
    }
    while(read_value != 0){
        if(read_value == -1){
            perror("read");
            return 1;
        }
        write_value = 0;
        while(write_value < read_value){
            ssize_t write_cuurent_value = write(STDOUT_FILENO, buffer, read_value - write_value);
        }
    }

    int close_return_value = close(fd);
    if(close_return_value == -1){
        perror("close");
        return 1;
    }

    return 0;
}