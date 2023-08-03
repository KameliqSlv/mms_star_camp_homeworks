#include <stdio.h>
#include <stdint.h>

void swapBytes(uint16_t* word){


  *word = ((*word << 8) & 0xff00) | ((*word >> 8) & 0x00ff);

}

int main(){
    uint16_t word = 13;
    //13 == 0000000000001101
    //      00001101 00000000

    
    printf("%2x \n" ,word);

    swapBytes(&word);

    printf("%2x \n", word);
}