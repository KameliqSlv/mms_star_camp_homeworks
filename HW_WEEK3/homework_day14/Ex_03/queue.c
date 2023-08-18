#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue* init_queue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if(!q){
        perror("Could not malloc");
        exit(-1);
    }
    q->next = NULL;

    return q;

}

void eqnueue(int new_elem, Queue *head){
    Queue *new_data = malloc(sizeof(Queue));
    if(!new_data){
        perror("Could not malloc");
        exit(-1);
    }
    
    if(head->next == NULL){
        new_data->data = new_elem;
        new_data->next = new_data;
        head->next = new_data;
    }
    

    Queue *last_node;
    last_node->next = new_data;
    last_node = new_data;
    // while(last_node->next != NULL){
    //     last_node = last_node->next;
    // }

    // last_node = new_data;
    
}

void print_queue(Queue *q){
    Queue* curr_elem = q->next;
    printf("%d ", curr_elem->data);
}