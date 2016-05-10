#ifndef SELECTIONMEDIAN_H_INCLUDED
#define SELECTIONMEDIAN_H_INCLUDED

#include <ctime>
#include <math.h>

int selectionMedian(int *a, int num_elements, float *time_taken, int *num_operations);

int select(int *a, int lower, int middle, int upper ,int *operations_counter);

int partitionSort(int *a, int lower, int upper ,int *operations_counter);

void swapValues(int *val_1, int *val_2);

#endif // SELECTIONMEDIAN_H_INCLUDED
