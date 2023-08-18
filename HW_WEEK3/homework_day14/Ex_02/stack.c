#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


Stack* init_stack(){
    Stack *s = malloc(sizeof(Stack));
    if(s == NULL){
        perror("Could not malloc\n");
        exit(-1);
    }
    s->head = NULL;
    s->tail = NULL;

    return s;
}

void push_stack_front(Stack *s, Data data){
    Node **head = &(s->head);
    Node *new_data = malloc(sizeof(Node));

    if(new_data == NULL){
        perror("Could not malloc\n");
        exit(-1);
    }

    new_data->data = data;
    new_data->next = (*head);
    (*head) = new_data;

    if(s->tail == NULL){
        s->tail = new_data;
    }
}

// void pop_stack_back(Stack *s, Data *res){
//     Node **head = &(s->head);
//     Node **tail = &(s->tail);

//     if(head == NULL){
//         perror("Empty list!\n ");
//         exit(-1);
//     }

//     Node *curr_node = (*head);

//     if(curr_node->next == NULL){
//         *res = curr_node->data;
//         free(curr_node);
//         (*head) = NULL;
//         (*tail) = NULL;
//         return;
//     }

//     while(curr_node->next->next != NULL){
//         curr_node = curr_node ->next;
//     }

//     *res = curr_node->next->data;
//     free(curr_node->next);
//     curr_node->next=NULL;
//     (*tail) = curr_node; 

// }   

void pop_stack_front(Stack *s, Data *res){
    Node **head = &(s->head);
    Node **tail = &(s->tail);

    if(head == NULL){
        perror("Empty list!\n ");
        exit(-1);
    }

    Node *curr_node = (*head)->next;
    free(*head);
    (*head) = curr_node;
    if((*head) != NULL){
        (*tail) = NULL;
    }
    
}

void deinit_stack(Stack *s){
    Node **head = &(s->head);
    while((*head) != NULL){
        Data d;
        pop_stack_front(s, &d);
        (*head) = (*head)->next;
    }
    free(*head);
}

void print_stack(Stack *s){
    Node *head = s->head;
    while(head != NULL){
        printf("%d ", head->data.data);
        head = head->next;
    }
    printf("\n");
}