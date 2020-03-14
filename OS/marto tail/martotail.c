#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 10


void create_name(char*, char*);
void invalid_file_error(char*);
void path_argument_error(char*);
int error_type(char*);
char* create_storage(int);
ssize_t set_seek_value(char*, char*);
void print_last_ten(int);
int print_tail(char*, int, int);
int stdin_read(char*);



int main(int argc, char *argv[]){
    int fd;
    for(int i = 1; i < argc; i++){
        print_tail(argv[i], argc, i);
    }
    if(argc < 2){
        print_tail("-", argc, 1);
    }
	return 0;
}



void invalid_file_error(char *name){
    char *error_buffer = malloc(sizeof(char) * 60 + strlen(name));
    strcat(error_buffer, "tail: cannot open '");
    strcat(error_buffer, name);
    strcat(error_buffer, "' for reading: No such file or directory\n");
    write(STDERR_FILENO, error_buffer, 60 + strlen(name));
}
void path_argument_error(char *name){
    char *error_buffer = malloc(sizeof(char ) * 39 + strlen(name));
    strcat(error_buffer, "tail: error reading '");
    strcat(error_buffer, name);
    strcat(error_buffer, "': Is a directory\n");
    write(STDERR_FILENO, error_buffer, 39 + strlen(name));
}
void full_memory_error(char *name){
    char *error_buffer = malloc(sizeof(char ) * 48 + strlen(name));
    strcat(error_buffer, "tail: error writing '");
    strcat(error_buffer, name);
    strcat(error_buffer, "': No space left on device\n");
    write(STDERR_FILENO, error_buffer, 48 + strlen(name));
}
void close_file_error(char *name){
    char *error_buffer = malloc(sizeof(char ) * 39 + strlen(name));
    strcat(error_buffer, "tail: error reading '");
    strcat(error_buffer, name);
    strcat(error_buffer, "': Input/outpu erro\n");
    write(STDERR_FILENO, error_buffer, 41 + strlen(name));
}
int error_type(char *name){
    if(name[0] == '/'){
        return 0; 
    }else{
        return 1;
    }
}

void create_name(char *name, char *name_buffer){
    if(strstr(name, "-")){
        strcpy(name_buffer, "==> standard input <==\n");
    }else{
        strcat(name_buffer, "==> ");
        strcat(name_buffer, name);
        strcat(name_buffer, " <==\n");
    }

}

ssize_t set_seek_value(char *storage, char *name){
    int storage_size = strlen(storage), new_line_count = 0;
    ssize_t new_start_point = 0;
    for(int i = storage_size - 1; i >= 0; i--){
        if(storage[i] == '\n'){
            new_line_count++;
        }
        if(new_line_count == 10){
            break;
        }
        new_start_point++;
    }
    if(new_line_count == 10){
        return storage_size - new_start_point;
    }
    else{
        return 0;
    }
}

void print_last_ten(int fd){
    ssize_t read_value = 1, write_value;
    char buffer[BUFFER_SIZE + 1];
    while(read_value != 0){
        read_value = read(fd, buffer, BUFFER_SIZE);
        write_value = 0;
        while(write_value < read_value){
            ssize_t write_current_value = write(STDOUT_FILENO, buffer, read_value - write_value);
            write_value += write_current_value;
        }
    }
}

int stdin_read(char *filename){
    char buffer[BUFFER_SIZE];
    int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
    if(fd == -1){
        full_memory_error(filename);
        return -1;
    }
    ssize_t read_value = 1, write_value;
	while(read_value != 0){
		read_value = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if(read_value == -1){
			full_memory_error(filename);
            return -1;
		}
		write_value = 0;
		while(write_value < read_value){

			ssize_t write_current_value = write(fd, buffer, read_value - write_value);
			if(write_current_value == -1){
				perror("write");
				return -1;
			}
			write_value += write_current_value;
		}
	}
    return fd;
}
char *create_storage(int fd){
    ssize_t read_value;
    char buffer[BUFFER_SIZE + 1];
    char *storage = malloc(sizeof(char) * 11);
    int storage_size = 0;

    while(1){
        read_value = read(fd, buffer, BUFFER_SIZE);
        if(read_value == 0){
            break;
        }
        buffer[BUFFER_SIZE] = '\0';
        storage[storage_size] = '\0';
        strcat(storage, buffer);
        storage_size += read_value;
        storage = (char*)realloc(storage, (sizeof(char) * read_value) + storage_size + 1);
		
    }
    storage[storage_size] = '\0';

    return storage;
}

int print_tail(char *name, int argument_count, int current_iteration){
    char *storage;
    char buffer[BUFFER_SIZE];
    char *name_buffer;
    if(strstr(name, "-")){
        name_buffer = malloc(sizeof(char) * strlen("==> standard input <==") + 1);
    }else{
        name_buffer = malloc(sizeof(char) * strlen(name) + 10);
    }
    name_buffer[0] = '\0';
    int fd;

    if(strstr(name, "-")){
        if(argument_count > 2){
            create_name(name, name_buffer);
            write(STDOUT_FILENO, name_buffer, strlen(name_buffer));
        }
        fd = stdin_read("-.txt");
        if(fd == -1){
            return 0;
        }
    }else{
        fd = open(name, O_RDONLY);
    }

    if(read(fd, buffer, 10) == -1 && strstr(name, "-") == 0){
        int error_flag = error_type(name);
        if(error_flag == 0){
            path_argument_error(name);
        }else if(error_flag == 1){
            invalid_file_error(name);
        }
        return 0;
    }
    lseek(fd, 0, SEEK_SET);
    
    if(argument_count > 2 && !strstr(name, "-")){
        create_name(name, name_buffer);
        write(STDOUT_FILENO, name_buffer, strlen(name_buffer));
    }



    storage = create_storage(fd);

    lseek(fd, set_seek_value(storage, name), SEEK_SET);
                
    print_last_ten(fd);

    if(current_iteration < argument_count - 1){
        write(STDOUT_FILENO, "\n", 1);
    }

    int close_return_value = close(fd);
    if(close_return_value == -1)
    {

        close_file_error(name);
        return 1;	
    }
    free(name_buffer);
    free(storage);
  
	return 0;
}
