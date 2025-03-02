#include <bits/stdc++.h>
using namespace std;

/*
Used to sort an array with a fixed range of data.
Time complexity: O(N)
*/

void IndexInputswap(vector<int> &v, int i, int j) // pass indexes, not values
{
    int a = v[i];
    v[i] = v[j];
    v[j] = a;
}

void cyclicSort(vector<int> &v) // assuming range is 1 to n
{
    int i = 0;
    while (i < v.size())
    {
        if (v[i] > 0 && v[i] <= v.size() && v[i] != i+1)
        {
            // Swap the number to the correct index
            IndexInputswap(v, v[i] - 1, i);
        }
        else
        {
            // Move to the next index if the element is already in place
            i++;
        }
    }
}

int main() {
    vector<int> arr = {3, 4, 2, 1};
    cyclicSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
