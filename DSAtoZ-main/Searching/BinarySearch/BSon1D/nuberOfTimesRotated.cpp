#include<bits/stdc++.h>
using namespace std;

/*
given an array calculate how many times an array is left rotated by one
the array was sorted previously and contains only unique
expected T.C O(logN)
*/

/*
the amount of time an array is left rotated by one = index of the min element
so we will use B.S to find that index
tip: since we need to find the index, do not use min function, but write it manually
to find the index
*/

int optimin(vector<int> v)
{
    int n = v.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index=-1;

    while (high >= low)
    {
        int mid = (low + high) / 2;

        if(v[low]<=v[high])
        {   
            if(v[mid]<ans)
            {
                index=mid;
                ans=v[mid];
            }
            break;
        }

        if (v[low] <= v[mid]) 
        {
            if(v[low]<v[mid])
            {
                index=low;
                break;
                //if whole input array already sorted(edge case)
            }
            if(v[mid]<ans)
            {
                index=mid;
                ans=v[mid];
            }
            low = mid + 1;
        }
        else 
        {
            if(v[mid]<ans)
            {
                index=mid;
                ans=v[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}


