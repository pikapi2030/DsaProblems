#include <bits/stdc++.h>
using namespace std;

/*
given an array and a target x, return floor and ceiling in a pair

floor- just smaller number than x or EQUAL to x if x is present
ceiling- just greater num than x or EQUAL to x if x is present
*/

/*aproach
celing is basicaly value at lowerd bound index
and floor is value at lower bound index with reverse sighns
*/

pair<int, int> FloorAndCeiling(vector<int> v, int target)
{
    int n = v.size();
    int ceiling = -1;
    int floor = -1;
    long long low = 0, high = n - 1;
    // calculating celing(lowerbound value)
    while (high >= low)
    {
        long long mid = (low + high) / 2;

        if (v[mid] >= target)
        {
            ceiling = v[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    // calculatig floor
    high = n - 1;
    low = 0;
    while (high >= low)
    {
        long long mid = (high + low) / 2;

        if (v[mid] <= target)
        {
            floor = v[mid];
            low = mid + 1;
        }
        else//v[mid]>target
        {
            high=mid-1;
        }
    }
    return {floor,ceiling};
}