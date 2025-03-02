#include <bits/stdc++.h>
using namespace std;

/*
DNF is used to sort an array with 3 elements
we use three pointers low,mid and high and follow three rules
from 0 to low-1 we have all the zeroes
from low to mid-1 we have all the ones
from mid to high-1 we have unsorted array
from high to n-1 we have all the twos

now we move the mid pointer
if v[mid]==0  then we swap mid and low and increment mid and low
if v[mid]==1 then we only increment mid
if v[mid]==2 then we swap mid and high-1 and decrement high

T.C O(N)
S.C O(1)

*/
void DNF(vector<int> v)
{
    int n = v.size();

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (v[mid] == 0)
        {
            swap(v[low], v[mid]);
            mid++;
            low++;
        }
        else if (v[mid] == 1)
        {
            mid++;
        }
        else // v[mid]==2
        {
            swap(v[high], v[mid]);
            high--;
        }
    }
}
