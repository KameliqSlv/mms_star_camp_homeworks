#include <stddef.h>
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
int cmp_int(const void *a, const void *b){
    return (*(int*)a) - (*(int*)b);
    //return (*(int*)a) > (*(int*)b) ? -1 : 1;
}

int main(){
    int arr[] = {1,2,-1,3,5,11,12,13,2,100,22};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int *max_elem = findMax(arr, n, sizeof(int), cmp_int);

    for (size_t i = 0; i<n; i++) {
        printf("%d\n", arr[i]);
    }
 
    printf("The max element is %d\n", *max_elem);

    return 0;
}
