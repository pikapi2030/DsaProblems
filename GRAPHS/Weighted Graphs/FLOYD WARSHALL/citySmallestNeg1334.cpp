#include <bits/stdc++.h>
using namespace std;

/*
There are n cities numbered from 0 to n-1. Given the array edges where 
edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities 
fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and 
whose distance is at most distanceThreshold, If there are multiple such cities, return the 
city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' 
weights along that path.
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dT) 
    {
        
         //build adj matrix
         vector<vector<int>>adjM(n,vector<int>(n,1e5));
         for(int i=0;i<n;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    adjM[i][j]=0;
                }
            }
         }
         for(auto it:edges)
         {
            int from=it[0];
            int to=it[1];
            int wt=it[2];
            adjM[from][to]=wt;
            adjM[to][from]=wt;

         }
         for(int k=0;k<n;k++)
         {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    adjM[i][j]=min(adjM[i][j],adjM[i][k]+adjM[k][j]);
                }
            }
         }
         int ans=-1;
         int minNeg=1e5;
         for(int i=0;i<n;i++)
         {
            int cntNeg=0;

            for(int j=0;j<n;j++)
            {
                if(i==j){continue;}
                if( adjM[i][j]<=dT )
                {
                cntNeg++;
                }
                
            }
            if( minNeg>cntNeg )
            {
                minNeg=cntNeg;
                ans=i;
            }
            else if(minNeg==cntNeg)
            {
                ans=max(ans,i);
            }
         }
         
return ans;
        
    }
};