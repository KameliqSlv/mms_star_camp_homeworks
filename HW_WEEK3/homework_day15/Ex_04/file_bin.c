#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        perror("Invalid number of arguments");
        exit(-1);
    }

    
    FILE *f = fopen(argv[1], "r+");
    if(f == NULL){
        perror("Error opening file");
        exit(-1);
    }

    char command = getchar();
    //unsigned char buf;
    while(command != EOF){
        fseek(f, 0, SEEK_SET);
        if(command == 'd'){
            unsigned char buf;
            while(fread(&buf, 1, sizeof(buf), f)){
                printf("%.2x", buf);
            }
            printf("\n");
        } else if (command == 't'){
            unsigned char buf;
            while(fread(&buf, 1, sizeof(buf), f)){
                putchar(buf);
            }
            printf("\n");
        } else if(command == 'a'){
            fseek(f, 0, SEEK_END);
            unsigned char new_byte;
            printf("Enter a new character: ");
            scanf("%hhx", &new_byte);
            fwrite(&new_byte, sizeof(new_byte), 1, f);
        } else if (command == 'c') {
            int start_index, end_index;
            printf("Enter a start index and end index: ");
            scanf("%d %d", &start_index, &end_index);
            if(start_index > 0 && start_index < end_index) {
                FILE *temp_file = tmpfile();
                if(temp_file == NULL){
                    perror("Error opening file");
                    exit(-1);
                }
            

                unsigned char buf;
                int index = 0;

                while (fread(&buf, 1, sizeof(buf), f)) {
                    fwrite(&buf, sizeof(buf), 1, temp_file);
                    index++;
                }

                fseek(temp_file, 0, SEEK_SET);
                while (fread(&buf, 1, sizeof(buf), temp_file)) {
                    fwrite(&buf, sizeof(buf), 1, f);
                }
                fclose(temp_file);
            } else {
                perror("Invalid data");
                exit(-1);
            }
        } else if (command == 'e') {
            int index;
            printf("Enter index: ");
            scanf("%d", &index);
            unsigned char new_byte;
            printf("Enter new byte: ");
            scanf("%hhx", &new_byte);
            fseek(f, index, SEEK_SET);
            fwrite(&new_byte, sizeof(new_byte), 1, f);
        }
    }


    fclose(f);
    return 0;
}