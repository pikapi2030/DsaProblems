#include <bits/stdc++.h>
using namespace std;
/*
You are given an m x n matrix board containing letters 'X' and 'O',
capture regions that are surrounded:

    Connect: A cell is connected to adjacent cells horizontally or vertically.
    Region: To form a region connect every 'O' cell.
    Surround: The region is surrounded with 'X' cells if you can connect the region with
     'X' cells and none of the region cells are on the edge of the board.

A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.
*/

/*aproach
we use DFS, we initialize our ans with all X, then we find boundary O on board and perfrom
a dfs traversal from them, we convert traversed X to O in our ans and return the ans

T.C O(4*n*m)+O(n)+O(n)
S.C O(n*m)
*/
void DFSER(vector<vector<char>> &ans, vector<vector<char>> &board, int drow[], int dcol[], int row, int col)
{
    
    int m = ans.size();
    int n = ans[0].size();
    ans[row][col] = 'O';
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && ans[nrow][ncol] == 'X' && board[nrow][ncol] == 'O')
        {
            DFSER(ans, board, drow, dcol, nrow, ncol);
        }
    }
}

vector<vector<char>> solve(vector<vector<char>> &board)
{

    int m = board.size();
    int n = board[0].size();
    vector<vector<char>> ans(m, vector<char>(n, 'X'));
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, -1, 0, 1};
    // checking for boundary 'O'
    for (int j = 0; j < n; j++) // boundary rows
    {
        if (board[0][j] == 'O') // first row
        {
            DFSER(ans, board, drow, dcol, 0, j);
        }
        if (board[m - 1][j] == 'O') // last row
        {
            DFSER(ans, board, drow, dcol, m - 1, j);
        }
    }

    for (int i = 0; i < m; i++) // boundary rows
    {
        if (board[i][0] == 'O') // first column
        {
            DFSER(ans, board, drow, dcol, i, 0);
        }
        if (board[i][n - 1] == 'O') // last column
        {
            DFSER(ans, board, drow, dcol, i, n - 1);
        }
    }
    return ans;
}
