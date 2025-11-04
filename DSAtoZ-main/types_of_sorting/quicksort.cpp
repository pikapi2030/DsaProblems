#include <iostream>
using namespace std;

// ---------- Print Array ----------
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ---------- Partition Function ----------
int partitionindex(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (i < high && arr[i] <= pivot)
            i++;
        while (j > low && arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

// ---------- QuickSort ----------
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition = partitionindex(arr, low, high);
        quicksort(arr, low, partition - 1);
        quicksort(arr, partition + 1, high);
    }
}

// ---------- Main ----------
int main()
{
    int a[] = {8, -3, 12, 2, 1, 1, 1, -4, 0, 2, 100, 1};
    int n = sizeof(a) / sizeof(a[0]);

    quicksort(a, 0, n - 1);
    printarray(a, n);

    return 0;
}
