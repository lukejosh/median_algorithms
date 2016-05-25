#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include <stdlib.h>
#include "bruteForceMedian.h"
#include "selectionMedian.h"
#include "tests.h"

int selectionMedian(int *a, int num_elements, float *time_taken, int *num_operations){
    int answer, operations_counter = 0;

    clock_t start = clock();

    if (num_elements == 1){
        answer = a[0];
    } else {
        answer = select(a, 0, floor(num_elements/2) , num_elements -1, &operations_counter);
    }

    *num_operations = *num_operations + operations_counter;
    *time_taken = *time_taken + ((float)clock() - (float)start);

    return answer;
}

int select(int *a, int lower, int middle, int upper ,int *operations_counter){

    int pos = partitionSort(a,lower,upper,operations_counter);

    if (pos == middle){
        return a[pos];
    }else{

        if (pos > middle){
            return select(a, lower, middle , pos-1, operations_counter);
        } else if (pos < middle){
            return select(a, pos+1, middle , upper, operations_counter);
        };
    };
}

int partitionSort(int *a, int lower, int upper ,int *num_operations){
    int pivot_val = a[lower];
    int pivot_loc = lower;
    int operations_counter = 0;

    for (int i = lower+1; i <= upper; i++){
        if (a[i] < pivot_val & (operations_counter++ | 1)){
            pivot_loc++;
            swapValues(&a[pivot_loc], &a[i]);
        }
    }
    swapValues(&a[lower], &a[pivot_loc]);

    *num_operations = *num_operations + operations_counter;
    return pivot_loc;
}

void swapValues(int *val_1, int *val_2){
    int *temp = val_1;
    val_1 = val_2;
    val_2 = temp;
}

