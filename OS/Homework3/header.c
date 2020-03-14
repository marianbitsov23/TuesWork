#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

int main(){
    int fd = open("c.txt", O_RDONLY);
    if(fd == -1){
        perror("open");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int counter = 0;
    ssize_t read_value = 1, write_value, write_current_value;
    size_t i = 0;
    while(read_value != 0){
        if(read_value == -1){
            perror("read");
            return 1;   
        }
        write_value = 0;
        while(write_value < read_value){
            write_current_value = write(STDOUT_FILENO, buffer, i);
            read_value = read(fd, buffer, BUFFER_SIZE);
            for(i = 0; i < read_value; i++){
                if(counter < 10){
                    if(buffer[i] == '\n'){
                        counter++;
                    }
                }
                else if(counter == 10){
                    break;
                }
                else{
                    return 1;
                }                
            }
            write_value += write_current_value;           
        }
    }
    int close_return_value = close(fd);
    if(close_return_value == -1){
        perror("close");
        return 1;
    }
}
