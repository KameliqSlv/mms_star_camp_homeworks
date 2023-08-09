#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    /*
        Направете програма, в която потребителят въвежда от стандартния 
        вход цяло число n. 
    */

    int n;
    printf("Input n value: ");
    scanf("%d", &n);

    double *arr = malloc(sizeof(double)*n);
    if(!arr){
        printf("Don't allocated memory");
        exit(-1);
    }
    
    //[ 0.0 - 1.0 ]
    for(size_t i =0;i<n;i++){
        arr[i] = rand() % 1001/1000.;
    }

    /*
        След това се въвежда ново число m и масивът се
         да се разшири с нови m елемента.
    */
    int m;
    printf("Input m value: ");
    scanf("%d", &m);

    double *new_arr_m = realloc(arr, sizeof(double)*(n + m));
    if(!arr){
        printf("Don't allocated memory");
        exit(-1);
    } else {
        arr = new_arr_m;
    }


    //[ 1.00 - 2.00 ]
    for(size_t i =0;i< n + m;i++){
        arr[n + i] = (rand() % 1001 + 1000) / 1000.;
    }   

    int p;
    printf("Input p size: ");
    scanf("%d", &p);

    double *new_arr_p = realloc(arr, sizeof(double)*(n + m + p));
    if(!arr){
        printf("Don't allocated memory");
        exit(-1);
    }else{
        arr = new_arr_p;
    }

    for(size_t i =0;i< n + m + p;i++){
        arr[n + m + i] = (rand() % 1001 + 2000) / 1000.;
    }
      for(size_t i = 0 ; i < n + m + p; i++){
        printf("%.2lf ", arr[i]);
    }
    printf("\n");  


    free(arr);

}