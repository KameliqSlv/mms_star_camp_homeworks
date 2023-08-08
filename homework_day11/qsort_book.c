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
}Book;

Book books[COUNT];


int asc_title(const void *a, const void *b) {
    return strcmp(((Book *)a)->title, ((Book *)b)->title);
}

int desc_title(const void *a, const void *b) {
    return strcmp(((Book *)b)->title, ((Book *)a)->title);
}

int asc_author(const void *a, const void *b) {
    return strcmp(((Book *)a)->author, ((Book *)b)->author);
}

int desc_author(const void *a, const void *b) {
    return strcmp(((Book *)b)->author, ((Book *)a)->author);
}

int asc_pages(const void *a, const void *b) {
    return ((Book *)a)->pages - ((Book *)b)->pages;
}

int desc_pages(const void *a, const void *b) {
    return ((Book *)b)->pages - ((Book *)a)->pages;
}

int asc_price(const void *a, const void *b) {
    return ((Book *)a)->price - ((Book *)b)->price;
}

int desc_price(const void *a, const void *b) {
    return ((Book *)b)->price - ((Book *)a)->price;
}




/*
void print_books()
{
    //Book books[COUNT];
    for (size_t i = 0; i < COUNT; i++)
    {
        printf("Title: %20s \t Author: %20s \t Pages: %u \t Price: %lf \n", books[i].title, books[i].author, books[i].pages, books[i].price);
    }
}
*/



int main(){
    //Book books[COUNT];

    for(size_t i = 0 ; i < COUNT ; i++){
      
        
        int len = rand()%11 + 10;

        for (size_t j = 0 ; j < len; j++) {
            books[i].title[j] = 'A' + (rand() % 26);
            books[i].author[j] = 'A'+ (rand() % 26);
        }

        //[5-2000]
       books[i].pages = 5 + rand() % (200 - 5);

       //[1.0 - 1000.0]
        books[i].price = rand() % 1000000 / 1000.0;

    }



    printf(" \n\t\tBook: \n");
    qsort(books, COUNT, sizeof(Book), asc_title);
    for (size_t i = 0; i < COUNT; i++)
    {
        printf("Title: %s  \n", books[i].title);
    }
    printf("\n");

    qsort(books, COUNT, sizeof(Book), desc_title);
    for (size_t i = 0; i < COUNT; i++)
    {
        printf("Title: %s \n", books[i].title);
    }
    printf("\n");




    printf(" \n\t\t author: \n");
    qsort(books, COUNT, sizeof(Book), asc_author);
    for (size_t i = 0; i < COUNT; i++)
    {
        printf("Author: %s  \n", books[i].author);
    }
    printf("\n");

    qsort(books, COUNT, sizeof(Book), desc_author);
     for (size_t i = 0; i < COUNT; i++)
    {
        printf("Author: %s  \n", books[i].author);
    }
    printf("\n");



    printf(" \n\t\t Pages: \n");
    qsort(books, COUNT, sizeof(Book), asc_pages);
    for (size_t i = 0; i < COUNT; i++)
    {
        printf("Pages: %u  \n", books[i].pages);
    }
    printf("\n");

    qsort(books, COUNT, sizeof(Book), desc_pages);
     for (size_t i = 0; i < COUNT; i++)
    {
        printf("Pages: %u  \n", books[i].pages);
    }
    printf("\n");



    printf(" \n\t\t Price: \n");
    qsort(books, COUNT, sizeof(Book), asc_pages);
    for (size_t i = 0; i < COUNT; i++)
    {
        printf("Price: %.2lf  \n", books[i].price);
    }
    printf("\n");

    qsort(books, COUNT, sizeof(Book), desc_pages);
     for (size_t i = 0; i < COUNT; i++)
    {
        printf("Price: %.lf  \n", books[i].price);
    }
    printf("\n");



    return 0;
}


