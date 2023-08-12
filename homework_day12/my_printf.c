#include <complex.h>
#include <stdarg.h>
#include <stdio.h>

int my_printf(const char *fmt, ...){
    va_list arg;
    va_start(arg, fmt);

    //int char_sum = 0;
    while(*fmt != '\0'){
        if(*fmt == '%'){
            fmt++;

            if(*fmt == 'c'){
                putc(va_arg(arg, int), stdout);
                fmt++;
            } else if (*fmt == 'd'){
                //char_sum += va_arg(arg, int);
                printf("%d", va_arg(arg, int));
                fmt++;
            } else if(*fmt == 'f'){
                //char_sum += va_arg(arg,double);
                printf("%f", va_arg(arg, double));
                fmt++;
            }

        }  else{
            putc(*fmt, stdout);
            fmt++;
        }
       
    }
    
    va_end(arg);
}

int main(){
    //char str[] = {"Hello world"};
    char c = 'K';
    int i = 7;
    float f = 3.14;
    my_printf("This is decimal : %d\n This is char: %c\n This is float %f \n", i, c, f);
}