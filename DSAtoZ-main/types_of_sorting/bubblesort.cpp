#include <iostream>
using namespace std;
/*
bubble sort pushes the max element at last by using adjacent swaping
the main loop goes from n-1 to 1(decremental loop)
main loop does not need to go till 0 since till then array will be sorted

the inner loop goes from 0 to n-2 then 0 to n-3 then 0 to n-4..
it should not go on the last element because in adjacent swapping we do arr[j]>arr[j+1]
if it goes to last element there would not be any j+1 element for comparison
it would throw run time error

TIME Complexity-  O(n(n+1)/2) or O(N^2)(average and worst case)
best case time complexity-O(N) (WHEN THE ARRAY IS ALREADY SORTED)


*/
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i] << " ";
    }
}

void bubblesort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        int didswap = 0; // optimising code(no need to run if array is already sorted)when
        // array is already sorted no swapping will happen so it should come out of the loop
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                didswap = 1;
            }
        }
        if (didswap == 0)
        {
            break;
        }
    }
}

int main()
{
    int a[] = {1, 4, 4, 7, 11, 25, 27, 30};
    bubblesort(a, 8);
    printarray(a, 8);
}
