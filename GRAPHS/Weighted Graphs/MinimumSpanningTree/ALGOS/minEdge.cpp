#include <bits/stdc++.h>
using namespace std;
// write a function which returns min edge and min weight to get from point A to point B

pair<int,int> minsRoad(int V,vector<vector<int>>adj[],int A,int P)
{
    vector<int>dist(V,INT_MAX);
    vector<int>road(V,INT_MAX);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;\
dist[A]=0;
road[A]=0;
pq.push({dist[A],A});//
while(!pq.empty())
{
    auto it=pq.top();
    pq.pop();
    int node=it.second;
    int wt=it.first;

    for(auto ij :adj[node])
    {
        int neig=ij[1];
        int wet=ij[0];
        if(dist[neig]>1+dist[node])
        {
            dist[neig]=wet+dist[node];
            road[neig]=1+road[node];
            pq.push({dist[neig],neig});
        }
    }
}
pair<int,int>ans;
ans.first=dist[p];
ans.second=road[p];
return ans;


}

int main()
{
    int V=6;
    vector<vector<int>>adj[V];
    vector<vector<int>> edges={{0,1,2},{0,2,1},{1,2,1},{2,3,2}  };
    for(auto it:edges)
    {
        vector<int>tmp(2);
        tmp[0]=it[1];
        tmp[1]=it[2];
        
    }
}

