#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    int val;
} Data;

typedef struct Node{
    Data data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* init_queue(){
    Node *new = (Node*)malloc(sizeof(Node));
    if(!new){
        perror("Could not malloc\n");
        exit(-1);
    }
    new->next = NULL;
    new->prev = NULL;
    return new;
}

//-	добавяне на елемент в началото;
void front_enqueue(Data new_elem, Node **q){
    //Node **head;
    Node *new = malloc(sizeof(Node));

    // new == NULL
    if(!new){
        perror("Could not malloc\n");
        exit(-1);
    }

    new->data = new_elem;
    new->next = *q;
    new->prev = NULL;
    (*q)->prev = new;
    *q = new;

}

//-	добавяне на елемент в края;
void back_enqueue(Data new_elem, Node **q){
    Node *new = malloc(sizeof(Node));

    //new == NULL
    if(!new){
        perror("Could not malloc\n");
        exit(-1);
    }

    new->data = new_elem;
    new->next = NULL;
    new->prev = NULL;

    if (*q == NULL) { // Ако опашката е празна , сетни new като пъви елемент
        *q = new;  
    }

    //Намирам последния елемент в опашката
    Node *cur_node = *q;
    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
    }

    // Добавям new към края на опашката
    cur_node->next = new;
    new->prev = cur_node;


    // if(*q == NULL) *q = new;

    // Node *cur_node = (*q)->next;
    // while(cur_node->next != NULL){
    //     cur_node = cur_node->next;
    // }

   
}

//-	премахване/връщане на елемент от началото;
void front_dequeue(Data *res, Node **q){
    if(*q == NULL) {
        printf("Empty list\n");
        exit(-1);
    }

    if(res == NULL){
        *res = (*q)->data;
    }

    Node* cur_head = (*q)->next;
    free(*q);
    *q=cur_head;
    if((*q) != NULL) (*q)->prev = NULL;
}

//-	премахване/връщане на елемент от края;
void back_dequeue (Data *res, Node** q ){
    if(*q == NULL){
        printf("Empty list\n");
        exit(-1);
    }


    Node *cur_head = (*q);

    // Ако има само един елемет опашката == 
    if(cur_head->next == NULL){
        *res = cur_head->data;
        free(cur_head);
        *q = NULL; // 
        return;
    }

    while (cur_head->next->next != NULL) {
        cur_head = cur_head->next;
    }

    *res = cur_head->next->data;
    free(cur_head->next);
    cur_head->next = NULL;
    (*q)->prev = cur_head;
}

void deinit_queue(Node **q){
    while(*q != NULL){
        Data d;
        front_dequeue(&d, q);
        (*q) = (*q)->next;
    }
    free(*q);
}





void print_q(Node *q){
    if(q == NULL){
        perror("Empty list\n");
        exit(-1);
    }
    while(q != NULL){
        printf("%d ", q->data.val);
        q = q->next;
    }
    printf("\n");
}

int main(){
    Node* q = init_queue();
    front_enqueue((Data){5}, &q);
    front_enqueue((Data){6}, &q);
    front_enqueue((Data){7}, &q);
    front_enqueue((Data){8}, &q);
    print_q(q);

    back_enqueue((Data){8}, &q);
    back_enqueue((Data){7}, &q);
    back_enqueue((Data){6}, &q);
    print_q(q);


    printf("Remove front: \n");
    Data d;
    front_dequeue(&d, &q);
    print_q(q);
    front_dequeue(&d, &q);
    print_q(q);

    printf("Remove back:\n");
    back_dequeue(&d, &q);
    print_q(q);
    back_dequeue(&d, &q);
    print_q(q);
    //printf("%d", node);


    deinit_queue(&q);
    print_q(q);
}

