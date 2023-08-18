#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){
    return strcmp((*(char**)a),(*(char**)b));
}

int main(int argc, char *argv[]){
    if(argc < 2){
        perror("Invalid number of arguments");
        exit(-1);
    }

    qsort(argv+1, argc -1  , sizeof(char*), cmp);

    /*
        Името на файла, в който ще се записва, се 
        въвежда от стандартния вход. Ако файлът не 
        съществува - той се създава. Ако файлът 
        съществува - изписва се съобщение за грешка.
    */

    char output[20];
    printf("Write output file : ");
    scanf("%s", output);
    FILE *f;
    if ((f = fopen(output, "r"))!= NULL){
        perror("The file already exists");
        exit(-1);
    } else {
        f = fopen(output,"w");
    }

    for (int i = 1; i < argc; i++) {
        //FILE *f = fopen(argv[i], "r");
        fprintf(f,"%s ", argv[i]);

    }
    printf("Successfully written!\n");
}