#include <bits/stdc++.h>
using namespace std;

/*
You are given an m x n integer array grid. There is a robot initially located at the top-left 
corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner 
(i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes 
cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right
corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.
*/

// tabs
int uniquePathsWithObstacles(vector<vector<int>> &v)
{
    int m = v.size();
    int n = v[0].size();
    if (v[m - 1][n - 1] == 1)
    {
        return 0;
    }
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0 && v[i - 1][j] == 0)
            {
                up = dp[i - 1][j];
            }
            if (j > 0 && v[i][j - 1] == 0)
            {
                left = dp[i][j - 1];
            }
            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}