#include <iostream>
using namespace std;
/*
quicksort selects a random number in an array called pivot sets it to the index it would
have in the sorted array
then the left and right sides of the pivot can be considered 2 new array and sortiong can
be applied recursively
main code is how to find the correct index of pivot
*/

/*
TIME COMPLEXITY
O(N*log_2 N)
O(N*log (base 2) N)
space complexity-O(N)
*/

/*
Quick Sort's in-place partitioning makes it more memory-efficient than Merge Sort in practice, but the worst-case space complexity can be higher when the partitioning is unbalanced.

Time Complexity:
Best Case: O(n log n) when the pivot choices consistently lead to balanced partitions.
Average Case: O(n log n)
Worst Case: O(n^2) when the pivot choices consistently lead to unbalanced partitions. However, with good pivot selection strategies (e.g., using the median element), this can be mitigated.

Space Complexity:
O(log n) auxiliary space for the recursive call stack in the best and average cases.
O(n) in the worst case when the partitioning is highly unbalanced.
Quick Sort's in-place partitioning makes it more memory-efficient than Merge Sort in practice, but the worst-case space complexity can be higher when the partitioning is unbalanced.

Quick Sort tends to perform well in practice and is often faster than other O(n log n) algorithms, but its worst-case time complexity is worse than Merge Sort.

Merge Sort's space complexity makes it less memory-efficient compared to some other sorting algorithms, but its stable performance and guaranteed O(n log n) time complexity in all cases make it a preferred choice for certain scenarios.

Space Complexity:
O(n) additional space is required for the temporary arrays during the merging process.
It has a space complexity of O(n) due to the need for additional space for merging.
*/

void swap(int arr[], int i, int j)
{
  int t = arr[i];
  arr[i] = arr[j];
  arr[j] = t;
}
void printarray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << " " << arr[i] << " ";
  }
}

int partitionindex(int arr[], int low, int high)
{
  int pivot = arr[low];
  int i = low;
  int j = high;
  while (j > i)
  {
    while (pivot >= arr[i] && i < high) // this loops puts i at index where pivot
    // is smaller then value, equal because we decide to put equal to pivot on left
    // i<high to prevent i from crosing boundaries
    {
      i++;
    }
    while (pivot < arr[j] && j > low)
    {
      j--;
    }
    if (i < j) // SWAP IF I AND J HAVE NOT CROSED
    {
      swap(arr, i, j);
    }
  }
  swap(arr, low, j); // placing pivot in centre
  return j;          // j is the index of pivot
}
void quicksort(int arr[], int low, int high)
{
  if (low < high)
  {
    int partition = partitionindex(arr, low, high);
    quicksort(arr, low, partition - 1);
    quicksort(arr, partition + 1, high);
  }
}
int main()
{
  int a[] = {8, -3, 12, 2, 1, 1, 1, -4, 0, 2, 100, 1};
  quicksort(a, 0, 11);
  printarray(a, 12);
}
