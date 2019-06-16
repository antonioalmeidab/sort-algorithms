#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int [],int);
void printArray(int [],int);

int main(){
    clock_t start, end;
    double cpu_time_used;

    int array[] = {7, 7, 7, 2, 2, 2, 6, 20, 14, 1};
    int size_array = sizeof(array)/sizeof(array[0]);

    printf("array desordenado: ");
    printArray(array, size_array);

    start = clock();
    selection_sort(array,size_array);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("array ordenado: ");
    printArray(array,size_array);
    printf("tempo utilizado: %f ms\n", cpu_time_used*1000);
    return 0;
}

void selection_sort(int array[], int size_array){
    int start_index = 0;

    while(start_index < size_array){
        int min_value = array[start_index];
        int min_value_index = start_index;
        for(int i = start_index+1; i < size_array; i++){
            if (array[i] < min_value) {
                min_value = array[i];
                min_value_index = i;
            }
        }
        for(int j = min_value_index-1; j >= start_index; j--){
            array[j+1] = array[j];
        }
        array[start_index] = min_value;
        start_index++;
    }
}
    


void printArray(int array[], int size_array){
    printf("[");
    for(int i = 0; i < size_array; i++){
        if(i == size_array - 1) printf("%d]\n", array[i]);
        else printf("%d, ", array[i]);
    }
}
