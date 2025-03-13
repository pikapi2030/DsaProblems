#include <bits/stdc++.h>
using namespace std;
/*
You are a professional robber planning to rob houses along a street. Each house has a
certain amount of money stashed, the only constraint stopping you from robbing each of
them is that adjacent houses have security systems connected and it will automatically
contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the
maximum amount of money you can rob tonight without alerting the police.

Example :1

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

!example 2:
nums=[2,1,1,2] max amount=4 (house 1 and house 4)
*/

/*aproach
in this quetion we have basically calculate maximum subsequence sum without having any
adjacent elements

we will use recursion(backtracking) to calculate sum of subsequences with no adjacent element
and then try to optimise using DP

*/

/*ALL T.C AND S.C
brute recursion  T.C O(2^N),S.C O(N+N)
*/
int helper(vector<int> &v, int cur)
{
    if (cur >= v.size())
    {
        return 0;
    }
    //! if we picked cur, then we will call for cur+2(adjacent indexes not allowed)
    int pick = v[cur] + helper(v, cur + 2);

    int notPick = helper(v, cur + 1);
    return max(pick, notPick);
}

int bruteR(vector<int> &v)
{
    int n = v.size();
    vector<int> temp;
    return helper(v, 0);
}
/*memoisation

*/
int memo(vector<int> &v, int cur, vector<int> &dp)
{
    if (cur >= v.size())
    {
        return 0;
    }
    if (dp[cur] != -1)
    {
        return dp[cur];
    }

    //! if we picked cur, then we will call for cur+2(adjacent indexes not allowed)
    int pick = v[cur] + memo(v, cur + 2, dp);

    int notPick = memo(v, cur + 1, dp);
    return dp[cur] = max(pick, notPick);
}

// tabulation
/*explaiation
dp[i] represent the maximum amount robbable till ith index of array
so dp[0]=v[0] (base case)

now if we take, we have to add the v[cur] to dp[cur-2], we can't take dp[cur-1] as
we have to make sure that cur-1 index is not included inour take sum
we are sure that dp[cur-2] does not include cur-1 element(refer to defenation of dp[i])

not if we do not take, we will simply take dp[cur-1] only

take=v[cur]+dp[cur-2]

notTake=d[cur-1]

//!dp[cur]=max(take,notTake)

*/
int tab(vector<int> &v)
{
    int n = v.size();
    if (n == 1)
    {
        return v[0];
    }
    vector<int> dp(n);
    dp[0] = v[0];            // base case
    dp[1] = max(v[0], v[1]); // to prevent cur-2<0, we start from 2th index, so filling first index manually
    for (int i = 2; i < n; i++)
    {
        int take = v[i] + dp[i - 2];
        int notTake = dp[i - 1];
        dp[i] = max(take, notTake);
    }
    return dp[n - 1];
}

// optimal
int opti(vector<int> &v)
{
    int n = v.size();
    if (n == 1)
    {
        return v[0];
    }

    int prevOfprev = v[0];      // base case
    int prev = max(v[0], v[1]); // to prevent cur-2<0, we start from 2th index, so filling first index manually
    for (int i = 2; i < n; i++)
    {
        int take = v[i] + prevOfprev;
        int notTake = prev;
        int current = max(take, notTake);
        prevOfprev = prev;
        prev = current;
    }
    return prev;
}
