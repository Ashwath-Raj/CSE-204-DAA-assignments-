/*
Program Name: Bucket Sort
Program Description: Takes an array as input and sorts its elements using
                     the Bucket Sort technique
Program Creation Time: Sep 6th
Program Creator: Ashwath Raj | AP25110010712
*/

#include <iostream>
#include <vector>
using namespace std;

void sortBucket(vector<int> &bucket)
{
    for (int i = 1; i < static_cast<int>(bucket.size()); i++)
    {
        int value = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > value)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = value;
    }
}

void bucketSort(int arr[], int n)
{
    if (n <= 1)
        return;

    int minValue = arr[0];
    int maxValue = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minValue)
            minValue = arr[i];
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }

    long long range = static_cast<long long>(maxValue) - minValue + 1;
    vector<vector<int>> buckets(n);

    for (int i = 0; i < n; i++)
    {
        int bucketIndex = static_cast<int>(
            (static_cast<long long>(arr[i]) - minValue) * n / range);
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (vector<int> &bucket : buckets)
        sortBucket(bucket);

    int index = 0;
    for (const vector<int> &bucket : buckets)
    {
        for (int value : bucket)
            arr[index++] = value;
    }
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

    bucketSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    delete[] arr;

    return 0;
}
