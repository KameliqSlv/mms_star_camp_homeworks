#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 10

typedef struct Book{
    char title[150];        
    char author[100];       
    unsigned pages;          
    double price;           
   // struct Book *next;
}Book;

typedef struct Node{
    Book data;
    struct Node * next;   
} Node;

//Book books[COUNT];  // следи елементите в масив 

void gen_rand(char *str){
    int n = 10 + rand() % 11;

    for(size_t i = 0; i < n ; i ++){
        int curIndex = rand() % 52;
        if(curIndex <= 25){
            str[i] = curIndex + 'A';
        } else{
            str[i] = curIndex - 26 + 'a';
        }
    }
}

void init_list(Node **head, Book data){
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL){
        perror("Could not malloc\n");
        exit(-1);
    }

    new_node->data = data;
    new_node->next = (*head);
    (*head)= new_node;

}

Book* init_books(){
    Book *books = malloc(sizeof(Book)*COUNT);

    if(books==NULL){
        perror("Could not malloc\n");
        exit(-1);
    }

    for(int i=0 ;i<COUNT;i++){

        gen_rand(books[i].title);

        gen_rand(books[i].author);

        books[i].pages = 5 + rand() % (2001 - 5);

        books[i].price = (rand() % 100000)/100.;

    }

    return books;
} 

int cmp_title(const void *a, const void *b){
    return strcmp((*(Book*)a).title, (*(Book*)b).title);
}





void print_books(Book *books){
     if(books == NULL){
        perror("Empty list\n");
        exit(-1);
    }
    for (size_t i = 0; i < COUNT; i++)
    {
        printf("Title: %20s \t Author: %20s \t Pages: %u \t Price: %.2lf \n", books[i].title, books[i].author, books[i].pages, books[i].price);
    }
    printf("\n");
}


int main(){
    Node *head = NULL;
    Book *books = init_books();

    for(int i = 0; i< COUNT; i++){
        init_list(&head, books[i]);
    }   
    print_books(books);


    qsort(books, COUNT, sizeof(Book), cmp_title);
    print_books(books);


    free(books);
}