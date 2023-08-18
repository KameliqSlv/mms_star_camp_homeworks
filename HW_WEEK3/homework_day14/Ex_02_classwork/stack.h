#include "linked_list.h"


#ifndef STACK_H
#define STACK_H

typedef link_list Stack;


Stack* init_stack(){
   return init_linked_list();
}

void push(Data new_elem, Stack* stack){
    push_back(new_elem, stack);
}

void pop(Data *new_elem, Stack* stack){
    pop_back(stack, new_elem);
}

void print_stack(Stack *stack){
    print_linked_list(stack);
}

void deint_stack(Stack *stack){
    deint_stack(stack);
}

#endif 