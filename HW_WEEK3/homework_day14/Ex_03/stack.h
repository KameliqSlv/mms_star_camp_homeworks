#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_H
#define STACK_H

#define SIZE 10

typedef struct Stack{
    int data[SIZE];
    int count;
}Stack;

Stack* init_stack();
void push_stack_front(Stack *s, int data);
void pop_stack_front(Stack *s, int *res);
void deinit_stack(Stack *s);
void print_stack(Stack *s);



// typedef struct Data{
//     int data;
// }Data;

// typedef struct Stack{
//     Data data;
//     int top;
// }Stack;

// Stack* init_stack();
// void push_stack_front(Stack **s, Data data);
// void pop_stack_front(Stack *s, int *res);
// void deinit_stack(Stack *s);
// void print_stack(Stack *s);


#endif