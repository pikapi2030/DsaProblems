#include <bits/stdc++.h>
using namespace std;
int MST(int V,vector<vector<int>>adj[])
{
    int sum=0;
    vector<int>vis(V,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});//wt,node
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int wt=it.first;
        int node=it.second;;
        if(vis[node]==1){continue; }
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node])
        {
            if(vis[it[0]]==0)
            {
                pq.push({it[1],it[0]});
            }

        }
        
    }
    return sum;

}