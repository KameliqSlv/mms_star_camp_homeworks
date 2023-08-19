#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define NUM_THREADS 5
#define INIT_BALANCE 1000


typedef struct Bank_account{
    int balance;
    pthread_mutex_t mutex; // mutex
} Bank_acount;

Bank_acount account;

// define deposit function
// не подаваме нищо понеже ше го извикаме през нишката
void *deposit(void *arg){
    int *amount = (int*)arg;
    pthread_mutex_lock(&account.mutex); // lock
    account.balance = account.balance + *amount;
    pthread_mutex_unlock(&account.mutex); // unlock
    return NULL;
}

//definr wirhdraw
void *withdraw(void *arg){
    int *amount = (int*)arg;
    pthread_mutex_lock(&account.mutex); // lock
    account.balance = account.balance - *amount;
    pthread_mutex_unlock(&account.mutex); // unlock
    return NULL;
}


int main(){
    // Initialize oure account balance
    account.balance = INIT_BALANCE;

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

    pthread_mutex_destroy(&account.mutex); // destroy mutex

    printf("Final balance of account is : %d \n", account.balance);

    // 200+200+200+200 = 4 * 200 = 800 
    //-100-100-100 =  3 * 100 = 300 // 1800 - 1300 = 1500

    return 0;
}