#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>

typedef struct points{
    double x;
    double y;
    double z;
}points;

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

const points O  = {0.,0.,0.};

double dist(points a, points b) {
    //distance = sqrt( (x2 – x1) * (x2 – x1) + (y2 – y1) * (y2 – y1) );
    //return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z) );
   double dx,dy,dz;
    dx = b.x - a.x;
    dy = b.y - a.y;
    dz = b.z - a.z;

    return sqrt(dx*dx + dy*dy + dz*dz)*1.0;
}

int cmp_points(const void *p1, const void *p2){
    double dist1 = dist(*(points*)p1, O);
    double dist2 = dist(*(points*)p2, O);

    return (dist1 - dist2)*1.0;
}

int cmp_int(const void *a, const void *b){
    return (*(int*)a) - (*(int*)b);
    //return (*(int*)a) > (*(int*)b) ? -1 : 1;
}

int main(){
    uint64_t arr[] = {1,2,3,4, 5};
    size_t n1=  sizeof(arr)/ sizeof(arr[0]);
    uint64_t *max_elem2 = findMax(arr, n1, sizeof(uint64_t), cmp_int);
    printf("Max elemnt in uint64_t array is %lu\n", *max_elem2);
    
    points ptr_arr[] = {{10,11,12},
                        {77,2,69},
                        {1,2,3}};
    size_t n2 = sizeof(ptr_arr) / sizeof(ptr_arr[0]);
    points* maxPoint = findMax(ptr_arr, n2, sizeof(points), cmp_points);
    printf("The max point is %lf %lf %lf\n", maxPoint->x, maxPoint->y, maxPoint->z);

    return 0;
}
