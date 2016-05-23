#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include <stdlib.h>
#include "bruteForceMedian.h"
#include "selectionMedian.h"
#include "tests.h"

#define MIN_INPUT_SIZE 0
#define MAX_INPUT_SIZE 1000
#define STEP_INPUT_SIZE 3
#define NUM_AVERAGES 2000

#define MS_PER_SEC 1000

using namespace std;

// Creates an array of random numbers for a given size
int *createRandomArray(int num_elements);

// writes the results to a csv file
int writeResultsToFile(int num_elements, int *input_size, float *brute_time, int *brute_operations, float *select_time, int *select_operations);

int main()
{
    int do_test;
    int num_datapoints = (MAX_INPUT_SIZE - MIN_INPUT_SIZE)/STEP_INPUT_SIZE;

    srand(clock());

    cout << "Would you like to run the tests? (0 = No, 1 = Yes)"<< endl;
    cin >> do_test;
    if (do_test > 0){
        run_tests();
        return 0;
    };

    int *input_size = new int[num_datapoints];
    float *brute_time = new float[num_datapoints];
    float *select_time = new float[num_datapoints];
    int *brute_operations = new int[num_datapoints];
    int *select_operations = new int[num_datapoints];

    #pragma omp parallel for
    for (int i=0; i < num_datapoints; i++) { // for each test
            input_size[i] = MIN_INPUT_SIZE+(i*STEP_INPUT_SIZE);

            cout << "Input Size = " << input_size[i] << endl;

            brute_time[i] = 0;
            select_time[i] = 0;
            brute_operations[i] = 0;
            select_operations[i] = 0;

        for (int j = 0; j < NUM_AVERAGES; j++){
            int *a = createRandomArray(input_size[i]);

            bruteForceMedian(a, input_size[i], &brute_time[i], &brute_operations[i] );
            selectionMedian(a, input_size[i], &select_time[i], &select_operations[i] );

            delete[] a;
        };

        brute_time[i] = (brute_time[i]*(float)MS_PER_SEC)/((float)NUM_AVERAGES*(float)CLOCKS_PER_SEC);
        select_time[i] = (select_time[i]*(float)MS_PER_SEC)/((float)NUM_AVERAGES*(float)CLOCKS_PER_SEC);

        brute_operations[i] = (int)brute_operations[i]/NUM_AVERAGES;
        select_operations[i] = (int)select_operations[i]/NUM_AVERAGES;

        cout << "   Brute Force Algorithm" << endl;
        cout << "       Time Taken(ms) = " << brute_time[i] << endl;
        cout << "       Num Operations = " << brute_operations[i] << endl;

        cout << "   Selection Algorithm" << endl;
        cout << "       Time Taken(ms) = " << select_time[i] << endl;
        cout << "       Num Operations = " << select_operations[i] << endl << endl;


    };

    writeResultsToFile(num_datapoints, input_size, brute_time, brute_operations, select_time, select_operations);

    delete[] input_size;
    delete[] brute_time;
    delete[] select_time;
    delete[] brute_operations;
    delete[] select_operations;

    return 0;
}

int *createRandomArray(int num_elements){
    int *a = new int[num_elements];

    for ( int i = 0 ; i < num_elements ; i++) {
        a[i] = rand() % 100000000 + 1;
    };

    return a;
}

int writeResultsToFile(int num_elements, int *input_size, float *brute_time, int *brute_operations, float *select_time, int *select_operations){

    ofstream myfile ("results.csv");
    if (myfile.is_open())
    {
        myfile << "input size" << "," << "brute force - time taken" << "," << "brute force - number operations";
        myfile << "," << "select - time taken" << "," << "select - number operations" << endl;
        for ( int i = 0 ; i < num_elements ; i++) {
            myfile << input_size[i] << "," << brute_time[i] << "," << brute_operations[i];
            myfile << "," << select_time[i] << "," << select_operations[i]<< endl;
        };
        myfile.close();
    }
    else cout << "Unable to open file";
    return 0;
}
