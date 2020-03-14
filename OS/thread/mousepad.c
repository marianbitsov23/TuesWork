#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 1000

void *check_primes(void *arg){
    int n = *((int *) arg);
    int not = 0;
    free(arg);
    printf("Prime calculation started for N=%d\n", n);
    int counter = 0;
    if(n == 1 || n == 0){
        printf("Number of primes for N=%d is 0\n", n);
        not = 1;
    }
    for(int i = 2; i < n; i++){
        int check = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                check++;
            }
        }

        if(check == 2){
            counter ++;
        }
    }
    if(not == 0){
        printf("Number of primes for N=%d is %d\n", n,  counter);
    }

}

int main(){
    char buffer[BUFFER_SIZE];
    pthread_t threads[BUFFER_SIZE];

    int counter = 0;
    while(1){
        

        fgets(buffer, BUFFER_SIZE, stdin);

        if(buffer[0] == 'e'){
            for(int i = 0; i <= counter; i++){
                pthread_join(threads[i], NULL);
            }
            return 0;
        }
        else if(buffer[0] == 'p'){
            int n = 0, j = 0;
            char numstr[BUFFER_SIZE];
            for(int i = 2; buffer[i] != '\0'; i++){
                numstr[j] = buffer[i];
                j++;
            }
            numstr[j] = '\0';
            n = atoi(numstr);
            int *p = malloc(sizeof(int));
            *p = n;
            pthread_create(&threads[counter], NULL, check_primes, p);
            counter++;
        }
        else{
            printf("Supported commands:\n");
            printf("p N - Starts a new calculation for the number of primes from 1 to N\n");
            printf("e - Waits for all calculations to finish and exits\n");
        }
    }
}