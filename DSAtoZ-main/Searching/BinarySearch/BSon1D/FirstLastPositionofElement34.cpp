#include <bits/stdc++.h>
using namespace std;
/*
Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/

/*BRUTE

using one forloop
maintain a first=-1,last-1
if(v[i]==target)
{
if(first==-1)
{
first=i;
}
last=i;
}

T.C O(N)

*/

vector<int> BRUTE(vector<int> v, int target)
{
    int n = v.size();
    int first = -1, last = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == target)
        {
            if (first == -1)
            {
                first = i;
            }
            last = i;
        }
    }
    return {first, last};
}

/*OPTI
we calculate lower and upper bound
we check is our lower bound points to target or not and is not equal to size of v
if our lower bound does not point to target or is equal to size of v then
target is not present in array and we return {-1,-1}
return {lp,up-1};

T.C O(2*log_2 N)
*/

vector<int> OPTI(vector<int> &v, int target)
{
    int n = v.size();

    int lb = n;
    int up = n;
    int low = 0, high = n - 1;

    // Find the lower bound (first occurrence of target)
    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (v[mid] >= target)
        {
            lb = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    // Validate the lower bound
    if (lb == n || v[lb] != target)
    {
        return {-1, -1}; // target not found
    }

    low = 0;
    high = n - 1;

    // Find the upper bound (last occurrence of target)
    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (v[mid] > target)
        {
            up = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return {lb, up - 1};
}

/*OPTIMAL 2(pure BS)

it may be required to solve the problem without using any lower or upper bounds
so we will use pure BS

we maintain first and last vars initialized to -1

to find first
we will slightly modify BS
during BS if v[mid]==target then intead of return we will store mid
eliminate right search space(we need lowest index for first)
so we will move high=mid-1

*/

vector<int> OPTIBS(vector<int> &v, int target)
{
    int n = v.size();
    int first = -1, last = -1;
    int low = 0, high = n - 1;

    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (v[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (v[mid] < target)
        {
            low = mid + 1;
        }
        else // v[mid]>target
        {
            high = mid - 1;
        }
    }
    if(first==-1){return {first,last};}
    high = n - 1, low = 0;
    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (v[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if(v[mid]>target)
        {
            high=mid-1;
        }
        else//v[mid]<target
        {
            low=mid+1;
        }
    }
    return {first,last};
}
