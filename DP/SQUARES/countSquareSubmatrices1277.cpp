#include <bits/stdc++.h>
using namespace std;
/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
Example 1:
Input: matrix =
[
[0,1,1,1],
[1,1,1,1],
[0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:
Input: matrix =
[
[1,0,1],
[1,1,0],
[1,1,0]
]
Output: 7
Explanation:
There are 6 squares of side 1.
There is 1 square of side 2.
Total number of squares = 6 + 1 = 7.
*/
int countSquares(vector<vector<int>> &v)
{
    int m = v.size();
    int ans = 0;
    int n = v[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = v[i][0];
        ans += dp[i][0];
    }
    for (int j = 1; j < n; j++)
    {
        dp[0][j] = v[0][j];
        ans += dp[0][j];
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (v[i][j] == 1)
            {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
            }
            ans += dp[i][j];
        }
    }
    return ans;
}