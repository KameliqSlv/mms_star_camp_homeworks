#include <stdio.h>
#include <stdint.h>

void swapBytes(uint16_t* word){

  //uint16_t a = ((*word | (1 << 15))) ;
  //uint16_t b =  (!!(*word & 0xff));
  //*word = a ^ b;
  *word = (*word | (1<<15)) ^ (!!(*word & 0xff));
}

int main(){
    uint16_t word = 0x11ff;

    //0001000111111111
    // |
    //1000000000000000 //1<<15
    // =
    //1001000111111111

    
    //0001000111111111
    // &
    //1111111111111111
    //=
    //0000000000000001
    //^
    //1001000111111111
    // = 
    //1001000111111110  == 91fe

    //1001000111111110


    printf("%4x \n" ,word); 
    printf("%4x\n", !!(word&0xff) );

    swapBytes(&word);

    printf("%4x \n", word); // 91fe
}