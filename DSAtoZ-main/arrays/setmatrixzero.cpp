#include <bits/stdc++.h>
using namespace std;
/*
a 2d matrix of order n*m is given containing onl 1 and 0
if arr[i][j]==0 then set ith row and jth column to have all zeroes
new updated zeroes should not be considered
Input:
 matrix=[[1,1,1],[1,0,1],[1,1,1]]

Output:
 [[1,0,1],[0,0,0],[1,0,1]]
*/

/*
brute solution(first marking row and column  of 0 by using extra space, then performing action)
we make a row array and a column array initialised with 0, we traverse through matrix
if a[i][j]==0 we mark row[i]=1,column[j]=1
after finish the iteration we do another traversal, if(row[i]==1||column[j]==1)
then a[i][j]==0
T.C O(2*n*m)
S.C O(n)+O(m)
*/
vector<vector<int>> brutesetzero(vector<vector<int>> &v)
{
    int n = v.size();    // row
    int m = v[0].size(); // column
    vector<int> row(n);
    vector<int> clmn(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                row[i] = 1;
                clmn[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || clmn[j] == 1)
            {
                v[i][j] = 0;
            }
        }
    }
    return v;
}

/*
optimal solution
it takes same T.C as better solution but S.C is reduced
int better we were maintaing two arrays for marking of one which would become
zero
matrix of n*m
in opti we do not make any extra array and consider v[0][something] as the array to
mark ones in rows and v[something][0] an another array to mark ones in column
but there is a problem v[0][0] is common for both arrays so we maintain a col0
variable to mark ones of column 0 specialy
now since we are using the matrix itself, first we will iterate (the last iteration to check
if if the one has to be made zero or not)
through i=1 to n and j=1 to m to avoid changing the arrays then we will
iterate thorugh row array than column array

*/

vector<vector<int>> optisetzero(vector<vector<int>> v)
{

    int n = v.size();
    int m = v[0].size();
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                v[i][0] = 0;
                if (j != 0)
                {
                    v[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }
    for (int i = 1; i < n; i++) // trying not to change our assumed arrays
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] != 0)
            {
                if (v[0][j] == 0 || v[i][0] == 0)
                {
                    v[i][j] = 0;
                }
            }
        }
    }
    if (v[0][0] == 0) // for row number 0
    {
        for (int j = 0; j < m; j++)
        {
            v[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            v[i][0] = 0;

        }
    }
}