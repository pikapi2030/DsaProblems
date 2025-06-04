#include <bits/stdc++.h>
using namespace std;

int F(vector<int> &v, int start, int end)
{
    int mini = 1e9;
    if (start == end)
    {
        return 0;
    }
    for (int partitionPoint = start; partitionPoint < end; partitionPoint++)
    {
        int steps = v[start - 1] * v[partitionPoint] * v[end] + F(v, start, partitionPoint) + F(v, partitionPoint + 1, end);
        mini = min(mini, steps);
    }
    return mini;
}
//! T.C O(N*N*N) S.C O(N*N)+O(N)
int Brute(vector<int> &arr, int N)
{
    return F(arr, 1, N - 1);
}

int memo(vector<int> &v, vector<vector<int>> &dp, int start, int end)
{
    int mini = 1e9;
    if (start == end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    for (int partitionPoint = start; partitionPoint < end; partitionPoint++)
    {
        int steps = v[start - 1] * v[partitionPoint] * v[end] + memo(v, dp, start, partitionPoint) + memo(v, dp, partitionPoint + 1, end);
        mini = min(mini, steps);
    }
    return dp[start][end] = mini;
}
// memoisation
int mem(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return memo(arr, dp, 1, N - 1);
}

// tabulation
int matrixMultiplication(vector<int> &v, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = 1e9;

            for (int k = i; k < j; k++)
            {

                int steps = v[i - 1] * v[k] * v[j] + dp[i][k] + dp[k + 1][j];
                mini = min(steps, mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}
