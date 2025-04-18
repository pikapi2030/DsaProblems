#include <bits/stdc++.h>
using namespace std;
/*
You are given an integer array coins representing coins of different denominations and an
integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be
made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.
Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:
Input: amount = 10, coins = [10]
Output: 1

*/
// pick not pick
int recur(vector<int> &c, int t, int index)
{
    if (t == 0)
    {
        return 1; // only way to return change is giving now coins
    }
    if (index == 0)
    {
        if (t % c[0] == 0)
        {
            return 1; // only way to return change is to give the c[0] coin multiple times
        }
        else
        {
            return 0;
        }
    }
    int pick = 0;
    if (t >= c[index])
    {
        pick = recur(c, t - c[index], index);
    }
    int notPick = recur(c, t, index - 1);
    return pick + notPick;
}

int brute(int amount, vector<int> &coins)
{
    return recur(coins, amount, coins.size() - 1);
}

// tabulation( not writing memoisation cause i can write it)
int change(int amount, vector<int> &coins)
{
    int n=coins.size();
    vector<vector<unsigned long long>>dp(n,vector<unsigned long long>(amount+1,0));
    for(int index=0;index<n;index++)
    {
        dp[index][0]=1;
    }
    for(int t=0;t<=amount;t++)
    {
        if(t%coins[0]==0)
        {
         dp[0][t]=1;
        }
    }
    for(int index=1;index<n;index++)
    {
        for(int target=1;target<=amount;target++)
        {
            unsigned long long pick=0;
            if (target >= coins[index])
            {
                pick = dp[index][target-coins[index]];
            }
            unsigned long long notPick=dp[index-1][target];
            dp[index][target]=pick+notPick;
        
        }
    }
    return (int)dp[n-1][amount];
}
