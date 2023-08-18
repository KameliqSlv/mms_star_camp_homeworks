#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int value(const char **str, int *num);
int priority(const char **str);
int eval(const char **str);

int main(){
    char str[20];

    while(1){
        scanf("%s", str);

    
        const char *str_p = str;
        printf("%d\n", eval(&str_p));
    }
    
}


int value(const char **str, int *num){
    char c = **str;
    if (isdigit(c)){
        char *p2;
        int val = strtol(*str, &p2, 0);
        *str = p2;
        if(num) *num = val;  
        return '1';
    }
    (*str)++;
    return c;
}

int priority(const char **str){
    int num;
    int op = value(str, &num);
    if(op == '1') return num;
    else if(op == '-') return -num;
    else if(op == '('){
        num = eval(str);
        return num;
    }
}

int eval(const char **str){
    int num = priority(str);
    while(1){
    int op = value(str, NULL);
    switch (op) {
        case '+':
            num += priority(str);
            break;
        case '-':
            num -= priority(str);
            break;
        case '*':
            num *= priority(str);
            break;
        case '/':
            num /= priority(str);
            break;
        case '^':
            num = pow(num,priority(str));
            break;
        default:
            return num;
            break;
    }
    }
}


