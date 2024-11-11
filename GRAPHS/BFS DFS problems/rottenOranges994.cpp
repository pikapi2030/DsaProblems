#include <bits/stdc++.h>
using namespace std;
/*
You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a
rotten orange becomes rotten.

Return the minimum number of minutes that must elapse
until no cell has a fresh orange. If this is impossible, return -1.
*/

/*Approach
we will use BFS travesal(using queue), will maintain a vis matrix
in queue we will be storing row,column and time of an rotten orange
we will return the max time recorded in our queue but before that
we will check if all fresh oranges are rotten in our vis array
//! T.C O(n*m)+O(n*m)  S.C O(m*n)+O(m*n)+O(m*n)
*/

int modifiedBFS(vector<vector<int>> oranges)
{
    queue<pair<pair<int, int>, int>> q; //{{row,column},time}
    int m = oranges.size();
    int n = oranges[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int AnsTime = 0;
    for (int i = 0; i < m; i++)//finding rotten oranges
    {
        for (int j = 0; j < n; j++)
        {
            if (oranges[i][j] == 2)
            {
                vis[i][j] = 2;
                q.push({{i, j}, 0});
            }
        }
    }
    int drow[] = {1, 0, -1, 0};    //! these both arrays will be used to call
    int dcolumn[] = {0, -1, 0, 1}; //! left right up down using loops
    while (!q.empty())
    {
        int row = q.front().first.first;
        int column = q.front().first.second;
        int t = q.front().second;
        AnsTime = max(AnsTime, t);
        q.pop();
        for (int i = 0; i < 4; i++) // loop to call up down left right
        {
            int neighourRow = row + drow[i];
            int neighbourColumn = column + dcolumn[i];
            if (neighbourColumn >= 0 && neighbourColumn < n && neighourRow >= 0 && neighourRow < m && vis[neighourRow][neighbourColumn] == 0 && oranges[neighourRow][neighbourColumn] == 1)
            {
                vis[neighourRow][neighbourColumn] = 2;

                q.push({{neighourRow, neighbourColumn}, t + 1});
            }
        }
    }
    // checking if all fresh oranges rotted or not
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (oranges[i][j] == 1 && vis[i][j] == 0)
            {
                return -1;
            }
        }
    }
    return AnsTime;
}
