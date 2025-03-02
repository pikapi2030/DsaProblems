#include <bits/stdc++.h>
using namespace std;

/*
Problem statement: Given two sorted arrays v1[] and v2[] of sizes n and m
in non-decreasing order. Merge them in sorted order. Modify arr1 so that it
contains the first N elements and modify arr2 so that it contains the last M elements.
*/

/*BRUTE
we create a third array v3, keep one pointer for each array(the input ones)
and compare and put them in our third array
if v1[i]>v2[j] then v3.pushback(v2[j]) , j++;
after that we again put all elements from v3 back to v1 and v2
the first n elements of v3 kept in v1(n is size of v1) and remaining in v2

T.C O(n+m)+O(n+m)
s.c O(n+m)
*/

void brute(vector<int> v1, int n, vector<int> v2, int m)
{
    vector<int> v3;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (v1[i] > v2[j])
        {
            v3.push_back(v2[j]);
            j++;
        }
        else
        {
            v3.push_back(v1[i]);
            i++;
        }
    }
    while (j < m)
    {
        v3.push_back(v2[j]);
        j++;
    }
    while (i < n)
    {
        v3.push_back(v1[i]);
        i++;
    }

    for (int k = 0; k < n; k++)
    {
        v1[k] = v3[k];
    }
    for (int k = n; k < m + n; k++)
    {
        v2[k - n] = v3[k];
    }
}

/*OPTIMAL
we use the fact that arrays are sorted
we go at last elment of v1 and first element of v2 and compare them
we use two pointers i and j
if v1[i]>v2[j] then v1[i] should belong to the v2 array since v2 array is going to hold
the larger elements(look at outputs) and v1[i]<v2[j] then break as correct
elements have been placed

so if v[i]>v2[j] we will simply swap them and increment j and decrement i
after doing this we have managed to place correct elments in correct array but not in correct
order so we will simply sort both arrays

T.C O( min(n,m))+O(nlogn)+O(mlogm)
s.c O(1)

*/

void opti(vector<int> &v1, vector<int> &v2)
{
    int n = v1.size();
    int m = v2.size();
    int i = n - 1; // at last element of v1
    int j = 0;     // at first element of v2

    while(j<m&&i>=0)
    {
        if(v1[i]>v2[j])
        {
            swap(v1[i],v2[j]);
        i--;
        j++;

        }
        else
        {
            break;
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
}

/*OPTIMAL 2
THE GAP METHOD
T.C O(log_2(n+m))*O(n+m)
s.c O(1)
harder to understand so will do it later(leaving the code)
*/



#include <bits/stdc++.h>
using namespace std;

void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}


