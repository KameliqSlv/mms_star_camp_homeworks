#include <stdio.h>
#include <stdlib.h>

#define MAX(x,y,z) ((x > y) ? x : y && (y > z) ? y : z && (z > x) ? z : x)
#define MIN(x,y,z) ((x < y) ? x : y && (y < z) ? y : z && (z < x) ? z : x)  
#define SET_BIT(mask, bit)  mask | (1<<bit)
#define CLEAR_BIT(mask, bit) mask & ~(1 << bit)
#define INVERSE_BIT(mask, bit) mask ^ (1 << bit)
#define swap(x,y) { x = x + y; y = x - y; x = x - y; }

                 // x = 1 + 2; y = x - y; x = x - y
                 // x = 3      y = 3 - 2; x = 3 - y
                 // x = 3      y = 1      x = 3 - 1
                 // x = 3      y = 1      x = 2
 

int main(){

    printf("Max : %d\n" , MAX(1, 2, 3));
    printf("Min : %d\n" , MIN(1, 2, 3));
    printf("Set bit : %d\n", SET_BIT(253, 1));
    printf("Clear bit : %d \n", CLEAR_BIT(255, 2));
    printf("Inverse bit: %d \n", INVERSE_BIT(255, 7));
   // printf("%d", SWAP(2, 1));
   int a = 1, b= 2;
   printf("Before swap: a = %d , b = %d \n", a, b); 
   swap(a, b);
   printf("After swap: a = %d , b = %d \n", a , b);
} 