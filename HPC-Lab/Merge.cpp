#include <iostream>
#include <omp.h>
using namespace std;

void merge(int a[], int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    int left[leftSize], right[rightSize];
    for (int i = 0; i < leftSize; i++)
        left[i] = a[low + i];
    for (int i = 0; i < rightSize; i++)
        right[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }
    while (i < leftSize)
        a[k++] = left[i++];
    while (j < rightSize)
        a[k++] = right[j++];
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int n;
    cout << "Enter total number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    double start_time, end_time;

    // Sequential merge sort
    start_time = omp_get_wtime();
    mergeSort(a, 0, n - 1);
    end_time = omp_get_wtime();
    cout << "Sequential Time: " << end_time - start_time << endl;

    // Parallel merge sort
    start_time = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single
        mergeSort(a, 0, n - 1);
    }
    end_time = omp_get_wtime();
    cout << "Parallel Time: " << end_time - start_time << endl;

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}

