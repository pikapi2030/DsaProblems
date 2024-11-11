#include <bits/stdc++.h>
using namespace std;


/*
!T.C O(N)+O(2e)
!S.C O(N+N+N+N)  
*/
void DFSER(vector<vector<int>>&adj,int node,vector<int>&ans,vector<int>&vis)
{
    vis[node]=1;
    ans.push_back(node);
    for(auto it:adj[node])
    {
     if(!vis[it])
     {
        DFSER(adj,it,ans,vis);
     }
    }

}

vector<int>DFS(vector<vector<int>>adj,int start)
{
vector<int>visited(adj.size(),0);    
vector<int>ans;
DFSER(adj,start,ans,visited);
return ans;
}



