#include "stack.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


Stack* init_stack(){
    Stack *s = malloc(sizeof(Stack)*SIZE);

    if(s == NULL){
        perror("Could not malloc\n");
        exit(-1);
    }

    s->count = 0;

    return s;
}

void push_stack_front(Stack *s, int data){
     if(s->count > SIZE){
        perror("The stack is full!\n");
        exit(-1);
    }
    s->data[s->count++] = data;
    //s->count++;
    
}

void pop_stack_front(Stack *s, int *res){
    if(s->count == 0){
        perror("The stack is empty!\n");
        exit(-1);
    }
    *res = s->data[--s->count];
}

void deinit_stack(Stack *s){
    free(s);
}

void print_stack(Stack *s){
//    for(size_t i = 0; i< SIZE; i++){
//         printf("%d ", s->data[i]);
//         //printf("%d", s->top);
//     }
//     printf("\n");
    for(size_t i = 0; i< s->count; i++){
        //printf("%d ", s->data.data);
        printf("%d ", s->data[i]);
    }
    printf("\n");   
}

// Stack* init_stack(){
//     Stack *s = malloc(sizeof(Stack));
//     if(s == NULL){
//         perror("Could not malloc\n");
//         exit(-1);
//     }

//     return s;
// }

// void push_stack_front(Stack **s, Data data){
//     Stack *new_data = malloc(sizeof(Stack));
    
//     (*s)->top++;

//     if((*s)->top > SIZE){
//         printf("PUSH\n %d \n", (*s)->top);
//         exit(-1);
//     }
   
//     new_data->data = data;
//     (*s) = new_data;
// }

// void print_stack(Stack *s){
//     for(size_t i = 0; i< SIZE; i++){
//         printf("%d ", s->data.data);
//         //printf("%d", s->top);
//     }
//     printf("\n");
//     for(size_t i = 0; i< SIZE; i++){
//         //printf("%d ", s->data.data);
//         printf("%d ", s->top);
//     }
//     printf("\n");
// }