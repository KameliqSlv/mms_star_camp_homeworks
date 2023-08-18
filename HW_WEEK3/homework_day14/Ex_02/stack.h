#include <stdlib.h>
#include <stdio.h>

#ifndef STACK_H
#define STACK_H

typedef struct Data{
    int data;
} Data;

typedef struct Node{
    Data data;
    struct Node *next;
}Node;


typedef struct Stack{
    struct Node *head;
    struct Node *tail;
}Stack;

Stack* init_stack();
void push_stack_front(Stack *s, Data data);
//void pop_stack_back(Stack *s, Data *res);
void pop_stack_front(Stack *s, Data *res);
void deinit_stack(Stack *s);
void print_stack(Stack *s);


#endif