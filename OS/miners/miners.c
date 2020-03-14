//---------------------------------------------
// NAME: Mariyan Bitsov
// CLASS: XI A
// NUMBER: 17
// PROBLEM: #2
//---------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS_COUNT 1000

int gold = 0;

pthread_mutex_t mutex;

void *miner(void *arg){
    int miner_count = *((int *) arg);
    free(arg);
    for(int i = 0; i < 20; i++){
        pthread_mutex_lock(&mutex);
        gold += 10;
        pthread_mutex_unlock(&mutex);
        printf("Miner %d gathered 10 gold\n", miner_count);
        sleep(2);
    }
}

void *trader(void *arg){
    int trader_count = *((int *) arg);
    free(arg);
    for(int i = 0; i < 20; i++){
        pthread_mutex_lock(&mutex);
        if(gold < 10){
            printf("The warehouse is emtpy, cannot sell!\n");
        }
        else {
            gold -= 10;
            printf("Trader %d sold 10 gold\n", trader_count);
        }
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
}

int main(int argc, char **argv){
    pthread_mutex_init(&mutex, NULL);
    int miners;
    int traders;
    if(argc == 1){
        miners = 1;
        traders = 1;
    }
    else{
        miners = atoi(argv[1]);
        traders = atoi(argv[2]);
    }

    pthread_t threads[THREADS_COUNT];

    for(int i = 0; i < miners; i++){
        int *pminers = malloc(sizeof(int));
        *pminers = i + 1;
        pthread_create(&threads[i], NULL, miner, pminers);
    }

    for(int i = miners; i < miners + traders; i++){
        int *ptraders = malloc(sizeof(int));
        *ptraders = i - miners + 1;
        pthread_create(&threads[i], NULL, trader, ptraders);
    }

    for(int i = 0; i < miners + traders; i++){
        pthread_join(threads[i], NULL);
    }
    
    printf("Gold: %d\n", gold);
    pthread_mutex_destroy(&mutex);
}