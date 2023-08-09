#include <stdarg.h>
#include <stdio.h>
#include <time.h>

void printf_time(const char *format, ...){
    va_list arg;
    va_start(arg, format);

    time_t t = time (NULL) ;
    struct tm* now = localtime(&t);
    char buff[30];

    int time = strftime(buff, sizeof(buff), " %d.%m.%Y - %H:%M:%S " , now);
    printf("[%s]", buff);
    vprintf(format, arg);
    va_end(arg);
}



int main(){
    printf_time("%d %d \n", 10 , 20);
}