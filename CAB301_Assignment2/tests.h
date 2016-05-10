#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "bruteForceMedian.h"
#include "selectionMedian.h"

using namespace std;

// A function which performs all tests on the algorithms
void run_tests();

// Returns true if the both median algorithm returns the correct expected results
bool get_results(int* a, int num_elements, int brute_expected,int selection_expected);

// Returns true if the brute median returns the correct expected result
bool get_brute_results(int* a, int num_elements, int expected);

// Returns true if the select median returns the correct expected result
bool get_selection_results(int* a, int num_elements, int expected);

// Simple method to print an array
void print_array(int* a, int length);

#endif // TESTS_H_INCLUDED
