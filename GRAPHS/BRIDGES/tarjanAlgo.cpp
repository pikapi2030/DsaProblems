#include <bits/stdc++.h>
using namespace std;
/*
this algo is used to return bridges in a graph
a bridge is such an edge, if removed will split the graph in components
bridge can be returned in vector of pairs, i,j being the nodes of at end of the bridge
{{i1,j1},{i2,j2}}
*/

class Solution
{
public:
    void dfs(vector<int> adj[], vector<int> &vis, vector<int> &time, vector<int> &low, vector<int> &mark,
             int &timer, int node, int parent)
    {
        vis[node] = 1;
        time[node] = low[node] = timer++;
        int child = 0;

        for (auto it : adj[node])
        {
            if (it == parent)
                continue;

            if (!vis[it])
            {
                dfs(adj, vis, time, low, mark, timer, it, node);
                low[node] = min(low[node], low[it]);

                if (parent != -1 && low[it] >= time[node])
                    mark[node] = 1;

                child++;
            }
            else
            {
                low[node] = min(low[node], time[it]);
            }
        }

        if (parent == -1 && child > 1)
            mark[node] = 1;
    }

    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0), low(V), time(V), mark(V, 0);
        int timer = 0;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(adj, vis, time, low, mark, timer, i, -1);
        }

        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (mark[i])
                ans.push_back(i);
        }

        if (ans.empty())
            return {-1};
        return ans;
    }
};
