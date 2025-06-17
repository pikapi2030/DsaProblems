#include <bits/stdc++.h>
using namespace std;
/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner
(i.e., grid[m - 1][n - 1]). The robot can only move either down or
right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the
robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.
Example 1:
Input: m = 3, n = 7
Output: 28
Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to
reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/

int rec(int i, int j, int m, int n) // i,j indicate current pos
{
    if (i == 0 && j == 0)
    {
        return 1; // count this path as we have reached destination
    }
    if (i < 0 || j < 0)
    {
        return 0; // out of bounds, this path cannot be considered
    }
    int up = rec(i - 1, j, m, n); // since we are reverse traversing,up and left instead of down and right
    int left = rec(i, j - 1, m, n);
    return up + left;
}
int recur(int m, int n)
{
    return (m-1,n-1);
}
// tabs
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
            {
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}
