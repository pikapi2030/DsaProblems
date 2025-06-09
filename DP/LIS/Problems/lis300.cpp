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
    return max(pick, notPick);
}

int brute(vector<int> &nums)
{
    return recur(nums, 0, -1); //-1 indicates no prev-index
}
// memoisation, since prev-index goes from -1...n-1, we offset it from 0...n
int mem(vector<int> &v, int index, int prevIndex, vector<vector<int>> &dp)
{

    if (index == v.size())
    {
        return 0;
    }
    if (dp[index][prevIndex + 1] != -1)
    {
        return dp[index][prevIndex + 1];
    }
    int pick = 0;
    if (prevIndex == -1 || v[index] > v[prevIndex])
    {
        pick = 1 + mem(v, index + 1, index, dp);
    }
    int notPick = mem(v, index + 1, prevIndex, dp);
    return dp[index][prevIndex + 1] = max(pick, notPick);
}

int memo(vector<int> &nums)
{
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
    return mem(nums, 0, -1, dp); //-1 indicates no prev-index
}
// 2D tabulation, -1 means no prev index, represented as 0 in the dp(not optimal)
int Tabs(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int pi = i - 1; pi >= -1; pi--)
        {
            int pick = 0;
            if (pi == -1 || v[i] > v[pi])
            {
                pick = 1 + dp[i + 1][i + 1]; // dp[x][y], here y actually represents y-1 in array
            }
            int notPick = dp[i + 1][pi + 1];
            dp[i][pi + 1] = max(pick, notPick);
        }
    }
    return dp[0][0];
}
// 1D tabulation(one array only) T.C O(N^2), SC O(N)
/*aproach
we initialise an array ans of size n with 1, ans[i] represents longestIS till ith of v(and v[i] is part of LIS)
now we use two for loops, one for trversal of ans array, inner one for checking if any
previous element(prev then i) is smaller then current, if it is we update ans[i] with
ans[prev]+1 only if current ans[i] is smaller then the new updated value

maximum from our ans array will be the ans
*/
int Tab1D(vector<int> &v)
{
    int n = v.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {

        for (int pi = 0; pi < i; pi++)
        {

            if (v[i] > v[pi])
            {
                dp[i] = max(dp[i], dp[pi] + 1);
            }
        }

        ans = max(dp[i], ans); // tell max from dp[i]
    }
    return ans;
}
//! optimal aproach( usses lower bound(BS)) T.C NlogN
/*aproach
we initialize an empty array
we traverse our v, if( v[i]>last element of array, we push it)
if not we replace v[i] either with v[i] present in our array or just greater than v[i](upper bound)
the lenght of this array is our ans
*/

int opti(vector<int> &v)
{
    vector<int> temp;
    temp.push_back(v[0]);
    for (int i = 0; i < v.size(); i++)
    {
        if (temp.back() < v[i])
        {
            temp.push_back(v[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
            temp[ind] = v[i];
        }
    }
    return temp.size();
}
/*printing LIS aproach
uses 1d tabulation
we create a hash during 1d dp computation , hash[i]=index of element prev to ith element in our LIS

*/

vector<int> PrintingLis(vector<int> &v)
{
    vector<int> Lis;
    int lastIndex = -1;
    int n = v.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, -1);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int pi = 0; pi < i; pi++)
        {

            if (v[i] > v[pi] && 1 + dp[pi] > dp[i])
            {
                dp[i] = 1 + dp[pi];
                hash[i] = pi;
            }
        }

        if (dp[i] > ans) // tell max from dp[i]
        {
            ans = dp[i];
            lastIndex = i;
        }
    }
    // printing LIS
    vector<int> LIS;
    if (lastIndex == -1)
    {
        return {v[0]};
    }
    while (hash[lastIndex] != -1)
    {
        LIS.push_back(v[lastIndex]);
        lastIndex = hash[lastIndex];
    }
    return LIS;
}
