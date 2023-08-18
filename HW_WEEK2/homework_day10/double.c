/*
●	Реализирайте функция, която печата битовете на число с плаваща запетая 
от тип double. (прочетете за double precision floating point format)
●	Реализирайте функция, която печата стойностите на знаковия бит, експонентата и мантисата на число с плаваща запетая от тип double. Стойностите да се изпечатат 
в десетична бройна система все едно са интерпретирани от двоичен прав код.

*/


// double е 64-бита
// 11 бита за експонентата 
// 1 бит за знак
// 52 бита за стойност
// 15 - десетични цифри за точност

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct double_comp{
    uint64_t mantissa :52;
    uint64_t exponent :11;
    uint64_t sign :1;
} double_comp;

typedef union D{
    double d;
    double_comp c;
} D;

void print_bit(double d){

    //Връщам броя на битовете, които типът заема в паметта 
    uint64_t i = sizeof d * CHAR_BIT;
    //printf("%ld \n" , i);
    
    // копира n знака от област на паметта src в област на паметта dest .
    uint64_t j;
    memcpy(&j, &d, sizeof(i));
    //printf("%ld \n" , j);

    //обхождам променливата за да видя всеки бит от double
    while(i--){
        printf("%ld", (j >> i) & 0x1);
    }
    printf("\n");

    //0100000000001001000111101011100001010001111010111000010100011111
    //0100000000001001000111101011100001010001111010111000010100011111

    
}

void print_m_e_s(double d){
    D d1;
    d1.d = d;

    printf("Sign: %d \nExponent: %d \nMantisa: %lu\n", d1.c.sign, d1.c.exponent, d1.c.mantissa) ;

}


int main(){
    double d= 3.14;

    print_bit(d);
    print_m_e_s(d);
    return 0;
}


