/*
    Напишете C програма, която създава два дъщерни процеса, A и B, които ще 
    комуникират с родителския процес с помощта на канали (pipes). 
    Родителският процес трябва да генерира произволен масив от цели числа
    и да го изпрати на процес A през канал. Процес A ще намери
    сумата от всички четни числа в масива и ще я изпрати на процес 
    B през друг канал. Накрая процес B ще изчисли квадрата на получената 
    сума и ще я изпрати обратно към родителския процес през трети канал. 
    След това родителският процес ще отпечата сумата на квадрат,
    получена от процес B.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define ARRAY_SIZE 10

// 0 -> read
// 1 -> write

void parent_process(int pipe1[2], int pipe2[2], int pipe3[2]){
    /*
        Тази функция представлява действията на родителския процес. 
        Той генерира произволен масив, изпраща го на процес А до pipe1, 
        изчаква да приключи, получава сумата на квадрат от процес B до pipe3
        и накрая отпечатва сумата на квадрат.
    */
    int array[ARRAY_SIZE];
    for(int i=0; i<ARRAY_SIZE; i++){
        array[i] = rand() % 20;
    }

    for(int i=0; i<ARRAY_SIZE; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    close(pipe1[0]);
    write(pipe1[1], array, sizeof(array));
    close(pipe1[1]);
    

    int sum;
    close(pipe3[1]);
    read(pipe3[0], &sum, sizeof(sum));
    close(pipe3[0]);
    printf("Square sum : %d\n",sum);
}


void process_A(int pipe1[2], int pipe2[2]){
    /*
        Получава масив от родителския процес чрез pip1, изчислява сумата на 
        елементите на масива и изпраща сумата на process_B чрез pip2
    */
    int array[ARRAY_SIZE];

    close(pipe1[1]);
    read(pipe1[0], array, sizeof(array));
    close(pipe1[0]);
    

    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if(array[i] % 2 == 0){
            sum += array[i];
        }
    }
    printf("Sum of even number : %d \n", sum);

    //close(pipe1[0]);
    close(pipe2[0]);
    write(pipe2[1], &sum, sizeof(sum));
    close(pipe2[1]);
}

void process_B(int pipe2[2], int pipe3[2]){
    /*
        Получава сумата от процес А до pipe2, изчислява сумата на квадрата и 
        изпраща сумата на квадрат обратно към родителския процес чрез pipe3
    */
    int sum;

    close(pipe2[1]);
    read(pipe2[0], &sum, sizeof(sum));
    close(pipe2[0]);

    int sq_sum = sum * sum;

    // close(pipe2[0]);
    close(pipe3[0]);
    write(pipe3[1], &sq_sum, sizeof(sq_sum));
    close(pipe3[1]);

}


int main(){
    int pipe1[2], pipe2[2],pipe3[2];

    if(pipe(pipe1) == -1 || pipe(pipe2) == -1 || pipe(pipe3) == -1){
        perror("Create pipe failed!");
        exit(-1); 
    }

        
    pid_t pidA = fork();
    if(pidA == -1){
        perror("Fork A failed!");
        exit(-1);
    } else if(pidA == 0){
        process_A(pipe1, pipe2);
    } else if(pidA > 0){
        pid_t pidB = fork();
        if (pidB == -1) {
            perror("Fork B failed");
            exit(-1);
        } else if(pidB == 0){
            process_B(pipe2, pipe3);
        } else if(pidB > 0){
            parent_process(pipe1, pipe2, pipe3);
            wait(NULL);
            wait(NULL);
        }

            // parent_process(pipe1, pipe2, pipe3);
            // wait(NULL);
    } else {
        perror("ERROR:");
        exit(-1);
    }
    
}