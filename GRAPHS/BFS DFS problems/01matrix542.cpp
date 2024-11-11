#include <bits/stdc++.h>
using namespace std;
/*similar to rotten oranges
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
//!diagonal movement not allowed
*/

/*aproach
we will solve it using BFS, we have to find nearest 0 for each cell, if a cell is 0
it's nearest 0 is itself so distance is 0
now we start bfs from 0 and go towards 1(if not visited)
 and calculate the time it took to reach one,
that is our distance, then we make that one a zero and find other ones

we do this with every zero
we use a visited array as well;
//! T.C O(n*m)+O(n*m)  S.C O(m*n)+O(m*n)+O(m*n)

*/

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{

    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<vector<int>> ans(m, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> qs; //{{row,col},dist}
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                vis[i][j] = 1;
                qs.push({{i, j}, 0});
            }
        }
    }

    while (!qs.empty())
    {
        int row = qs.front().first.first;
        int col = qs.front().first.second;
        int dist = qs.front().second;
        ans[row][col] = dist;
        qs.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && vis[nrow][ncol] != 1)
            {
                qs.push({{nrow, ncol}, dist + 1});
                vis[nrow][ncol] = 1;
            }
        }
    }
    return ans;
}