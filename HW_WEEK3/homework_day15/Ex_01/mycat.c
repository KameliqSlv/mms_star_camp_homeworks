#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc == 1 ){
        int c;
        while( (c = getchar())!= EOF){
            putchar(c);
        }
    }
    // 1 аргумент от командния ред: програмата чете от 
    // файл, чието име е подадения аргумент. Програмата изпечатва 
    // съдържанието му на стандартния изход.
    // else if(argc == 2){
    //     FILE *file = fopen(argv[1], "r");
    //     if(file == NULL){
    //         perror("Error opening file");
    //         exit(-1);
    //     }
    //     int c;
    //     while((c = fgetc(file)) != EOF){
    //         putchar(c);
    //     }
    //     // c = fgetc(file);
    //     // while (c!=EOF) {
    //     //     fputc(c, stdout);
    //     //     c = fgetc(file);
    //     // }
    //     fclose(file);
    //}


    // 2 или повече аргумента от командния ред.
    // Програмата изпечатва съдържанието на файловете с имена, 
    // подадени като аргументи от командния ред последователно.
    else {
        for (int i = 1; i < argc; i++) {
            FILE *file =fopen(argv[i], "r");
            if(file == NULL) {
                perror("Error opening file");
                exit(-1);
            }
            int c;
            while((c = fgetc(file)) != EOF){
                putchar(c);
            }
            fclose(file);
        }
    }

    return 0;
}