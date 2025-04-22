#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array nums, return the length of the longest strictly increasing.
Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

*/
// brute recursion  T.C O(2^n)

/*aproach
we will use pick or not pick,
//!we can only pick if our previous picked element is smaller than the one we are picking
so we need an extra argument for prev-index(not using prev-element as it can go negative)
since we need previous, we will be starting from 0th index, F(a,b)
means lis from ath index with prev element b
*/

int recur(vector<int> &v, int index, int prevIndex)
{
    if (index == v.size())
    {
        return 0;
    }
    int pick = 0;
    if (prevIndex == -1 || v[index] > v[prevIndex])
    {
        pick = 1 + recur(v, index + 1, index);
    }
    int notPick = recur(v, index + 1, prevIndex);
    return max(pick,notPick);
}

int brute(vector<int> &nums)
{
    return recur(nums, 0, -1); //-1 indicates no prev-index
}
//memoisation, since prev-index goes from -1...n-1, we offset it from 0...n 
int mem(vector<int> &v, int index, int prevIndex,vector<vector<int>>&dp)
{
    
    if (index == v.size())
    {
        return 0;
    }
    if(dp[index][prevIndex+1]!=-1)
    {
        return dp[index][prevIndex+1];
    }
    int pick = 0;
    if (prevIndex == -1 || v[index] > v[prevIndex])
    {
        pick = 1 + mem(v, index + 1, index,dp);
    }
    int notPick = mem(v, index + 1, prevIndex,dp);
    return dp[index][prevIndex+1]= max(pick,notPick);
}

int memo(vector<int> &nums)
{
    vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
    return mem(nums, 0, -1,dp); //-1 indicates no prev-index
}
//tabulation

