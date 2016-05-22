#include "selectionMedian.h"

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

    //*operations_counter =  *operations_counter + 1;
    if (pos == middle){
        return a[pos];
    }else{
        //*operations_counter =  *operations_counter + 1;
        if (pos > middle){
            return select(a, lower, middle , pos-1, operations_counter);
        } else {
            //*operations_counter =  *operations_counter + 1;
            if (pos < middle){
                return select(a, pos+1, middle , upper, operations_counter);
            };
        };
    };
}

int partitionSort(int *a, int lower, int upper ,int *operations_counter){
    int pivot_val = a[lower];
    int pivot_loc = lower;

    for (int i = lower+1; i <= upper; i++){
        *operations_counter =  *operations_counter + 1;
        if (a[i] < pivot_val){
            pivot_loc++;
            swapValues(&a[pivot_loc], &a[i]);
        }
    }
    swapValues(&a[lower], &a[pivot_loc]);
    return pivot_loc;
}

void swapValues(int *val_1, int *val_2){
    int *temp = val_1;
    val_1 = val_2;
    val_2 = temp;
}

