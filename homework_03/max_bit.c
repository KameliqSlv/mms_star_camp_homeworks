#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*,const void*)){
    void *max_elem = arr;
    for (size_t i = 1; i < n; i++) {
        void *elem = ((char*)arr + i * elem_s);
        if(cmp(elem, max_elem) > 0) {
            max_elem = elem;
        }
    }
    return max_elem;
}

int cmp_bit(int a) {
    unsigned count = 0;
    for(size_t i = 0; i < 32; i++){
        count += !!(a&(1ULL<<i));
    }
    return count;
}

int max_bit(const void *a, const void *b){
    //eturn (*(int*)a) - (*(int*)b);

    int count_a = cmp_bit(*(float*)a);
    int count_b = cmp_bit(*(float*)b);

    return count_a > count_b ? -1 : 1;

}

int main(){
    float arr[] = {3.14,3.58,4.25,2.5};
    size_t n = sizeof(arr)/ sizeof(arr[0]);
    int *max_elem = findMax(arr, n, sizeof(float), max_bit);

    for (size_t i = 0; i<n; i++) {
        printf("%f\n", arr[i]);
    }
 
    printf("The max element is %f\n", *max_elem);

    return 0;
}
