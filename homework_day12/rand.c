#include <complex.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    double arr[10];
    for (size_t i = 0; i < 10; i++) {
       // arr[i] = 1000 + rand() % (2001 - 1000)/1000.;
        
        
        //rand [1.0-2.0]
        //arr[i] = (rand() % 1001 + 1000) / 1000.;

        //rand [2.0 - 3.0]
         arr[i] = (rand() % 1001 + 2000) / 1000.;

    
    }
    
    for (size_t i = 0; i<10; i++) {
        printf("%.2lf ", arr[i]);
    }
}