#include <bits/stdc++.h>
using namespace std;
/*
a safe node is a node whose all paths end at a terminal node
a terminal node is a node that has no outgoing edges
we need do detect if a node is part of a cycle, if it is, it is not safe
if a node is not part of a cycle, it is safe
*/

bool DFSER(vector<vector<int>> &adjL, vector<int> &vis, int node)
{
    vis[node] = 2;
    for (const auto &it : adjL[node])//& for optimization otherwise getting TLE
    {
        if (vis[it] == 0)
        {
            if (DFSER(adjL, vis, it) == true)
            {
                return true;
            }
        }
        else if (vis[it] == 2)
        {
            return true;
        }
    }
    vis[node]=1;
    return false;
}

vector<int> safeStatesDFS(vector<vector<int>> adjL)
{
    int n = adjL.size();
    vector<int> vis(n, 0);
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            DFSER(adjL,vis,i);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i]==1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
