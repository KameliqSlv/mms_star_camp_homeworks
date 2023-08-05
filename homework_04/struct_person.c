
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID_LEN 10

typedef struct Person {
    char name[100];
    char id[ID_LEN];
    unsigned short birthYear;
    unsigned char birthMonth;
    unsigned char birthDay;
    // F -> female , M -> male 
    char gender;
} Person;

//създаване на глобална променлива за запазване на обектите в структурата
Person *arr;
//създавам елементи които ще броят елементите в структурата и максималния
//обхват
size_t elem_count , capacity_arr;

void* initArray(size_t capacity){
    arr = malloc(sizeof(Person)*capacity);
    if(arr==NULL) exit(-1);
    elem_count = 0;
    capacity_arr = capacity;

    return arr;
}

int addPerson(char *name, unsigned short birthYear, unsigned char birthMonth,  unsigned char birthDay, char gender){

    if(elem_count >= capacity_arr){
        return -1;
    }

    //копирам низа посечен от източника
    strcpy(arr[elem_count].name, name);

    //Генериране на уникален индентификатоз по име 
    for(size_t i = 0; i < ID_LEN; i++){
       arr[elem_count].id[i] += arr[elem_count].name[i];
       // //*arr->id += 1;
   }

   // s elem count opredelqm na koq poziciq
    arr[elem_count].birthYear = birthYear;
    arr[elem_count].birthMonth = birthMonth;
    arr[elem_count].birthDay = birthDay;
    arr[elem_count].gender = gender;
    
    printf("ID: %s \n", arr[elem_count].id);
    elem_count++;
    return 0;
}

int removePerson(char *id){
    for(size_t i = 0; i < elem_count; i++){
        //strcmp -> стравнява два символни низа по символ.
        //Ако низовете са вярни връща нула
        //Ако не сложа 0 връща грешка
        if(strcmp(arr[i].id, id) == 0){
            for (size_t j = i; j<elem_count-1; j++) {
                arr[j] = arr[j+1];
            }
            //*arr[i].id = *arr[i+1].id; 
            elem_count--;
            return 0;
        } 
    }
    return -1;
}

void readPerson(){
    if(elem_count > capacity_arr){
        exit(-1);
    }
    
    printf("Име: ");
    scanf("%s", arr[elem_count].name);

    printf("Година на раждане: ");
    // %hd-> се използва за shot променливите за да запише само два байта
    scanf("%hd", &arr[elem_count].birthYear); 

    printf("Месец на раждане: ");
    scanf(" %c", &arr[elem_count].birthMonth);

    printf("Дата на раждане: ");
    scanf(" %c", &arr[elem_count].birthDay);

    printf("Пол :");
    scanf(" %c", &arr[elem_count].gender);

    addPerson(arr[elem_count].name, arr[elem_count].birthYear, 
                arr[elem_count].birthMonth, arr[elem_count].birthDay, 
                arr[elem_count].gender);
}

int printPerson(char *id){
    for (size_t i = 0; i<elem_count; i++) {
        if(strcmp(arr[i].id, id)==0){
            printf("\n========================================\n");
            printf("Име: %s\n", arr[i].name);
            printf("ID: %s\n", arr[i].id);
            printf("Година на раждане: %hu \n", arr[i].birthYear);
            printf("месец на раждане: %c\n", arr[i].birthMonth);
            printf("Ден на раждане: %c\n",arr[i].birthDay);
            printf("Пол: %c\n", arr[i].gender);
            printf("\n========================================\n");
            return 0;    
        }
       
    }

    return -1;
}

int main(){
    
 
    size_t capacity = 10;
    initArray(capacity);

    readPerson();
    readPerson();


    char id[ID_LEN];
    printf("Въведете ID номер: ");
    scanf("%s", id);


    printf("%d \n ",printPerson(id));

    
    //printf("%ld", elem_count);
    int remove = removePerson(id);
    if(remove == 0){
        printf("Човека с ID '%s' е премахнат успешно! \n", id);
    } else{
        printf("Грешно втведени данни!  \n");
    }

    //printf("%ld\n", sizeof(Person));

  
    printf("%d \n ",printPerson(id));

    free(arr);
    return 0;
}


