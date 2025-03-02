#include <bits/stdc++.h>
using namespace std;

int findMaxFish(vector<vector<int>>& grid) 
{
   
  int m=grid.size();
  int n=grid[0].size();
  int drow[]={-1,1,0,0};
  int dcol[]={0,0,1,-1};
vector<vector<int>>vis(n,vector<int>(m,0));

  queue<pair<int,int>>qs;//{row,col}
  while(!qs.empty())
  {
    int row=qs.front().first;
    int col=qs.front().second;
    qs.pop();
    for(int i=0;i<4;i++)
    {
        int nrow=drow[i]+row;
        int ncol=dcol[i]+col;
        if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&vis[nrow][ncol]==0&&grid[nrow][ncol]!=0)
        {
         qs.push({nrow,ncol});

        }
    }
   
  }        
}

