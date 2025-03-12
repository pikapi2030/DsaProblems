#include <bits/stdc++.h>
using namespace std;
/*
Given an array arr[] of size n, where arr[i] denotes the height of ith stone.
Geek starts from stone 0 and from stone i, he can jump to stones i + 1, i + 2, … i + k.
The cost for jumping from stone i to stone j is abs(arr[i] – arr[j]).
Find the minimum cost for Geek to reach the last stone.
*/

int bruteR(int k, int cur, vector<int> &v)
{

    if (cur == v.size() - 1)
    {
        return 0;
    }
    int minCost = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (cur + i < v.size())
        {
            int ijump = abs(v[cur] - v[cur + i]) + bruteR(k, cur + i, v);
            minCost = min(minCost, ijump);
        }
    }
    return minCost;
}
/*memoisation
T.C O(N*K)
S.C O(N)+O(N)
*/

int memo(int k, int cur, vector<int> &v, vector<int> &dp)
{

    if (cur == v.size() - 1)
    {
        return 0;
    }
    if (dp[cur] != -1)
    {
        return dp[cur];
    }
    int minCost = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (cur + i < v.size())
        {

            int ijump = abs(v[cur] - v[cur + i]) + memo(k, cur + i, v, dp);
            minCost = min(minCost, ijump);
        }
    }
    return dp[cur] = minCost;
}

/*tabulation
T.C O(N*K)
S.C O(N)
*/

int opti(int k, vector<int> &v)
{
    int n = v.size();

    vector<int> dp(n, -1);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int minCost = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i + j < n)
            {
                int jJump = abs(v[i] - v[i + j]) + dp[i + j];
                minCost = min(minCost, jJump);
            }
        }
        dp[i] = minCost;
    }

    return dp[0];
}
/*optimal
T.C O(N*K)
S.C O(K) use an array of k size and keep record of k elemnts instead on n elements
code not written
*/

