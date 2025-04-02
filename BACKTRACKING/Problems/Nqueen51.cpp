#include <bits/stdc++.h>
using namespace std;
/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that
no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/
// 0 means no queen, 1 means queen
//!T.C  O(N!) , for N=20, will take 7500 years 
//! TODO:more optimal solution using branch and bound, dp are possible
/*
!!We do not need to check all 8 directions,

right direction,top-right diagonal,bottom-right diagoanl :-
since we are filling from left to right, no need to check this direction as
no queen will be present anyway

top and bottom:- we are placing queens by fixing the column and iterating rows,
as we find a queen can we placed, we move to next column so there is a gurantee
that only 1 queen will be place per column

!!directions to check:-
left,top-left diagonal,top-bottom diagonal

*/


void MatrixesPrinter(vector<vector<vector<int>>>v)
{
    
    for(auto it:v)
    {
        int n=it.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<" "<<it[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"********************************************************"<<endl;
        
    }
}

bool isSafe(int row, int col, vector<vector<int>> &Board, int k)
{
    // cheking for left
    int dupCol = col;
    int dupRow = row;
    while (dupCol >= 0)
    {
        if (Board[row][dupCol] == 1)
        {
            return false;
        }
        dupCol--;
    }

    // cheking for bottom-left diagonal
    dupCol = col;

    while (dupRow < k && dupCol >= 0)
    {
        if (Board[dupRow][dupCol] == 1)
        {
            return false;
        }
        dupCol--;
        dupRow++;
    }
    dupRow = row;
    dupCol = col;
    // cheking for top-left diagonal
    while (dupRow >= 0 && dupCol >= 0)
    {
        if (Board[dupRow][dupCol] == 1)
        {
            return false;
        }
        dupRow--;
        dupCol--;
    }

    return true;
}

void solver(vector<vector<int>> &Board, int col, vector<vector<vector<int>>> &ans, int k)

{
    if (col == k)
    {
        ans.push_back(Board);
        return;
    }
    // check every row for the particular column
    for (int row = 0; row < k; row++)
    {
        if (isSafe(row, col, Board, k))
        {
            Board[row][col] = 1;
            solver(Board, col + 1, ans, k);
            Board[row][col] = 0;//!BACKTRACK
            /*backtrack, since we want every possible solution,
            we have to backtrack indepedant of the isSolve function
            basically, even we found a soution, we have to find more so we backtrack
            always
            */
        }
    }
}

vector<vector<vector<int>>> Nqueen(int k)
{
    vector<vector<vector<int>>> ans; // contains matrixes of solutions
    vector<vector<int>> Board(k, vector<int>(k, 0));

    solver(Board, 0, ans, k);
    return ans;
}

int main()
{
    vector<vector<vector<int>>>ans=Nqueen(6);
    cout<<ans.size();
}
