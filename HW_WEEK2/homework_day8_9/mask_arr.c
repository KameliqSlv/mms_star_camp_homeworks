#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index){
    uint32_t new_mask = ~(1<<bit_index);

    for (size_t i = 0; i< nitems; i++) {
        maskArr[i] &= new_mask;
    }

    return *maskArr;
}

int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index){
    uint32_t new_mask = (1 << bit_index);

    for (size_t i = 0; i<nitems; i++) {
        maskArr[i] |= new_mask;
    }

    return *maskArr;
}

int checkBits(uint32_t* maskArr, size_t len, size_t bit_index){
    uint32_t new_mask = (1 << bit_index);

    for(size_t i = 0; i < len;i++){
        if((maskArr[i]&new_mask) == 0) return 0;
        else if((maskArr[i]&new_mask) == 1) return 1;
        else return -1;
    }
    return *maskArr;
}

int main(){
    uint32_t mask_arr[] = {11,20,31,40};
    int n = sizeof(mask_arr)/sizeof(mask_arr[0]);
    for(size_t i = 0; i < n;i++){
        printf("%d ", mask_arr[i]);
    }
    printf("\n");
    
    clearBits(mask_arr, n, 0);
    for(size_t i = 0; i < n;i++){
        printf("%x ", mask_arr[i]);
    }
    printf("\n");


    uint32_t mask_arr2[] = {11,20,31,40};
    setBits(mask_arr2, n, 1);
    for(size_t i = 0; i < n;i++){
        printf("%x ", mask_arr2[i]);
    }
    printf("\n");

    uint32_t mask_arr3[] = {11,20,31,40};
    int bit_index = 0;
    int res = checkBits(mask_arr3, n, bit_index);
    for(size_t i = 0; i < n;i++){
        printf("%x ", mask_arr2[i]);
    }
    printf("\n");

    if(res == 0) 
        printf("Всички елементи в mask_arr3 имат стойност 0 на бита с индекс %d\n", bit_index);
    else if(res == 1)         
        printf("Всички елементи в mask_arr3 имат стойност 1 на бита с индекс %d\n", bit_index);
    else {
        printf("%d има стойност 1 за някои елементи на mask_arr и стойност 0 за други елементи на mask_arr \n" ,bit_index);
    }
    

    return 0;
}