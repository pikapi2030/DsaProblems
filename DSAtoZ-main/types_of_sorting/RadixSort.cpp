#include <bits/stdc++.h>
using namespace std;

void PrintArray(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << v[i] << " ";
    }
    cout << endl;
}

int MaxElement(int v[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    return max;
}

void CountSort(int v[], int n, int pos)
{
    int hash[10] = {}; // only 0 to 9 digits are possible
    for (int i = 0; i < n; i++)
    {
        int digit = (v[i] / pos) % 10; // extract digit at 'pos' place
        hash[digit]++;
    }

    int sum = 0;

    for (int i = 0; i < 10; i++) // hash modified to cumulative sum array
    {
        sum += hash[i];
        hash[i] = sum;
    }

    int ans[n];
    for (int i = n - 1; i >= 0; i--) // must loop from the end to maintain stability
    {
        int digit = (v[i] / pos) % 10;
        int index = hash[digit] - 1; // index after sorting of v[i], with respect to digit
        ans[index] = v[i];
        hash[digit]--;
    }

    // Copy loop
    for (int i = 0; i < n; i++)
    {
        v[i] = ans[i];
    }
}

void RadixSort(int v[], int n)
{
    int MaxE = MaxElement(v, n);

    for (int pos = 1; MaxE / pos > 0; pos = pos * 10)
    {
        CountSort(v, n, pos);
    }
}

int main()
{
    int v[7] = {12, 43, 56, 22, 1, 26, 79};
    RadixSort(v, 7);
    PrintArray(v, 7);
}
