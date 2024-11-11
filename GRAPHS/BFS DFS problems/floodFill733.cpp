#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFillBFS(vector<vector<int>> v, int startRow, int startColumn, int startColor)
{
    int m = v.size();
    int n = v[0].size();
    int initialColor = v[startRow][startColumn];
    if (initialColor == startColor)
        return v; // No need to proceed if the start color is already the initial color

    queue<pair<int, int>> qs; // {row, column}
    qs.push({startRow, startColumn});
    v[startRow][startColumn] = startColor;

    // Direction vectors for up, right, down, left movements
    int dRow[] = {-1, 0, 1, 0};
    int dColumn[] = {0, 1, 0, -1};

    while (!qs.empty())
    {
        int row = qs.front().first;
        int column = qs.front().second;
        qs.pop();

        // Check all four possible directions
        for (int i = 0; i < 4; i++)
        {
            int neighborRow = row + dRow[i];
            int neighborColumn = column + dColumn[i];

            // If the neighbor is within bounds, has the initial color, and hasn't been visited
            if (neighborRow >= 0 && neighborRow < m && neighborColumn >= 0 && neighborColumn < n && v[neighborRow][neighborColumn] == initialColor)
            {
                qs.push({neighborRow, neighborColumn});
                v[neighborRow][neighborColumn] = startColor; // Change color upon pushing to avoid revisiting
            }
        }
    }

    return v;
}
//! T.C: O(M*N)

void modfifiedDFS(vector<vector<int>> &ans,int startRow,int startColumn,int startColor,
int initialColor,int dRow[],int dCol[])
{
int m=ans.size();
int n=ans[0].size();    
ans[startRow][startColumn]=startColor;

for(int i=0;i<4;i++)
{
    int nRow=startRow+dRow[i];
    int nColumn=startColumn+dCol[i];
    if(nRow>=0 && nColumn>=0 && nRow<m && nColumn<n && ans[nRow][nColumn]==initialColor 
    &&ans[nRow][nColumn]!=startColor )
    {
        modfifiedDFS(ans,nRow,nColumn,startColor,initialColor,dRow,dCol);
    }
}
}

vector<vector<int>> floodFillDFS(int startRow,int startCol,int startColor,
vector<vector<int>>&image)
{
    int initialColor= image[startRow][startCol];
    vector<vector<int>>ans=image;
    int dRow[]={-1,0,1,0};
    int dCol[]={0,1,0,-1};
    modfifiedDFS(ans,startRow,startCol,startColor,initialColor,dRow,dCol);
    return ans;
}
//! T.C O(N*M) 

