#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void *read_image( const char *filepath );

int main( int argc, const char* argv[] ) {
	char *info = read_image(argv[1]);
	const char *filename = argv[1];
	uint32_t width;
	uint32_t height;
	int fileSize;
	int check = 0;
	FILE *fp = fopen(filename, "r");

	for(int i = strlen(filename) + 1; i > strlen(filename) - 4; i--){
		if(strstr(filename, ".") == 0){
			check = 2;
		}
		if(filename[i - 3] == '.' && filename[i - 2] == 'p' && filename[i - 1] == 'n' && filename[i] == 'g'){
			check++;
		}

	}
	
	if(check != 1 && check != 2){
		printf("Unable to parse file\n");
		return 0;		
	}

	if(fp == NULL){
		printf("Unable to open file\n");
		return 0;
	}

	memmove(&width, info + 16, sizeof(width));
	memmove(&height, info + 20, sizeof(height));
	width = ntohl(width);
	height = ntohl(height);

	fseek(fp, 0L, SEEK_END);
	fileSize = ftell(fp);
	fclose(fp);

	printf("PNG image width: %d\n", width);
	printf("PNG image height: %d\n", height);
	printf("PNG file size: %d\n", fileSize);

	return 0;
}
