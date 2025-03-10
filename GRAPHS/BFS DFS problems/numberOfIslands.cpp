#include <bits/stdc++.h>
using namespace std;
/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or
vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
["1","1","1","1","0"],
["1","1","0","1","0"],
["1","1","0","0","0"],
["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
["1","1","0","0","0"],
["1","1","0","0","0"],
["0","0","1","0","0"],
["0","0","0","1","1"]
]
Output: 3

 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

void DFSER(vector<vector<char>> &grid, vector<vector<int>> &vis, const int drow[], const int dcol[], int row, int col)
{
    vis[row][col] = 1;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < 4; i++) // 4 possible directions
    {
        int nbrow = row + drow[i];
        int nbcol = col + dcol[i];
        if ( nbrow >= 0 && nbcol >= 0 && nbrow < m && nbcol < n&& grid[nbrow][nbcol] == '1' && vis[nbrow][nbcol] == 0 )
        {
            DFSER(grid, vis, drow, dcol, nbrow, nbcol);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int drow[] = {1,0,-1,0};
    int dcol[] = {0,1,0,-1};
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int islandcount = 0; // ans
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1' && vis[i][j] == 0)
            {
                islandcount++;
                DFSER(grid, vis, drow, dcol, i, j);
            }
        }
    }
    return islandcount;
}
