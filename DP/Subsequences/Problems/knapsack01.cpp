#include <bits/stdc++.h>
using namespace std;
/*
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are
N items and the ith item weighs wi and is of value vi. Considering the constraints of the
maximum weight that a knapsack can carry, you have to find and return the maximum value
that a thief can generate by stealing items.
*/
// brute : basic pick not pick recursion

int recur(vector<int> &w, vector<int> &v, int cap, int index) //{value,weight}
{
    if (cap == 0)
    {
        return 0;
    }
    if (index == 0)
    {
        if (cap >= w[0])
        {
            return v[0];
        }
        else
        {
            return 0;
        }
    }
    int pick = 0;
    if (cap >= w[index])
    {
        pick = v[index] + recur(w, v, cap - w[index], index - 1);
    }
    int notPick = recur(w, v, cap, index - 1);
    return max(pick, notPick);
}

int brute(vector<int> weight, vector<int> value, int cap)
{
    return recur(weight, value, cap, value.size() - 1);
}

// meoisation
int memo(vector<int> &w, vector<int> &v, int cap, int index, vector<vector<int>> &dp) //{value,weight}
{
    if (dp[index][cap] != -1)
    {
        return dp[index][cap];
    }
    if (cap == 0)
    {
        return 0;
    }
    if (index == 0)
    {
        if (cap >= w[0])
        {
            return v[0];
        }
        else
        {
            return 0;
        }
    }
    int pick = 0;
    if (cap >= w[index])
    {
        pick = v[index] + memo(w, v, cap - w[index], index - 1, dp);
    }
    int notPick = memo(w, v, cap, index - 1, dp);
    return dp[index][cap] = max(pick, notPick);
}

int meoisation(vector<int> weight, vector<int> value, int cap)
{
    int n = value.size();
    vector<vector<int>> dp(n, vector<int>(cap + 1, -1));
    return memo(weight, value, cap, value.size() - 1, dp);
}
// tabulation
int tab(vector<int> w, vector<int> v, int cap)
{
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(cap + 1, 0));
    for (int capacity = 0; capacity <= cap; capacity++)
    {
        if (capacity >= w[0])
        {
            dp[0][capacity] = v[0];
        }
    }
    for (int index = 0; index < n; index++)
    {
        dp[index][0] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int capacity = 1; capacity <= cap; capacity++)
        {
            int pick = 0;
            if (capacity >= w[index])
            {
                pick = v[index] + dp[index - 1][capacity - w[index]];
            }
            int notPick = dp[index - 1][capacity];
            dp[index][capacity] = max(pick, notPick);
        }
    }
    return dp[n - 1][cap];
}
// space optimisation(use 2 arrays)(stil not best, we can use 1 array as well)
int opti(vector<int> w, vector<int> v, int cap)
{
    int n = v.size();
    vector<int>cur(cap+1,0);
    vector<int> pre(cap + 1, 0);
    pre[0] = 0;
    for (int capacity = 0; capacity <= cap; capacity++)
    {
        if (capacity >= w[0])
        {
            pre[capacity] = v[0];
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int capacity = 1; capacity <= cap; capacity++)
        {
            int pick = 0;
            if (capacity >= w[index])
            {
                pick = v[index] + pre[capacity - w[index]];
            }
            int notPick = pre[capacity];
            cur[capacity] = max(pick, notPick);
        }
        pre = cur;
    }
    return pre[cap];
}
// optimal (using only 1 array)
/*how it works?
we know that values of cur array are only dependant of values of prev array,
so it does not matter if we fill our curr array in forward or reverse manner,
it will always get filled correctly since prev array is already present

we can use prev array as curr array at same time if we fill it in reverse order,


*/

int better(vector<int> w, vector<int> v, int cap)
{
    int n = v.size();
    vector<int> pre(cap + 1, 0);
    pre[0] = 0;
    for (int capacity = 0; capacity <= cap; capacity++)
    {
        if (capacity >= w[0])
        {
            pre[capacity] = v[0];
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int capacity = cap; capacity >= 0; capacity--)
        {
            int pick = 0;
            if (capacity >= w[index])
            {
                pick = v[index] + pre[capacity - w[index]];
            }
            int notPick = pre[capacity];
            pre[capacity] = max(pick, notPick);
        }
        
    }
    return pre[cap];
}
