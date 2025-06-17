#include <bits/stdc++.h>
using namespace std;
/*
Given an n x n array of integers matrix, return the minimum sum of
any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the
next row that is either directly below or diagonally left/right. Specifically,
the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col),
or (row + 1, col + 1).
*/
//! variable starting and ending points
/*approach
we will start from bottom and use loop to call n function calls from the bottom and maximise
them
*/

int rec(vector<vector<int>> &v, int i, int j)
{
    int n = v.size();

    if (i < 0 || j < 0 || j >= n)
    {
        return 1e9;
    }
    if (i == 0)
    {
        return v[0][j];
    }
    int up = v[i][j] + rec(v, i - 1, j);
    int rightUp = v[i][j] + rec(v, i - 1, j + 1);
    int leftUp = v[i][j] + rec(v, i - 1, j - 1);
    return min({up, rightUp, leftUp});
}

int recur(vector<vector<int>> &v)
{
    int n = v.size(); // n*n matrix
    int ans = 1e9;
    for (int j = 0; j < n; j++)
    {
        ans = min(ans, rec(v, n - 1, j));
    }
    return ans;
}
// tabs
int tabs(vector<vector<int>> &v)
{
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = v[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int rightUp = 1e9;
            int leftUp = 1e9;

            int up = v[i][j] + dp[i - 1][j];
            if (j + 1 < n)
            {

                rightUp = v[i][j] + dp[i - 1][j + 1];
            }
            if (j - 1 >= 0)
            {

                leftUp = v[i][j] + dp[i - 1][j - 1];
            }
            dp[i][j] = min({up, rightUp, leftUp});
        }
    }
    int ans = 1e9;
    for (int j = 0; j < n; j++)
    {
        ans = min(dp[n - 1][j], ans);
    }
    return ans;
}
