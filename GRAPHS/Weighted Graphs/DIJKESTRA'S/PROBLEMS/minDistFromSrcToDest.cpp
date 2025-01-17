#include <bits/stdc++.h>
using namespace std;
/*
Given a n * m matrix grid where each element can either be 0 or 1. 
You need to find the shortest distance between a given source cell to a destination cell. 
The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. 
Two cells are adjacent if they share a side. 
In other words, you can move in one of the four directions, Up, Down, Left and Right. 
The source and destination cell are based on the zero based indexing.
The destination cell should be 1.
*/

/*Aproach
we will apply dijk, 
but since moving to other cell only costs 1 unit(uniform weight) we do not need a 
priority queue, it can be done using queue(as there is no need of sorting,
all pairs will form in sorted order(same dist))

since all cost of movement is uniform, any cell visited first will be visited from the 
shortest distance
*/

int Sol(vector<vector<int>>&grid,pair<int,int>&src,pair<int,int>&dest/*destination*/)
{
    if(src==dest){ return 0; }
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));//vis grid
    vector<int>drow={1,0,-1,0};
    vector<int>dcol={0,1,0,-1};
    queue<pair<int,pair<int,int>>>qs;// {dist,{row,col}}
    qs.push({0,{src}});
    while(!qs.empty())
    {
        int dist=qs.front().first;
        int row=qs.front().second.first;
        int col=qs.front().second.second;
        qs.pop();
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0&&grid[nrow][ncol]==1)
            {
                if(nrow==dest.first&&ncol==dest.second)
                {
                    return dist+1;
                }
                qs.push({dist+1,{nrow,ncol}});
                vis[nrow][ncol]=1;
            }
        }

    }
    return -1;


}


