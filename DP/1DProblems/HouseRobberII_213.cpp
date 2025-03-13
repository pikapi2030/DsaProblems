#include <bits/stdc++.h>
using namespace std;
/*
house robber 1 but first and last houses are also adjacent

*/

/*aproach
maximum amount will be max( maxAmount excluding last index, maxAmount excluding first index )
//! better code at bottom
*/

int helper(vector<int> v, int flag)//if flag==0, oth index is exluded, if flag==1, n-1 index is excluded
{
    int n = v.size();
    if (n == 1)
    {
        return v[0];
    }

    if (flag == 0) // exclude v[0]
    {
        if (n == 2)
        {
            return v[1];
        }
        int prevOfprev = v[1];

        // base case
        int prev = max(v[1], v[2]); // to prevent cur-2<0, we start from 2th index, so filling first index manually
        for (int i = 3; i < n; i++)
        {

            int take = v[i] + prevOfprev;
            int notTake = prev;
            int current = max(take, notTake);
            prevOfprev = prev;
            prev = current;
        }
        return prev;
    }

    if (flag == 1) // exclude n-1
    {
        if (n == 2)
        {
            return v[0];
        }
        int prevOfprev = v[0];

        // base case
        int prev = max(v[0], v[1]); // to prevent cur-2<0, we start from 2th index, so filling first index manually
        for (int i = 2; i < n - 1; i++)
        {

            int take = v[i] + prevOfprev;
            int notTake = prev;
            int current = max(take, notTake);
            prevOfprev = prev;
            prev = current;
        }
        return prev;
    }
    return -1;//dummy return
}

int opti(vector<int> &v)
{
    int n = v.size();
    return max(helper(v, 0), helper(v, 1));
}


/*SAME APROACH BUT MUCH BETTER CODE */
class Solution 

{

public:



    int robOriginal(vector<int>& nums, int start, int end) 

    {

        int last = 0, last_last = 0, res = 0;

        

        for(int i = start; i < end; ++i)

        {

            res = max(last_last + nums[i], last);

            last_last = last;

            last = res;

        }

        return res;

    }



    int rob(vector<int>& nums) 

    {

        if(nums.empty()) return 0;

        if(nums.size() == 1) return nums[0];

        int n = nums.size();

        return max(robOriginal(nums, 0, n-1), robOriginal(nums, 1 , n));

    }

};