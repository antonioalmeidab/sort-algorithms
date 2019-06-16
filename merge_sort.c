#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int[],int);
void mergeSubs(int[],int,int,int);
void mergeSort(int[],int,int);

int main(){
    int array[] = {4,1,3,6,72,4,6};
    int array_length = sizeof(array)/sizeof(array[0]);
    clock_t start, end;
    double cpu_time_used;

    printf("Array desordenado: ");
    printArray(array,array_length);

    start = clock();
    mergeSort(array, 0, array_length-1);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Array ordenado: ");
    printArray(array, array_length);
    printf("tempo utilizado: %f ms\n", cpu_time_used*1000);
    return 0;
}

void printArray(int array[], int size) {
    for(int i = 0; i < size; i++){
        printf(" %d |", array[i]);
    }
    printf("\n");
}

void mergeSubs(int array[], int left_index, int middle, int right_index) {
    int left_size, right_size;
    left_size = (middle - left_index) + 1;
    right_size = right_index - middle;

    int right_sub[right_size], left_sub[left_size];

    for (int index = 0; index < left_size; index++) {
        left_sub[index] = array[left_index + index];
    }

    for (int index = 0; index < right_size; index++) {
        right_sub[index] = array[middle + 1 + index];
    }

    int i = 0;
    int j = 0;
    int k = left_index;

    while (i < left_size && j < right_size) {
        if (left_sub[i] < right_sub[j]) {
            array[k] = left_sub[i];
            i++;
        }
        else {
            array[k] = right_sub[j];
            j++;
        }
        k++;
    }

    for (i; i < left_size; i++){
        array[k] = left_sub[i];
        k++;
    }

    for (j; j < right_size; j++) {
        array[k] = right_sub[j];
        k++;
    }
}

void mergeSort (int array[], int left_index, int right_index) {
    if (left_index < right_index) {
        int middle = left_index + (right_index - left_index)/2;

        mergeSort(array, left_index, middle);
        mergeSort(array, middle+1, right_index);

        mergeSubs(array, left_index, middle, right_index);
    }
}
