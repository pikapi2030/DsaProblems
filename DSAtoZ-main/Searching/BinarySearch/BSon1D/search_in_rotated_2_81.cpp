#include<bits/stdc++.h>
using namespace std;

/*
similar to search in roated(33) but with duplicates
and return true or false if target is present
*/

/*
our previous code will not work for just one test case 
when v[low]=v[mid]=v[high] in this condition we cannot
identify which half is the sorted half
example
v={3,1,2,3,3,3,3}  we can see right half is sorted but our computer can't

so to deal with this, if v[mid]!==target then we know neither are high,low the target
(all three equal)  so we will simply reduce the search space by doing
high--,low++

T.C O(log_2 N)(average),  O(n/2)(worst) when lot of dupicates, and we keep shrinking
(when v[mid]=v[high]=v[low]) occurs too many times we shrink half of our array

*/

bool opti(vector<int> v, int target)
{
    int n = v.size();
    int low = 0, high = n - 1;

    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (v[mid] == target)
        {
            return true;
        }
      if(v[mid]==v[high]&&v[mid]==v[low])
      {
        high--;
        low++;
        continue;
        //to recheck
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
    return false;
}

