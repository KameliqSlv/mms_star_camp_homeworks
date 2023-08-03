#include <stdio.h>
#include <stdlib.h>

#define ID_LEN 10

typedef struct Person {
    char name[100];
    char id[ID_LEN];
    unsigned short birthYear;
    unsigned short birthMonth;
    unsigned short birthDay;
    // F -> female , M -> male 
    char gender;
} Person;

typedef struct Person_t{
    struct Person *person;
    struct Person *capacity;
} Person_t;

void* initArray(size_t capacity){
    Person_t *person = malloc(sizeof(Person_t)*capacity);
    if(person==NULL) exit(-1);
}

int addPerson(char *name, unsigned short birthYear, unsigned char birthDay, char gender){
   Person arr = {
    *name,
    birthYear, 
    birthDay,
    gender
   };

int main(){
    printf("%ld\n", sizeof(Person));
}


