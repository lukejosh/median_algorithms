#include "tests.h"

void run_tests(){
    int test_size;

    cout << "Test 1" << endl;
    test_size = 5;
    int test1 [test_size] = { 1, 2, 3, 4, 5 };
    print_array(test1, test_size);
    cout << "   Passed = " << get_results(test1, test_size, 3, 3) << endl;
    delete[] test1;

    cout << "Test 2" << endl;
    test_size = 6;
    int test2 [test_size] = { 1, 2, 3, 4, 5, 6 };
    print_array(test2, test_size);
    cout << "   Passed = " << get_results(test2, test_size, 3, 4) << endl;
    delete[] test2;

    cout << "Test 3" << endl;
    test_size = 5;
    int test3 [test_size] = { 1, 2, 3, 3, 5};
    print_array(test3, test_size);
    cout << "   Passed = " << get_results(test3, test_size, 3, 3) << endl;
    delete[] test3;

}

bool get_results(int* a, int num_elements, int brute_expected,int selection_expected){

    bool brute_result =  get_brute_results(a,num_elements,brute_expected);

    bool selection_result =  get_selection_results(a,num_elements,selection_expected);

    return (brute_result && selection_result);

}


bool get_brute_results(int* a, int num_elements, int expected){
    int operations = 0;
    float time = 0;
    int ans;
    bool result;

    ans = bruteForceMedian(a, num_elements, &time, &operations);

    result = (ans == expected);

    cout << "       Brute Force Algorithm" << endl;
    cout << "           Num Operations = " << operations << endl;
    cout << "           Answer = " << ans << endl;
    cout << "           Expected = " << expected << endl;
    cout << "           Passed = " << result << endl;


    return result;
}

// Returns true if the select median returns the correct expected result
bool get_selection_results(int* a, int num_elements, int expected){
    int operations = 0;
    float time = 0;
    int ans;
    bool result;

    ans = selectionMedian(a, num_elements, &time, &operations);

    result = (ans == expected);

    cout << "       Selection Algorithm" << endl;
    cout << "           Num Operations = " << operations << endl;
    cout << "           Answer = " << ans << endl;
    cout << "           Expected = " << expected << endl;
    cout << "           Passed = " << result << endl;

    return result;
}

void print_array(int* a, int length){
    cout << "   Array = [ ";
    for (int i = 0; i < length; i++){
        cout << a[i] << " ";
    };
    cout << "]" << endl;
}
