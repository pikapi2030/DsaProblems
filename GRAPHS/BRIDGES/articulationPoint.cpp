#include <bits/stdc++.h>
using namespace std;

/*
Given an undirected connected graph with V vertices and adjacency list adj. You are required
to find all the vertices removing which (and edges through it) disconnects the graph into 2
or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops
present in the graph.
*/

void dfs(vector<int> adj[], vector<int> &vis, vector<int> &time, vector<int> &low, vector<int> &mark,
         int &timer, int node, int parent)
{
    vis[node] = 1;
    time[node] = timer;
    low[node] = timer;
    timer++;
    int child = 0;
    for (auto it : adj[node])
    {

        if (it == parent)
        {
            continue;
        }
        if (vis[it] == 0)
        {
            dfs(adj, vis, time, low, mark, timer, it, node);
            low[node] = min(time[it], low[node]);
            if (parent != -1 && low[it] >= time[node]) // articulation point,diff logic for starting point
            {
                mark[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(time[it], low[node]);
        }
    }
    if (parent == -1)
    {
        if (child > 1) // if starting node has more than 1 child
        {
            mark[node] = 1;
        }
    }
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> low(V, 1e9);
    vector<int> time(V);
    vector<int> ans;
    vector<int> mark(V, 0); // marks articulation points
    int timer=0;
    dfs(adj, vis, time, low, mark, timer, 0, -1);

    for (int i = 0; i < mark.size(); i++)
    {
        if (mark[i])
        {
            ans.push_back(i);
        }
    }

    return ans;
}
