/*
    Реализирайте програма, чрез която да се редактират 
    бинарни файлове.
*/


#include <ctype.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int fd;

char display_hex(size_t size){
    if(size <= 9) {
        return '0' + size;
    } else {
        return 'A' + (size-10);
    }
}

int main(int argc, char *argv[]){
    /*
        Програмата приема 1 аргумент от командния ред - 
        името на файла, който ще се редактира.
    */
    if(argc != 2){
        perror("Invalid number of arguments");
        exit(-1);
    }
    //write(1, "Hello world!", 12);

    //fwrite("Hello world!\n", sizeof(char), 13, stdout);

    /*
        1.	Отваря се файла, чието име е подадено като аргумент от командния
        ред. Ако файлът не съществува се създава
        .Ако файлът съществува - съдържанието му НЕ се трие.
    */

    //FILE *f = fopen(argv[1], "r");
    fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND);
    if(fd == -1){
        write(STDERR_FILENO, "Open error\n", 11);
    }
    /*
        2.	Прочита се команда от стандартния вход.
         Възможните команди са:
    */

    size_t file_size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    unsigned char buf[file_size];
    int bytes_read = read(fd, buf, file_size);
    if(bytes_read == -1){
        write(STDERR_FILENO, "Read error\n", 12);
        exit(-1);
    }

    char command = getchar();
    while(command != EOF){
        
        if (command == 'd'){
            /*
                ○	d - (display) - Изпечатва се стойността на всеки байт от 
                файла в шестнадесетична бройна система (подобно на данните в 
                левия панел на ghex).
            */
            
            for(size_t i = 0; i < file_size; i++){
                char hex_buff[3];
                hex_buff[0] = display_hex(buf[i] >> 4);
                hex_buff[1] = display_hex(buf[i] & 0xF);
                hex_buff[2] = ' ';
                //hex_buff[3] = '\0';
                write(STDOUT_FILENO, hex_buff, 3);
            }            
            
        } else if(command == 't'){
            /*
                ○	t - (display text) - Изпечатва се стойността на всеки байт 
                от файла интерпретиран като ASCII символ (подобно на данните в 
                десния панел на ghex).
            */

            unsigned char ascii;
            while(read(fd, &ascii,sizeof(ascii)) != -1){
                if(isprint(ascii)){
                    write(STDOUT_FILENO, &ascii, 1);
                }else{
                    write(STDOUT_FILENO, ".", 1);
                }
            }
            
            // for(int i = 0; i < file_size; i++){
                
            //     //putchar(ascii);
            //     char ascii = (isprint(buf[i] ? buf[i] : ' '));
            //     write(STDERR_FILENO, &ascii, 1 );
            // }
            printf("\n");
           
        } else if(command == 'a'){
            /*
                ○	a <new_byte> - (append) - добавя нов байт със стойност <new_byte> в 
                края на файла. 
                <new_byte> е число в интервала [0, ff] в шестнадесетична 
                бройна система.
            */

            char new_byte;
            scanf("%hhx", &new_byte);
            //lseek(fd, 0, SEEK_END);
            write(STDOUT_FILENO, &new_byte, sizeof(new_byte));
            file_size++;
        } else if (command == 'c') {
            /*
                ○	c <start_index> <end_index> - (cut) - премахва байтовете,
                 които са с индекси по-големи от <start_index> и по-малки от
                  <end_index>.
                 <start_index> и <end_index> са числа в десетична бройна 
                 система.
            */

            int start_index, end_index;
            scanf("%d %d", &start_index, &end_index);
                lseek(fd, start_index, SEEK_SET);
                int byte = file_size - end_index - 1;
                read(fd, buf, byte);
                lseek(fd, start_index, SEEK_SET);
                write(fd, buf, byte);
                ftruncate(fd, file_size - (end_index - start_index + 1 ));
            //    file_size -= (end_index - start_index + 1);
            


        } else if(command == 'e'){
            int edit_index;
            scanf("%d", &edit_index);
            char new_byte;
            scanf("%c", &new_byte);
            if(edit_index >= 0 && edit_index < file_size) {
                lseek(fd, edit_index, SEEK_SET);
                write(fd, &new_byte, sizeof(new_byte));
                buf[edit_index] = new_byte;
            }
        }
    }

    close(fd);


}
 