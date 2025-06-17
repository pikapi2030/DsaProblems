#include <bits/stdc++.h>
using namespace std;
/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally,
if you are on index i on the current row, you may move to either index i or index i + 1
on the next row.
Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
2
3 4
6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:
Input: triangle = [[-10]]
Output: -10
*/
/*approach
since we have a fixed starting point and variable ending point, we start our recursion call
from the start
*/

int rec(vector<vector<int>> &t, int i, int j)
{
    int m = t.size();
    if (i == m - 1) // last row, destination
    {
        return t[i][j]; // cost of going from dest to dest is t[i][j]
    }
    /*since we can only move down or downDiagnal,
    we will never we out of bounds before reaching last row
    */
    int down = t[i][j] + rec(t, i + 1, j);
    int diagDown = t[i][j] + rec(t, i + 1, j + 1);
    return min(down, diagDown);
}

int bruteRec(vector<vector<int>> &triangle)
{
    return rec(triangle, 0, 0);
}
int minimumTotal(vector<vector<int>> &t)
{
    int m = t.size();
    vector<vector<int>> dp(m, vector<int>(m, 1e9));
    for (int j = 0; j < m; j++)
    {
        dp[m - 1][j] = t[m - 1][j]; // base case
    }
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)//traversal direction does not matter, as dp[i][j] is not dependent dp[i][j+1] or dp[i][j-1]
        {
            int down = t[i][j] + dp[i + 1][j];
            int diagDown = t[i][j] + dp[i + 1][j + 1];
            dp[i][j]= min(down, diagDown);
        }
    }
    return dp[0][0];
}
