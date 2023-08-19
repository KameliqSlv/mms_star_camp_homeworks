#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX_SLOT 32
#define THREAD_NUM 16

sem_t sem; // declaration of the semaphore


void *routine(void *args){
    int id = (*(int *)args);
    printf("%d waiting ... \n", id);

    sem_wait(&sem);
    
    printf("Thread %d enter in system and occupate a slot\n", id);
    sleep(rand() % 5 + 1);

    sem_post(&sem);
    printf("Thread %d exit from system and release a slot\n", id);


    //free(args);


    return NULL;
}



int main(){
    if(sem_init(&sem, 0, MAX_SLOT) == -1){
        perror("Couldn't init semaphore");
        exit(-1);
    }

    pthread_t thread[THREAD_NUM];
    //int *thread_id = malloc(sizeof(int));
    int thread_id[THREAD_NUM];
    for(int i = 0; i < THREAD_NUM; i++){
        //*thread_id = i;
        thread_id[i] = i;
        if(pthread_create(&thread[i], NULL, routine, thread_id + i ) == -1){
            perror("pthread_create failed!");
            exit(-1);
        };
    }

    for (int i = 0; i < THREAD_NUM; i++) {
        if(pthread_join(thread[i], NULL) == -1){
            perror("pthread_join failed!");
            exit(-1);
        }
    }

    //free(thread_id);
    
    sem_destroy(&sem);

    return 0;
}