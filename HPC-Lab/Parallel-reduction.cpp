#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

// Function to find minimum value in an array
int parallelMin(const vector<int>& arr) {
    int min_val = arr[0];
#pragma omp parallel for reduction(min:min_val)
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

// Function to find maximum value in an array
int parallelMax(const vector<int>& arr) {
    int max_val = arr[0];
#pragma omp parallel for reduction(max:max_val)
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

// Function to find sum of all elements in an array
int parallelSum(const vector<int>& arr) {
    int sum = 0;
#pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < arr.size(); ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to find average of all elements in an array
double parallelAverage(const vector<int>& arr) {
    int sum = parallelSum(arr);
    return static_cast<double>(sum) / arr.size();
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    
    cout << "Min: " << parallelMin(arr) << endl;
    cout << "Max: " << parallelMax(arr) << endl;
    cout << "Sum: " << parallelSum(arr) << endl;
    cout << "Average: " << parallelAverage(arr) << endl;

    return 0;
}

