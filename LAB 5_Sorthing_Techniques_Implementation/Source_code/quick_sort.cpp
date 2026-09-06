/*
Program Name: Quick Sort
Program Description: Takes an array as input and sorts its elements using
                     the Quick Sort technique
Program Creation Time: Sep 6th
Program Creator: Ashwath Raj | AP25110010712
*/

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int smallerIndex = low - 1;

    for (int currentIndex = low; currentIndex < high; currentIndex++)
    {
        if (arr[currentIndex] <= pivot)
        {
            smallerIndex++;
            swap(arr[smallerIndex], arr[currentIndex]);
        }
    }

    swap(arr[smallerIndex + 1], arr[high]);
    return smallerIndex + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int pivotIndex = partition(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
}

int main(void)
{
    int n;

    cout << "Enter Size of Array: ";
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    delete[] arr;

    return 0;
}
