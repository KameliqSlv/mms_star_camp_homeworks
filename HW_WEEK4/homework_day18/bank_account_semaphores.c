#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 5
#define INIT_BALANCE 1000


typedef struct Bank_account{
    int balance;
} Bank_acount;

Bank_acount account;
sem_t balance_sem; // declaration of the semaphore

// define deposit function
// не подаваме нищо понеже ше го извикаме през нишката
void *deposit(void *arg){
    int *amount = (int*)arg;
    sem_wait(&balance_sem);
    account.balance = account.balance + *amount;
    sem_post(&balance_sem);
    return NULL;
}

//definr wirhdraw
void *withdraw(void *arg){
    int *amount = (int*)arg;
    sem_wait(&balance_sem);
    account.balance = account.balance - *amount;
    sem_post(&balance_sem);
    return NULL;
}


int main(){
    // Initialize oure account balance
    account.balance = INIT_BALANCE;

    //initialize semaphore
    // указател към съхранението на семафора
    // Стойността нула показва че сематора ще се използва само от нишки в рамките на текущия процес
    // използва се за инициализиране на стойността на семафора
    if(sem_init(&balance_sem, 0, 1) == -1){
        perror("Couldn't initialize Semaphore");
        exit(-1);
    }

    //create num of pthread
    pthread_t threads[NUM_THREADS];

    int deposid_amount = 200;
    int withdraw_amount = 100;

    // int deposid_amount[NUM_THREADS];
    // int withdraw_amountNUM_THREADS;

    
    

    for (size_t i=0 ;i<NUM_THREADS;++i) {
        //if even - deposit
        if ((i % 2 == 0)){
           // deposid_amount[i] =200;
            printf("Thread: %ld, is deposite\n",i);
            pthread_create(&threads[i], NULL,deposit ,&deposid_amount);
        }else{ //if idd - withdraw
           // withdraw_amount[i] = 100;
            printf("Thread: %ld, is withraw \n",i);
            pthread_create(&threads[i], NULL,withdraw,&withdraw_amount);
        }

       

    }//end for loop

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&balance_sem); // destroy

    printf("Final balance of account is : %d \n", account.balance);

    // 200+200+200+200 = 4 * 200 = 800 
    //-100-100-100 =  3 * 100 = 300 // 1800 - 1300 = 1500

    return 0;
}