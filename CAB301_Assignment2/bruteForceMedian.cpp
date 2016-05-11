#include "bruteForceMedian.h"

int bruteForceMedian(int *a, int num_elements, float *time_taken, int *num_operations){
    int num_smaller, num_equal, operations_counter = 0, k;

    clock_t start = clock();

    k = ceil(num_elements/2.0);

    for(int i = 0; i < num_elements; i++){
        num_smaller = 0;
        num_equal = 0;
        for(int j = 0; j < num_elements; j++){
                operations_counter++;
                if (a[j] < a[i]){
                    num_smaller++;
                }else{
                    //operations_counter++;
                    if(a[j] == a[i]){
                    num_equal++;
                    };
                };
        };
        if (num_smaller < k && k <= (num_smaller + num_equal)){
            *num_operations = *num_operations + operations_counter;
            *time_taken = *time_taken + (float)(clock() - start);

            return a[i];
        };
    }
}
