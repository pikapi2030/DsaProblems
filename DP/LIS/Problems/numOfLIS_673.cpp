#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.
Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing
subsequences of length 1, so output 5.
*/
/*appr
we maintain a 1D dp array, and a 1D cnt array
dp[i]=LIS till ith index,given that v[i] is part of LIS(same as dp used in 1D tab of LIS)
cnt[i]=number of increasing subsequences of length dp[i] till ith index including v[i] as part
of each subsequence

*/
int findNumberOfLIS(vector<int> &v)
{
    int maxLen = 1;
    int n = v.size();
    vector<int> dp(n, 1);
    vector<int> cnt(n, 1);
    for (int i = 0; i < n; i++)
    {

        for (int pi = 0; pi < i; pi++)
        {

            if (v[i] > v[pi])
            {
                if (dp[i] == 1 + dp[pi])
                {
                    cnt[i] += cnt[pi];
                }
                else if (1 + dp[pi] > dp[i])
                {
                    dp[i] = 1 + dp[pi];
                    cnt[i] = cnt[pi];
                }
            }
        }
        maxLen=max(dp[i],maxLen);
    }
    int ans=0;
    for(int i=0;i<n;i++)//all cnt[i] with maxLen as dp[i] should be added
    {
        if(dp[i]==maxLen)
        {
            ans+=cnt[i];
        }
    }
    return ans;
}
