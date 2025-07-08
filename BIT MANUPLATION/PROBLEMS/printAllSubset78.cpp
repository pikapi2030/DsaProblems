#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array nums of unique elements, return all possible subsets
(the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/

/*approach
we will use the power set aproach
lets say our nums has 3 elements
so total subsets = pow(2,3)=8
now assume we have a 3 bits, how many numbers can it represent?
same as number of subsets (8)
so we will think of a 3 bits, _ _ _ , and try to fill it with all possible
combinations of 0 and 1, 1 represents to pick nums[i] to generate a subset
0 represents to not pick
now how to fill 0,1 in a 3 bit (_ _ _) simpy iterate from 0 to (2^3-1)
*/
//! T.C O( n*2^n ) S.C O(2^n *n)(near about)

bool isIthBitSet(int num,int i)
{
return (1<<i)&num;
}

vector<vector<int>> subsets(vector<int> &nums)
{
vector<vector<int>>ans;    
int n=nums.size();
int totalSubsets=1<<n;//same as pow(2,n) 
for(int number=0;number<totalSubsets;number++)
{
    vector<int>temp;
    for(int i=0;i<n;i++)
    {
     if( isIthBitSet(number,i))//pick
     {
        temp.push_back(nums[i]);
     }
    }
    ans.push_back(temp);
}
return ans;
}
