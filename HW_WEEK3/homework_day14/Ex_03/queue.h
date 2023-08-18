#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue{
    int data;
    struct Queue *next;
}Queue;

Queue* init_queue();

void eqnueue(int new_elem, Queue *q);

void dequeue(int *res, Queue *q);

void print_queue(Queue *q);

void deinit_queue(Queue *q);

#endif

