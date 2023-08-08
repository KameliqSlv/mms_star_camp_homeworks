#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 50

int stack[SIZE];
int top = 0;


void push (int val) {
    stack[++top] = val;
}

int pop (){
    return stack[top--];
    
}


int main(){
    char str[] = "1 2 + 3 * 5 -";
    char *str_p = str;
 

    while(*str_p){
        if(*str_p >= '0' && *str_p <= '9'){
            push(atoi(str_p));
            str_p++;            
        }
        if(*str_p == '+'){
            int a = pop();
            int b = pop();
            push(a+b);
        } else if(*str_p == '-'){
            int a = pop();
            int b = pop();
            push(b-a);
        } else if (*str_p == '*'){
            int a = pop();
            int b = pop();
            push(a*b);
        }
       str_p++;  
    }
    printf("%d\n", pop());



    return 0;
}







