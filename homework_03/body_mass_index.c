#include <stdint.h>
#include <stdio.h>

typedef struct {
    double weight_kg;
    uint16_t height_cm;
} Human;

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

//Body Mass Index = weight_kg / (height_meter*height_meters)
double calculate_mass_index(Human weight, Human height){
    return weight.weight_kg/(height.height_cm * height.height_cm);
}


//Body Mass Index = weight_kg / (height_meter*height_meters)
int body_mass_index(const void *a, const void *b){
    //return calculate_mass_index(*(Human*)a, *(Human*)b) - calculate_mass_index(*(Human*)a, *(Human*)b);


    //double mass = calculate_mass_index(h1.weight_kg, h1.height_kg);
    
    //return calculate_mass_index(h1, h1) - calculate_mass_index(h2, h2);
    double body_mass1 = calculate_mass_index( *(Human*)a, *(Human*)a );
    double body_mass2 = calculate_mass_index( *(Human*)b, *(Human*)b );
    
    return (body_mass1 - body_mass2)*1.0;
    //return (Human*)b - (Human*)a;
}


int main(){
    Human arr_human[] = {{75,180}, //23.1
                        {47,146}, //22
                        {140,200}}; //35
    
    size_t n = sizeof(arr_human)/sizeof(arr_human[0]);

    Human *body_mass = findMax(arr_human, n, sizeof(Human), body_mass_index);


    printf("Body mass index: %lf %d\n", body_mass->weight_kg, body_mass->height_cm);



    return 0;
}
