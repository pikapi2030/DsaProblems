#include <bits/stdc++.h>
using namespace std;
/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid)
consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed
by connecting adjacent lands horizontally or vertically or diagonally i.e.,
!in all 8 directions.
*/

void DFSER(vector<vector<char>> &grid, vector<vector<int>> &vis, const int drow[], const int dcol[], int row, int col)
{
    vis[row][col] = 1;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < 8; i++) // 8 possible directions
    {
        int nbrow = row + drow[i];
        int nbcol = col + dcol[i];
        if (grid[nbrow][nbcol] == 1 && vis[nbrow][nbcol] == 0 && nbrow > 0 && nbcol > 0 && nbrow < m && nbcol < n)
        {
            DFSER(grid, vis, drow, dcol, nbrow, nbcol);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int drow[] = {-1,1,0,0};
    int dcol[] = {};
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int islandcount = 0; // ans
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                DFSER(grid, vis, drow, dcol, i, j);
            }
        }
    }
}
