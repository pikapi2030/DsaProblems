#include <bits/stdc++.h>
using namespace std;
/*
You are given an integer array prices where prices[i] is the price of a given stock on the
ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may
buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the
stock before you buy again).
Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/

int rec(vector<int> &p, int k, int index, int cnt)
{
    if (cnt >= 2 * k||index==p.size())//cnt is 0 indexed
    {
        return 0;
    }
    int profit = 0;
    if (cnt % 2 == 0) // buy
    {
        profit = max(rec(p, k, index + 1, cnt + 1) - p[index], rec(p, k, index + 1, cnt));
    }
    else if (cnt % 2 != 0) // sell
    {
        profit = max(rec(p, k, index + 1, cnt + 1) + p[index], rec(p, k, index + 1, cnt));
    }
    return profit;
}

int q(vector<int> &p, int k)
{
    return rec(p, k, 0, 0);
}

//tabulation
int maxProfit(int k,vector<int>&p)
{
    int n=p.size();
    vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=2*k-1;j>=0;j--)
        {
         if(j%2==0)
         {
            dp[i][j]=max(dp[i+1][j+1]-p[i],dp[i+1][j]);
         }
         else if(j%2!=0)
         {
            dp[i][j]=max(dp[i+1][j+1]+p[i],dp[i+1][j]);
         }
        }
    }
    return dp[0][0];
}


