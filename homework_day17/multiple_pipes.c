#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int fd[3][2]; //[N][M] - [N] -> брой дескриптори
                  //         [M] -> 0 read // 1 write //

    for(int i = 0; i < 3; i++){         // check if evetything is okay
        if(pipe(fd[i]) < 0){
            return 1;
        }
    }

    int myValue = 6;

    int pid1 = fork();
    if(pid1 < 0){   //  fork failed
        return 2;
    }

    if(pid1 == 0){
        // предава на child1 стойността => fd[0][0]
        // CHILD 1 УМНОЖАВА ПО 3 ПОЛУЧЕНАТА СТОЙНОСТ И Я ПРЕДАВА НА CHILD 2 => fd[1][1]	


        close(fd[0][1]);
        close(fd[1][0]);
        close(fd[2][0]);
        close(fd[2][1]);

        read(fd[0][0], &myValue, sizeof(myValue));
        close(fd[0][0]);

        myValue = myValue * 3;

        write(fd[1][1], &myValue, sizeof(myValue));
        close(fd[1][1]);
    } else if(pid1 > 0) {
        pid_t pid2 = fork();
        if(pid2 == -1) {
            return 3;
        } else if (pid2 == 0) {
            close(fd[0][0]);
            close(fd[0][1]);
            close(fd[1][1]);
            close(fd[2][0]);

            read(fd[1][0], &myValue, sizeof(myValue));
            close(fd[1][0]);

            if(myValue % 2 == 0){
                myValue *= 2;
            } else {
                myValue /= 2;
            }

            write(fd[2][1], &myValue, sizeof(myValue));
        
        } else if(pid2 > 0){
            close(fd[0][0]);
            close(fd[1][0]);
            close(fd[1][1]);
            close(fd[2][1]);
            
            write(fd[0][1], &myValue, sizeof(myValue));
            read(fd[2][0], &myValue, sizeof(myValue));

            printf("Value is %d\n", myValue);
        }
    }
}