#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#define K 10
unsigned int file_size;
int * numbers;
unsigned long long sum = 0;

pthread_mutex_t lock1;

void *thread_fun_too_much_locking(void* args) {
    // SUM numbers
    int thread_index = *(int*)args;
    printf("STARTED THREAD WITH INDEX: %d\n", *(int*)args);
    for(size_t i = 0; i < (file_size/K)/sizeof(int); i++) {
        // sum += (numbers + (file_size/K)*thread_index)[i];
        pthread_mutex_lock(&lock1);
        sum += numbers[i + thread_index * (file_size/K)/sizeof(int)];
        pthread_mutex_unlock(&lock1);
    }
    printf("ENDING THREAD WITH INDEX: %d. SUM IS: %llu\n", *(int*)args, sum);
}
void *thread_fun(void* args) {
    // SUM numbers
    unsigned long long localSum = 0;
    int thread_index = *(int*)args;
    printf("STARTED THREAD WITH INDEX: %d\n", *(int*)args);
    for(size_t i = 0; i < (file_size/K)/sizeof(int); i++) {
        // sum += (numbers + (file_size/K)*thread_index)[i];
        localSum += numbers[i + thread_index * (file_size/K)/sizeof(int)];
    }
    pthread_mutex_lock(&lock1);
    sum += localSum;
    pthread_mutex_unlock(&lock1);
    printf("ENDING THREAD WITH INDEX: %d. SUM IS: %llu\n", *(int*)args, sum);
}
// ./program numbers.bin
int main(int argc, char *argv[]) {
    // Open file
    FILE* f1 = fopen(argv[1], "r");
    // Get file size
    struct stat file_info;

    stat(argv[1], &file_info);
    file_size = file_info.st_size;

    // Create buffer for file contents
    numbers = malloc(file_size);
    // Read file contents into buffer
    fread(numbers, sizeof(int), file_size, f1);

    // Close file
    fclose(f1);

    // Create mutex
    if(pthread_mutex_init(&lock1, NULL)) {
        perror("Could not init mutex");
    }
    // Create K threads - pass thread_index as argument
    pthread_t thread_handles[K];
    int i = 0;
    int thread_ids[K];
    for(;i < K; i++) {
        thread_ids[i] = i;
        if(pthread_create(thread_handles + i, NULL, thread_fun, thread_ids + i) == -1) {
            perror("could not create thread");
            exit(1);
        }
        // pthread_join(thread_handles[i], NULL);
    }

    // Wait for threads to finish
    for(int i = 0; i < K; i++) {
        pthread_join(thread_handles[i], NULL);
    }
    // Sum results from each thread
    free(numbers);

    printf("\nTOTAL SUM: %llu", sum);

    pthread_mutex_destroy(&lock1);
    return 0;
}