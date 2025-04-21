#include <bits/stdc++.h>
using namespace std;
/*
You are given an integer array coins representing coins of different denominations and an
integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of
money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.



Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

*/

// recursive:- pick-notpick with infinite suplies
int recur(vector<int> &coins, int amount, int index)
{
    if (amount == 0)
    {
        return 0;
    }
    if (index == 0)
    {
        if (amount % coins[0] == 0)
        {
            return amount / coins[0];
        }
        else
        {
            return 1e9; // amount could not be reduced to 0
        }
    }
    int notPick = recur(coins, amount, index - 1);
    int Pick = 1e9;
    if (amount >= coins[index])
    {
        Pick = 1 + recur(coins, amount - coins[index], index); // infinite supply of coins, coins[index] can be picked again
    }
    return min(Pick, notPick);
}

int BRUTE(vector<int> &coins, int amount)
{
    int n = coins.size();
    int ans = recur(coins, amount, n - 1);
    if (ans == 1e9)
    {
        return -1;
    }
    return ans;
}

// memoisation
int memo(vector<int> &coins, int amount, int index, vector<vector<int>> &dp)
{
    if (dp[index][amount] != -1)
    {
        return dp[index][amount];
    }
    if (amount == 0)
    {
        return 0;
    }
    if (index == 0)
    {
        if (amount % coins[0] == 0)
        {
            return amount / coins[0];
        }
        else
        {
            return 1e9; // amount could not be reduced to 0
        }
    }
    int notPick = memo(coins, amount, index - 1, dp);
    int Pick = 1e9;
    if (amount >= coins[index])
    {
        Pick = 1 + memo(coins, amount - coins[index], index, dp); // infinite supply of coins, coins[index] can be picked again
    }
    return dp[index][amount] = min(Pick, notPick);
}

int memoisation(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = memo(coins, amount, n - 1, dp);
    if (ans == 1e9)
    {
        return -1;
    }
    return ans;
}

// tabulation
int tabulation(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
    for (int target = 0; target <= amount; target++) // index=0
    {
        if (target % coins[0] == 0)
        {
            dp[0][target] = target / coins[0];
        }
    }
    for (int index = 0; index < n; index++)
    {
        dp[index][0] = 0;
    }
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= amount; target++)
        {
            int notPick = dp[index - 1][target];
            int pick = 1e9;
            if (target >= coins[index])
            {

                pick = 1 + dp[index][target - coins[index]]; // infinite suplies so dp[INDEX][target]
            }
            dp[index][target] = min(pick, notPick);
        }
    }
    if (dp[n - 1][amount] == 1e9)
    {
        return -1;
    }
    return dp[n - 1][amount];
}
// space optimisation
int spaceOpt(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> prev(amount + 1, 1e9);
    vector<int> cur(amount + 1, 1e9);
    for (int target = 0; target <= amount; target++) // index=0
    {
        if (target % coins[0] == 0)
        {
            prev[target] = target / coins[0];
        }
    }
    prev[0] = 0;
    cur[0] = 0;
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= amount; target++)
        {
            int notPick = prev[target];
            int pick = 1e9;
            if (target >= coins[index])
            {

                pick = 1 + cur[target - coins[index]]; // infinite suplies so dp[INDEX][target]
            }
            cur[target] = min(pick, notPick);
        }
        prev = cur;
    }
    if (prev[amount] == 1e9)
    {
        return -1;
    }
    return prev[amount];
}
