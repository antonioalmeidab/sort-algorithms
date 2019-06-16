#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;

void swap (int *first, int *second) {
    int aux = *first;
    *first = *second;
    *second = aux;
}

void bubbleSort (int values[], int amount_values) {
    start = clock();
    for (int curr_round = 0; curr_round < amount_values - 1; curr_round++)
        for (int curr_value = 0; curr_value < amount_values - curr_round - 1; curr_value++)
            if (values[curr_value] > values[curr_value + 1])
                swap(&values[curr_value], &values[curr_value + 1]);
    end = clock();
}

void printArray (int values[], int size) {
    printf("[");
    for (int i = 0; i < size; i++)
        printf(" %d ", values[i]);
    printf("]\n");
}

int main() {
    int values[] = {5, 1, 4, 2, 8, 10, 34, 12, 9, 32};
    int amount_values = sizeof(values)/sizeof(values[0]);
    
    printf("Original array: ");
    printArray(values, amount_values);

    // Bubble Sort
    printf("\n\nBubble Sort: ");
    bubbleSort(values, amount_values);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printArray(values, amount_values);
    printf("Time used: %f\n\n", cpu_time_used);
    
    return 0;
}
