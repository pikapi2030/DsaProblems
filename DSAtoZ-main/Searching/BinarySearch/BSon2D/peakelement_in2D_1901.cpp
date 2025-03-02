#include <bits/stdc++.h>
using namespace std;
/*

A peak element in a 2D grid is an element that is strictly greater than all of
its adjacent neighbors to the top, bottom, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal,
find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with
the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

NOTE:there can be multiple peak elements, returning coordinates of any one of them
is cosidered bottom ans

*/

/*BRUTE
using two nested for loop, check for top,bottom,top and bottom
T.C O(4*m*n)
*/

/*BETTER
simply calculate the max element in matrix
T.C O(m*n)
*/

/*OPTIMAL
NOTE: IN VID SOL, STRIVER HAS DONE IT CONSIDERING MID AS A COLUMN, I AM DOING MID AS A ROW
AS A 2D MATRIX IS ACTUALLY A VECTOR OF VECTOR, EACH VECTOR IS ARRANGED AS ROWS

using BS and logic of peak element in 1d we can solve this

we start low as 0th row, high as last row

mid also indicates a row
now we calculate the max value in midth row, this value can be a peak element
we check for top and bottom
(NO NEED TO CHECK FOR top AND bottom SINCE IT IS ALREADY A MAX ELEMENT IN THAT row)
if bigger than top and bottom peak element found

if top element is bigger then we eliminate the bottom search space(of rows)
if bottom elmenet bigger than we eliminate the top search space of rows

T.C O((log_2 n) *m) for every row BS we scan column for max element
S.C O(1)

*/

int ColumnOfMaxElmenet_inARow(vector<int> &v)
{
    long long max = -1;
    int column_coordinate = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max=v[i];
            column_coordinate = i;
        }
    }

    return column_coordinate;

}

vector<int> OPTIMAL(vector<vector<int>> &v)
{
    long long low = 0, high = v.size() - 1;

    while (high >= low)
    {
        long long mid = (low + high) / 2;
        int column_coordinate = ColumnOfMaxElmenet_inARow(v[mid]);
        long long top = -1, bottom = -1; // representing top and bottom of a possible peak element,-1 to handle edge cases
        if (mid - 1 >= 0)
        {
            top = v[mid-1][column_coordinate];
        }
        if (mid + 1 < v.size())
        {
            bottom = v[mid+1][column_coordinate];
        }

        if (v[mid][column_coordinate] > top && v[mid][column_coordinate]>bottom)
        {
            return {(int)mid, column_coordinate};
        }
        else if (v[mid][column_coordinate] < top) // top is big,eliminate bottom
        {
            high = mid - 1;
        }
        else // bottom>v[rowcoordinate][mid] bottom is big eliminate top
        {
            low = mid + 1;
        }
    }

    return {-1, -1};
}
