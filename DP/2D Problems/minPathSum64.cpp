#include <bits/stdc++.h>
using namespace std;
/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/
// tabs
int minPathSum(vector<vector<int>> &v)
{
    int m = v.size();
    int n = v[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0)); // initialisation of 0 has no significance
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = v[0][0];
                continue;
            }
            int up = 1e9;
            int left = 1e9;
            if (i > 0)
            {
                up = v[i][j] + dp[i - 1][j];
            }
            if (j > 0)
            {
                left = v[i][j] + dp[i][j - 1];
            }
            dp[i][j] = min(up, left);
        }
    }
    return dp[m - 1][n - 1];
}