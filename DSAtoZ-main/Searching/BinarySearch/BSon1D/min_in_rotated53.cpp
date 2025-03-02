#include <bits/stdc++.h>
using namespace std;

/*
give a rotated array which was sorted, return min element
t.c should be O(log n)
*/

/*
we maintain a ans var
we will first try to find the sorted half,

if left half is sorted, 
our low can be the min so ans=min(ans,v[low])
if right half is sorted our mid can be the min
so ans=min(ans,v[mid])
after this we eliminate the sorted half and repeat the process

one optimization can be done is if at any point v[low]<=v[high]
which means our search space is already sorted so low 
can be our ans



*/

int optimin(vector<int> v)
{
    int n = v.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;

    while (high >= low)
    {
        int mid = (low + high) / 2;

        if(v[low]<=v[high])//this condition can be removed and code will works
        {   ans=min(ans,v[low]);//it is for extra optimisation
            break;//if condition is met, then our search space is already sorted 
        }

        if (v[low] <= v[mid]) // left half sorted
        {
            ans = min(ans, v[low]);
            low = mid + 1;
        }
        else // right half sorted
        {
            ans = min(v[mid], ans);
            high = mid - 1;
        }
    }
    return ans;
}
