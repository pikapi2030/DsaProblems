#include <bits/stdc++.h>
using namespace std;
/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1
represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally)
land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of
the grid in any number of moves.
*/

/*
we do a DFS traversal of lands connected with a boundary with a vis array
after travesal we count unvisited lands and return them

*/

void DFSER(vector<vector<int>> &grid, vector<vector<int>> &vis, int drow[], int dcol[],
           int row, int col )
{

    vis[row][col] = 1;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nbrow = row + drow[i];
        int nbcol = col + dcol[i];
        if (nbrow >= 0 && nbcol >= 0 && nbrow < m && nbcol < n && vis[nbrow][nbcol] != 1 && grid[nbrow][nbcol] == 1)
        {
            DFSER(grid, vis, drow, dcol, nbrow, nbcol);
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int drow[] = {-1, 1, 0, 0};
    int dcol[] = {0, 0, 1, -1};
    vector<vector<int>> vis(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                if ((i == 0 || i == m - 1||j==0||j==n-1) && vis[i][j] == 0)//boundary 
                {
                    DFSER(grid, vis, drow, dcol, i, j);
                }
            }
        }
    }
    //counting total unvisited lands
    int unvisitedLand=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1/*land present*/&&vis[i][j]==0)
            {
                unvisitedLand++;
            }
        }
    }
    return unvisitedLand;
}
