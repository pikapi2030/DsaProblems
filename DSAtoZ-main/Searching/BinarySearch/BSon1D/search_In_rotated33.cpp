#include <bits/stdc++.h>
using namespace std;

/*
given a unique rotated array(which was sorted before) and given a target
return index of target(no lenear search)
T.C should be O(logN)
*/

/*
we will use BS, but our array is not sorted but rotated

we are sure that at any point in array, the either half would be sorted
(which can be checked by comparing mid and low, mid and high)
we will check if our target is present in that sorted half
(if the sorted half's range is within our target) if yes
we eliminate the other half

T.C O(log_2 N)

*/

int opti(vector<int> v, int target)
{
    int n = v.size();
    int low = 0, high = n - 1;

    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (v[mid] == target)
        {
            return mid;
        }
        if (v[mid] >= v[low]) // if yes then left half is sorted
        {
            if (target >= v[low] && target <= v[mid]) // to check if target is present in sorted half
            {
                high = mid - 1; // eliminate right search space
            }
            else // target not in range of sorted half
            {
                low = mid + 1; // eliminate sorted half
            }
        }
        else // if right half is sorted
        {
            if (v[high] >= target && v[mid] <= target) // checking if target is present in this half
            {
                low = mid + 1; // eliminate left search space
            }
            else // target not present in this half
            {
                high = mid - 1; // eliminate sorted half
            }
        }
    }
    return -1;
}
