#include<stdio.h>
#include<stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H 1


typedef struct Data {
    int val;   
} Data;

typedef struct Node {
    Data d;
    struct Node *next;
}Node;

typedef struct link_list{
    struct Node *head;
    struct Node *tail;
} link_list;


void print_linked_list(link_list *ll) ;
void push_back(Data new_data, link_list *ll) ;
void pop_back(link_list *ll, Data *result);
void push_front(Data new_data, link_list *ll) ;
void pop_front(link_list *ll, Data *result);
//void free_all();
link_list* init_linked_list();
void deinit_linked_list(link_list *ll);

#endif


