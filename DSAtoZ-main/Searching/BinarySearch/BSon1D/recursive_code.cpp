#include <bits/stdc++.h>
using namespace std;
/*
recursive binary code
T.C  O(log_2 (N))  log base 2 N

*/

/*OVERFLOW CASE
if our high=INT_MAX then (low+INT_MAX)/2 gives overflow error

use long long for high and low  to solve this issue
OR
 right mid = low+(high-low)/2 (mathematically gives same value as (low+high)/2)
prevents overflow by doing (high-low)/2+low  

*/

int BS(vector<int> v, int low, int high, int target)
{
    int mid = (high + low) / 2;
    if (low > high)
    {
        return -1;
    }

    if (v[mid] == target)
    {
        return mid;
    }

    else if (v[mid] > target)
    {
        return BS(v, low, mid - 1, target); // high changes to mid -1
    }

    else // mid<target
    {
        return BS(v, mid + 1, high, target);
    }
}
