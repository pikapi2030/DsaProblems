#include <bits/stdc++.h>
using namespace std;
/*
given an array, return the number of subsequences with sum k
*/

int helper(vector<int> &v, int k, vector<int> &temp, int index, int sum)
{
    int n = v.size();
    if (index >= n)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }

    temp.push_back(v[index]); // pick
    sum += v[index];
    int pick = helper(v, k, temp, index + 1, sum); // pick call
    temp.pop_back();
    sum -= v[index];
    int notPick = helper(v, k, temp, index + 1, sum); // non pick call
    return notPick + pick;
}

int perfectSum(vector<int> &v, int k)
{
    vector<int> temp;

    return helper(v, k, temp, 0, 0);
}

// MORE INTUITIVE APROACH T.C O(2^N) S.C O(N)

long long BetterHelp(vector<int> &v, int target, int index)
{
    // if conditions for the edge case example 0,1,3 k=4
    if (index == 0)
    {
        if (target == 0 && v[0] == 0)
            return 2; // pick or not pick
        if (target == 0 || v[0] == target)
            return 1;
        return 0;
    }

    int pick = 0;
    if (target >= v[index])
    {
        pick = BetterHelp(v, target - (long)v[index], index - 1);
    }
    int notPick = BetterHelp(v, target, index - 1);
    return (pick + notPick) % (int)(1e9 + 7);
}

int better(vector<int> &v, int k)
{
    int n = v.size();
    return BetterHelp(v, k, n - 1); // reprsents number of subsets with sum k till (n-1)th index
}

// MEMOISATION T.C O(N*Sum) S.C O(N*Sum)+O(N)
#include <bits/stdc++.h>
using namespace std;
long long memo(vector<int> &v, int target, int index, vector<vector<long>> &dp)
{
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }
    // if conditions for the edge case example 0,1,3 k=4
    if (index == 0)
    {
        if (target == 0 && v[0] == 0)
            return 2; // pick or not pick
        if (target == 0 || v[0] == target)
            return 1;
        return 0;
    }

    int pick = 0;
    if (target >= v[index])
    {
        pick = memo(v, target - (long)v[index], index - 1, dp);
    }
    int notPick = memo(v, target, index - 1, dp);
    return dp[index][target] = (pick + notPick) % (int)(1e9 + 7);
}

int findWays(vector<int> &v, int k)
{
    // Write your code here.
    int n = v.size();
    vector<vector<long>> dp(n, vector<long>(k + 1, -1));
    return memo(v, k, n - 1, dp);
}
// TABULATION
long long tabu(vector<int> &v, int k)
{
    int n = v.size();
    vector<vector<long>> dp(n, vector<long>(k + 1, 0));

    if (v[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][0] = 1;
    }
    if (v[0] <= k && v[0] != 0)
    {
        dp[0][v[0]] = 1;
    }
    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= k; target++)
        {
            int pick = 0;
            if (target >= v[index])
            {
                pick = dp[index - 1][target - v[index]];
            }
            int notPick = dp[index - 1][target];
            dp[index][target] = (pick + notPick) % (int)(1e9 + 7);
        }
    }
    return dp[n - 1][k];
}

// Space optimisation
long long opti(vector<int> &v, int k)
{
    int n = v.size();
    vector<long> prev(k + 1, 0);
    vector<long> cur(k + 1, 0);
    if (v[0] == 0)
    {
        prev[0] = 2;
    }
    else
    {
        prev[0] = 1;
    }
    if (v[0] <= k && v[0] != 0)
    {
        prev[v[0]] = 1;
    }
    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= k; target++)
        {
            int pick = 0;
            if (target >= v[index])
            {
                pick = prev[target - v[index]];
            }
            int notPick = prev[target];
            cur[target] = (pick + notPick) % (int)(1e9 + 7);
        }
        prev = cur;
    }
    return prev[k];
}
